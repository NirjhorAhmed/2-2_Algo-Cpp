#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

struct Edge
{
    int to;
    double prob;
};

struct Node
{
    double prob;
    int vertex;

    bool operator<(const Node &other) const
    {
        return prob < other.prob;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        double w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int start, finish;
    cin >> start >> finish;

    vector<double> best(n, 0.0);

    priority_queue<Node> pq;

    best[start] = 1.0;
    pq.push({1.0, start});

    while (!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();

        if (cur.prob < best[cur.vertex])
            continue;

        for (int i = 0; i < adj[cur.vertex].size(); i++)
        {
            int next = adj[cur.vertex][i].to;
            double p = adj[cur.vertex][i].prob;

            if (best[cur.vertex] * p > best[next])
            {
                best[next] = best[cur.vertex] * p;
                pq.push({best[next], next});
            }
        }
    }

    cout << fixed << setprecision(5) << best[finish] << endl;

    return 0;
}