#include <bits/stdc++.h>
using namespace std;

void clear_dp(int dp[100001])
{
    for (int i=0; i<100001; i++) dp[i] = 0;
}

int main()
{
    int t;
    cin >> t;
    int dp[100001];
    while (t--)
    {
        string s; cin >> s;
        int n = s.size();
        clear_dp(dp);
        dp[n-1] = s[n-1]-'0';
        for (int i=n-2; i>=0; i--)
        {
            if (s[i]=='0') dp[i] = dp[i+1];
            else dp[i] = !dp[i+1];
        }
        cout << (dp[0] ? "WIN\n" : "LOSE\n");
    }
    return 0;
}