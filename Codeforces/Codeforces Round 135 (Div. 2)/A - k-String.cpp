#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
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

    solve();

    return 0;
}

// main program

void solve()
{
    int k; cin >> k;
    vector<int> cnt(26, 0);
    string s; cin >> s;
    for (char c : s) cnt[c - 'a']++;

    for (int i = 0; i < 26; i++)
        if (cnt[i] % k != 0)
        {
            cout << -1 << '\n';
            return;
        }

    for (int i = 0; i < k; i++)
        for (int c = 0; c < 26; c++)
            for (int num = 0; num < cnt[c] / k; num++)
                cout << char(c + 'a');
    cout << '\n';
}
