#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

int main()
{
    int n;
    cin >> n;

    vector<long long> dp(n + 1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + ((i - 1) * dp[i - 2]) % MOD) % MOD;
    }

    cout << dp[n];

    return 0;
}