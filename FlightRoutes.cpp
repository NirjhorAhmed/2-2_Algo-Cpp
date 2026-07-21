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
    ll dist;
    int vertex;

    bool operator<(const Node &other) const
    {
        return dist > other.dist;
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    priority_queue<Node> pq;

    vector<int> cnt(n + 1, 0);
    vector<ll> ans;

    pq.push({0, 1});

    while (!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();

        int u = cur.vertex;
        ll d = cur.dist;

        if (cnt[u] >= k)
            continue;

        cnt[u]++;

        if (u == n)
            ans.push_back(d);

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].to;
            ll w = adj[u][i].cost;

            pq.push({d + w, v});
        }
    }

    for (int i = 0; i < k; i++)
        cout << ans[i] << " ";

    cout << endl;

    return 0;
}