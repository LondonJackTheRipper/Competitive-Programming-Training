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
    string s, t; cin >> s >> t;

    if (n < 6)
    {
        if (n == 4)
        {
            bool ans = (s == t);
            swap(s[0], s[3]);

            cout << (ans | (s == t) == 1 ? "YES\n" : "NO\n");
        } else
        if (n < 4)
            cout << (s == t ? "YES\n" : "NO\n");
        else
        {
            bool ans = (s[2] == t[2]);
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());

            cout << (ans & (s == t) ? "YES\n" : "NO\n");
        }
        return;
    }

    vector<int> cnt1(26, 0), cnt2(26, 0);
    for (char c : s)
        cnt1[c - 'a']++;
    for (char c : t)
        cnt2[c - 'a']++;

    for (int i = 0; i < 26; i++)
        if (cnt1[i] != cnt2[i])
        {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}
