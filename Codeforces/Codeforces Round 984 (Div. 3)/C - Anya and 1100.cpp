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
    int cur = 0;
    vector<int> sub(s.length() + 1, 0);
    for (int i = 0; i < s.length() - 3; i++)
        if (s.substr(i, 4) == "1100")
        {
            cur++;
            sub[i] = 1;
        }

    int q; cin >> q;
    while (q--)
    {
        int pos; cin >> pos; pos--;
        char v; cin >> v;
        s[pos] = v;

        for (int i = max(0, pos - 3); i <= pos; i++)
        {
            int j = i + 3;
            if (j < s.length())
                if (s.substr(i, 4) != "1100")
                {
                    cur -= (sub[i] == 1);
                    sub[i] = 0;
                } else
                {
                    cur += (sub[i] == 0);
                    sub[i] = 1;
                }
        }

        cout << (cur > 0 ? "YES\n" : "NO\n");
    }
}
