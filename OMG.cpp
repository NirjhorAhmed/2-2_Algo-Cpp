#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, W;
    cin >> N >> W;

    vector<int> ram(N);
    vector<int> traffic(N);

    for (int i = 0; i < N; i++)
        cin >> ram[i];

    for (int i = 0; i < N; i++)
        cin >> traffic[i];

    vector<int> dp(W + 1, 0);

    for (int i = 0; i < N; i++)
    {
        for (int copy = 1; copy <= 2; copy++)
        {
            for (int j = W; j >= ram[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - ram[i]] + traffic[i]);
            }
        }
    }

    cout << dp[W];

    return 0;
}