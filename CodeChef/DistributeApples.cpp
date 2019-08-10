#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long n, k;
        cin >> n >> k;
        long groups = n/k;
        if (groups%k==0)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
        
    }
    return 0;
}