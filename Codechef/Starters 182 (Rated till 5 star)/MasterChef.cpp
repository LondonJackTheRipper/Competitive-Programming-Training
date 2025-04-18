#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

const string name = "test";

void solve();
signed main()
{
    if (fopen((name + ".inp").c_str(), "r"))
    {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

// main program
bool process(int n, int k, string s)
{
    vector<pair<int, int>> proc;
    vector<int> left(n, 0);
    int cur = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            if (cur >= k)
                proc.push_back({i - cur, cur});
            if (cur >= 2 * k - 1)
                return false;
            left[i] = cur;
            cur = 1;
        } else
        {
            cur++;
            left[i] = 0;
        }
    }
    if (cur >= k)
        proc.push_back({n - cur, cur});
    if (cur >= 2 * k - 1)
        return false;
    
    if (proc.empty())
        return true;
    if ((int)proc.size() > 2)
        return false;
    if ((int)proc.size() == 2)
        return (s[proc[0].first] != s[proc[1].first]);
        
        for (int i = 0; i < proc[0].first; i++)
            if (s[i] != s[proc[0].first] && proc[0].second - k + 1 + left[i] < k)
                return true;
    
    return false;
}

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    bool res = process(n, k, s);
    reverse(s.begin(), s.end());
    res |= process(n, k, s);
    
    cout << (res == true ? "YES\n" : "NO\n");
}
