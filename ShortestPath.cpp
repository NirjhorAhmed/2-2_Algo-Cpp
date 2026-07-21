#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main(){
    
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dist(n + 1, INF);
    vector<int> parent(n + 1);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        ll d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node])
            continue;

        for (auto edge : adj[node])
        {
            int next = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[next])
            {
                dist[next] = dist[node] + weight;
                parent[next] = node;
                pq.push({dist[next], next});
            }
        }
    }

    if (dist[n] == INF)
    {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> path;

    int cur = n;

    while (parent[cur] != cur)
    {
        path.push_back(cur);
        cur = parent[cur];
    }

    path.push_back(1);

    reverse(path.begin(), path.end());

    for (int x : path)
        cout << x << " ";

    cout << "\n";

    return 0;
}