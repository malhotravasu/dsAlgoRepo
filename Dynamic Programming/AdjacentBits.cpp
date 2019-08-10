/// SPOJ GNYR09F - Adjacent Bit Counts

#include <bits/stdc++.h>
using namespace std;

void clear_dp(int dp[2][101][101])
{
	for (int i=0; i<2; i++)
		for (int j=0; j<101; j++)
			for (int k=0; k<101; k++)
				dp[i][j][k] = -1;
}

int adjCountK(int first, int n, int k, int dp[2][101][101])
{
	if (dp[first][n][k]!=-1) return dp[first][n][k];
	
	int result;
	if (n==0) return 0;
	else if (n==1)
	{
		if (k==0) return first ? 1 : 2;
		else if (k<0) return 0;
		else if (k==1) return first;
		else return 0;
	}
	else if (k>n) result=0;
	else if (n==k) result=first;
	else
	{
		if (first==1)
		{
			result = adjCountK(1, n-1, k-1, dp)+adjCountK(0, n-1, k, dp);
		}
		else
		{
			result = adjCountK(1, n-1, k, dp)+adjCountK(0, n-1, k, dp);
		}
	}
	return dp[first][n][k] = result;
}

int main() 
{
	int dp[2][101][101];
	int t;
	cin >> t;
	while (t--)
	{
		clear_dp(dp);
		int idx, n, k;
		cin >> idx >> n >> k;
		int result = adjCountK(0, n-1, k, dp) + adjCountK(1, n-1, k, dp);
		cout << idx << ' ' << result << '\n';
	}
	return 0;
}