#include <iostream>
#include <vector>
#include <queue>
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
    int n, m, s;
    cin >> n >> m >> s;

    vector<Edge> edges;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        edges.push_back({a, b, c});
        adj[a].push_back(b);
    }

    vector<ll> dist(n + 1, INF);
    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j].from;
            int v = edges[j].to;
            ll w = edges[j].cost;

            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    vector<int> bad(n + 1, 0);
    queue<int> q;

    for (int j = 0; j < m; j++)
    {
        int u = edges[j].from;
        int v = edges[j].to;
        ll w = edges[j].cost;

        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            if (!bad[v])
            {
                bad[v] = 1;
                q.push(v);
            }
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];

            if (!bad[v])
            {
                bad[v] = 1;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i == s)
        {
            cout << 0 << endl;
        }
        else if (dist[i] == INF)
        {
            cout << "INF" << endl;
        }
        else if (bad[i])
        {
            cout << "-INF" << endl;
        }
        else
        {
            cout << dist[i] << endl;
        }
    }

    return 0;
}