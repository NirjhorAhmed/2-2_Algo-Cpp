#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dist[i][j];
        }
    }

    vector<int> order(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> order[i];
    }

    vector<bool> active(n + 1, false);
    vector<ll> ans;

    for (int k = n; k >= 1; k--)
    {
        int x = order[k];
        active[x] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][x] + dist[x][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][x] + dist[x][j];
                }
            }
        }

        ll sum = 0;

        for (int i = 1; i <= n; i++)
        {
            if (!active[i])
                continue;

            for (int j = 1; j <= n; j++)
            {
                if (!active[j])
                    continue;

                sum += dist[i][j];
            }
        }

        ans.push_back(sum);
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}