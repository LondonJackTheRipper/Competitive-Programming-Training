#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

string name = "test";

void solve();
signed main()
{
    if (fopen((name + ".inp").c_str(), "r"))
    {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

// main program

void solve()
{
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x]++;
    }

    vector<int> proc;
    for (auto it : mp)
        proc.push_back(it.second);
    sort(proc.begin(), proc.end(), greater<int>());

    for (int i = n; i >= 0; i--)
    {
        int tmp = proc.front();
        if (i > tmp) continue;
        tmp -= i;

        int rem = proc.size() - (tmp == 0);
        if (rem >= i)
        {
            cout << i << '\n';
            return;
        }
    }
}
