#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int N;
        cin >> N;

        vector<vector<long long>> dist(N + 1, vector<long long>(N + 1));

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin >> dist[i][j];
            }
        }

        for (int k = 1; k <= N; k++)
        {
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= N; j++)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        int R;
        cin >> R;

        long long ans = 0;

        for (int i = 0; i < R; i++)
        {
            int s, d;
            cin >> s >> d;

            ans += dist[s][d];
        }

        cout << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}