#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Edge
{
    int u;
    int v;
    ll w;
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

vector<int> parent;

int Find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = Find(parent[x]);
}

bool Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b)
        return false;

    parent[b] = a;
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

    for (int i = 0; i < m; i++)
    {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), cmp);

    parent.resize(n + 1);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    ll ans = 0;
    int cnt = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        if (Union(edges[i].u, edges[i].v))
        {
            ans += edges[i].w;
            cnt++;
        }
    }

    if (cnt != n - 1)
        cout << "IMPOSSIBLE";
    else
        cout << ans;

    return 0;
}