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

    int res = 1e9;
    int j = 0;
    vector<int> cnt(4, 0);
    for (int i = 0; i < n; i++)
    {
        while (j < n && (cnt[1] == 0 || cnt[2] == 0 || cnt[3] == 0))
        {
            cnt[s[j] - '0']++;
            j++;
        }
        if (cnt[1] > 0 && cnt[2] > 0 && cnt[3] > 0)
            res = min(res, j - i);
        cnt[s[i] - '0']--;
    }

    cout << (res == 1e9 ? 0 : res) << '\n';
}
