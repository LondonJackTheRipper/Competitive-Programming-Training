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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> cnt(26, 0);
    for (int i = 0; i < k; i++)
    {
        char c; cin >> c;
        cnt[c - 'a']++;
    }
    vector<int> unable;
    for (int i = 0; i < 26; i++)
        if (cnt[i] == 0)
            unable.push_back(char(i + 'a'));

    vector<int> pos[26];
    for (int i = 0; i < n; i++)
        pos[s[i] - 'a'].push_back(i);

    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        int position = n;
        for (char c : unable)
        {
            int tmp = lower_bound(pos[c - 'a'].begin(), pos[c - 'a'].end(), i) - pos[c - 'a'].begin();
            if (tmp == pos[c - 'a'].size()) tmp = n; else tmp = pos[c - 'a'][tmp];
            position = min(position, tmp);
        }

        res += position - i;
    }

    cout << res << '\n';
}
