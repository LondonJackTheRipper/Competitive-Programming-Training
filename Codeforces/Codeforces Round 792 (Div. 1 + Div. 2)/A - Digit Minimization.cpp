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

    vector<int> cnt(10, 0), pos(10, 0);
    for (int i = 0; i < s.length(); i++)
    {
        int num = s[i] - '0';
        cnt[num]++;
        pos[num] = s.length() - i;
    }

    sort(s.begin(), s.end());
    for (int i = 1; i <= 9; i++)
    {
        if (cnt[i] == 0) continue;

        if (cnt[i] > 1)
            cout << i << '\n';
        else
            cout << (n == 2 && pos[i] == 2 ? (s[1] - '0') : i) << '\n';

        return;
    }
}
