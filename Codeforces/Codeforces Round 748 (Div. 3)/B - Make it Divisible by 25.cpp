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
    string s; cin >> s;
    int n = s.length();

    vector<int> cnt(10, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        cnt[s[i] - '0']++;

        if (cnt[0] > 1 || (s[i] == '2' && cnt[5]) || (s[i] == '5' && cnt[0]) || (s[i] == '7' && cnt[5]))
        {
            cout << n - i - 2 << '\n';
            return;
        }
    }
}
