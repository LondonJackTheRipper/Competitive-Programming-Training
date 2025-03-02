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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        int idx = c - 'a';

        if (idx <= k)
            cout << 'a';
        else
        {
            int rem = k - mx;
            char res_c = char(c - rem);
            for (int j = i; j < n; j++)
            {
                int nxt_idx = s[j] - 'a';

                if (nxt_idx <= mx)
                    cout << 'a';
                else
                    cout << (idx - rem <= nxt_idx && nxt_idx <= idx ? res_c : s[j]);
            }
            break;
        }
        mx = max(mx, idx);
    }
    cout << '\n';
}
