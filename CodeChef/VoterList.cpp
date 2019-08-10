// CodeChef Voters List

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    map<int, int> voter_count;
    int id;
    for (int n: {n1, n2, n3})
    {
        for (int i=0; i<n; i++)
        {
            cin >> id;
            voter_count[id]++;
        }
    }
    string out {'\n'};
    int count {0};
    for (map<int, int>::iterator itr=voter_count.begin(); itr!=voter_count.end(); itr++)
    {
        if (itr->second > 1)
        {
            out += (to_string(itr->first) + '\n');
            count++;
        }
    }
    cout << count << out;
    return 0;
}