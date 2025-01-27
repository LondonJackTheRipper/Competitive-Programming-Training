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
    string s; cin >> s;
    vector<int> cnt(26, 0);
    cnt[s[0] - 'A']++;
    for (int i = 1; i < n; i++)
    {
        if (cnt[s[i] - 'A'] > 0 && s[i - 1] != s[i])
        {
            cout << "NO\n";
            return;
        }
        cnt[s[i] - 'A']++;
    }
    cout << "YES\n";
}
