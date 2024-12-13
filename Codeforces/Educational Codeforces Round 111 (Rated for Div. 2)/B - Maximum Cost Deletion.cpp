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
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    vector<int> need(2, 0);
    int cur = 0, cnt = 0;
    char prev = '#';
    for (char c : s)
    {
        cnt += (c == '0');

        if (c != prev && cur != 0)
        {
            need[prev - '0'] += max(cur * a + b, cur * (a + b));
            cur = 1;
        }
        else
            cur++;

        prev = c;
    }
    need[prev - '0'] += max(cur * a + b, cur * (a + b));

    int tmp1 = max((n - cnt) * a + b, (n - cnt) * (a + b));
    int tmp2 = max(cnt * a + b, cnt * (a + b));
    cout << max(need[0] + (n - cnt == 0 ? 0 : tmp1), need[1] + (cnt == 0 ? 0 : tmp2)) << '\n';
}
