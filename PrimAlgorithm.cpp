#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

struct Edge
{
    int to;
    ll cost;
};

struct Node
{
    int vertex;
    ll cost;

    bool operator<(const Node &other) const
    {
        return cost > other.cost;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<bool> visited(n + 1, false);

    priority_queue<Node> pq;

    pq.push({1, 0});

    ll ans = 0;
    int cnt = 0;

    while (!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();

        int u = cur.vertex;

        if (visited[u])
            continue;

        visited[u] = true;
        ans += cur.cost;
        cnt++;

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].to;
            ll w = adj[u][i].cost;

            if (!visited[v])
                pq.push({v, w});
        }
    }

    if (cnt != n)
        cout << "IMPOSSIBLE";
    else
        cout << ans;

    return 0;
}