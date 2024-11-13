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
    vector<int> pre(n, 0), cnt_pre(26, 0), suf(n, 0), cnt_suf(26, 0);
    pre[0] = suf[n - 1] = 1;
    cnt_pre[s[0] - 'a'] = cnt_suf[s[n - 1] - 'a'] = 1;
    for (int i = 1; i < n; i++)
    {
        int x = s[i] - 'a';
        cnt_pre[x]++;
        pre[i] = pre[i - 1] + (cnt_pre[x] == 1);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        int x = s[i] - 'a';
        cnt_suf[x]++;
        suf[i] = suf[i + 1] + (cnt_suf[x] == 1);
    }

    int res = pre[n - 1];
    for (int i = 0; i < n - 1; i++)
        res = max(res, pre[i] + suf[i + 1]);

    cout << res << '\n';
}
