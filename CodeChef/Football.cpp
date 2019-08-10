// CodeChef AugustLong-2019 Football

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sc[n][2];
        int max_points {0};
        for (int i=0; i<n; i++) cin >> sc[i][0];
        for (int i=0; i<n; i++) cin >> sc[i][1];
        for (int i=0; i<n; i++)
        {
            int score = sc[i][0]*20 - sc[i][1]*10;
            max_points = max(score, max_points);
        }
        cout << max_points << '\n';
    }
    return 0;
}