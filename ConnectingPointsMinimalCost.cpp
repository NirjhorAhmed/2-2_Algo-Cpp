#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

struct Point
{
    int x;
    int y;
};

struct Edge
{
    int u;
    int v;
    ll cost;
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
    return a.cost < b.cost;
}

int main()
{
    int N;
    cin >> N;

    vector<Point> points(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    vector<Edge> edges;

    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            ll dist = abs(points[i].x - points[j].x) + abs(points[i].y - points[j].y);

            edges.push_back({i, j, dist});
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    parent.resize(N + 1);

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    ll ans = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        if (Union(edges[i].u, edges[i].v))
        {
            ans += edges[i].cost;
        }
    }

    cout << ans;

    return 0;
}