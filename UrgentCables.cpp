#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Edge
{
    int u;
    int v;
    ll cost;
    ll priority;
};

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

bool cmp(Edge a, Edge b)
{
    return a.priority < b.priority;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        Edge e;
        e.u = a;
        e.v = b;
        e.cost = c;
        e.priority = c * (a + b);

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
            ans += edges[i].cost;
            cnt++;
        }
    }

    if (cnt != n - 1)
        cout << "IMPOSSIBLE";
    else
        cout << ans;

    return 0;
}