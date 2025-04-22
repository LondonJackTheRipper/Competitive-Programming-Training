#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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

    if (n == 1)
        cout << (s == "0" ? 1 : 2) << '\n';
    else
    {
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
            {
                bool can = false;
                for (int j = n - 1; j > i; j--)
                    if (s[j] == '1' && s[j - 1] == '0')
                    {
                        reverse(s.begin() + i, s.begin() + j);
                        can = true;
                        break;
                    }
                if (!can)
                    reverse(s.begin() + i, s.end());
                break;
            }
        int res = 0;
        for (int i = 1; i < n; i++)
            res += (s[i] != s[i - 1]);
        cout << res + n + (s[0] == '1') << '\n';
    }
}
