// CodeChef Zombie Caves - August Long

#include <bits/stdc++.h>
using namespace std;

void clear_arr(int arr[100005])
{
    for (int i=0; i<100005; i++) arr[i] = 0;
}

bool is_arr_empty(int arr[100005])
{
    for (int i=0; i<100005; i++)
    {
        if (arr[i]) return false;
    }
    return true;
}

int C[100005];
int diff[100005];
int zomb_count[100005];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        clear_arr(C);
        clear_arr(diff);
        clear_arr(zomb_count);
        
        int n; cin >> n;

        for (int i=1; i<=n; i++) cin >> C[i];
        
        for (int i=1, l, r; i<=n; i++)
        {
            l = i-C[i];
            l = (l<1) ? 1: l;
            r = i+C[i];

            diff[l]++;
            if (r<n) diff[r+1]--;
        }

        for (int i=1, zomb_health; i<=n; i++)
        { 
            cin >> zomb_health;
            if (zomb_health > n) continue;
            zomb_count[zomb_health]++;
        }
        
        for (int i=1; i<=n; i++)
        {
            diff[i] += diff[i-1];
            zomb_count[diff[i]]--;
        }

        if (is_arr_empty(zomb_count))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}