#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

struct Edge
{
    int to;
    ll w;
};

struct Node
{
    ll dist;
    int vertex;

    bool operator<(const Node &other) const
    {
        return dist > other.dist;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> adj(N + 1);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dist1(N + 1, INF);
    vector<ll> dist2(N + 1, INF);

    priority_queue<Node> pq;

    dist1[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();

        ll d = cur.dist;
        int u = cur.vertex;

        if (d > dist2[u])
            continue;

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].to;
            ll w = adj[u][i].w;

            ll nd = d + w;

            if (nd < dist1[v])
            {
                swap(nd, dist1[v]);
                pq.push({dist1[v], v});
            }

            if (nd > dist1[v] && nd < dist2[v])
            {
                dist2[v] = nd;
                pq.push({dist2[v], v});
            }
        }
    }

    if (dist1[N] == INF)
        cout << -1 << endl;
    else
        cout << dist2[N] << endl;

    return 0;
}