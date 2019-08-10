// CodeChef Hussain's Set

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    long *arr = new long[n];
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n, greater<long> ());

    queue<long> ol;
    for (int i=0; i<n; i++) ol.push(arr[i]);
    queue<long> nw;
    long ans[63000001], max_elem;
    for (int i=1; i<63000001; i++)
    {
        if (ol.empty())
        {
            max_elem = nw.front();
            nw.pop();
            nw.push(max_elem/2);
        }
        else if (nw.empty())
        {
            max_elem = ol.front();
            ol.pop();
            nw.push(max_elem/2);
        }
        else
        {
            long x = ol.front(), y = nw.front();
            if (x>=y)
            {
                max_elem = x;
                ol.pop();
                nw.push(x/2);
            }
            else
            {
                max_elem = y;
                nw.pop();
                nw.push(y/2);
            }   
        }
        ans[i] = max_elem;
    }
    
    int idx;
    while (m--)
    {
        cin >> idx;
        cout << ans[idx] << '\n';
    }
    return 0;
}