#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

struct Edge
{
    int from;
    int to;
    ll cost;
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        edges.push_back({a, b, c});
    }

    for (int i = 0; i < k; i++)
    {
        int tower;
        cin >> tower;
        edges.push_back({0, tower, 0});
    }

    vector<ll> dist(n + 1, INF);

    dist[0] = 0;

    for (int i = 0; i <= n; i++)
    {
        bool changed = false;

        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j].from;
            int v = edges[j].to;
            ll w = edges[j].cost;

            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                changed = true;
            }
        }

        if (!changed)
            break;
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }

    return 0;
}