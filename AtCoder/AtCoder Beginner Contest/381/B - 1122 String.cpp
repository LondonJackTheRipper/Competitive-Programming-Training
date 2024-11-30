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
    string s; cin >> s;

    if ((int)s.length() % 2 == 1)
    {
        cout << "No\n";
        return;
    }
    vector<int> cnt(26, 0);
    for (int i = 1; i <= (int)s.length() / 2; i++)
    {
        if (s[2 * i - 1] != s[2 * i - 2])
        {
            cout << "No\n";
            return;
        }
        cnt[s[2 * i - 1] - 'a']++;
        cnt[s[2 * i - 2] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        if (cnt[i] != 0 && cnt[i] != 2)
        {
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
}
