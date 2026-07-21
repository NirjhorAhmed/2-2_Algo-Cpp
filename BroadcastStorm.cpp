#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
bool hasCycle;

void dfs(int node, int parent)
{
    visited[node] = 1;

    for (int next : adj[node])
    {
        if (!visited[next])
        {
            dfs(next, node);
        }
        else if (next != parent)
        {
            hasCycle = true;
        }
    }
}

int main(){

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        adj.assign(n + 1, vector<int>());
        visited.assign(n + 1, 0);

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int answer = 0;

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                hasCycle = false;
                dfs(i, -1);

                if (hasCycle)
                    answer++;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}