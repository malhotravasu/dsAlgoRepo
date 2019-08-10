// Codechef - Permutations and Palindrome

#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char, vector<int>> idxs;
    int t;
    cin >> t;
    while (t--)
    {
        idxs.clear();
        string s;
        cin >> s;
        int n = s.size();
        
        for (int i=0; i<n; i++)
        {
            idxs[s[i]].push_back(i);
        }
        
        int oddc {0};
        for (auto itr=idxs.begin(); itr!=idxs.end(); itr++)
        {
            if (itr->second.size()%2) oddc++;
        }
        if (oddc > 1)
        {
            cout << -1 << '\n';
            continue;
        }
        
        int l {0}, r {n-1};
        vector<int> permutation(n);
        for (auto itr=idxs.begin(); itr!=idxs.end(); itr++)
        {
            vector<int> &curr_idxs = itr->second;
            if (curr_idxs.size()%2)
            {
                int mid = n/2;
                int l_ = mid-(curr_idxs.size()/2);
                for (int i=0; i<curr_idxs.size(); i++)
                {
                    permutation[l_] = curr_idxs[i];
                    l_++;
                }
            }
            else
            {
                for (int i=0; i<curr_idxs.size()-1; i+=2)
                {
                    permutation[l] = curr_idxs[i]; l++;
                    permutation[r] = curr_idxs[i+1]; r--;
                } 
            }
        }
        
        for (int &idx: permutation)
        {
            cout << (idx+1) << ' ';
        }
        cout << '\n';
    }
    return 0;
}