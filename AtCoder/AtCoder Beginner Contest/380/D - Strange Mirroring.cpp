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
char C(char c)
{
    return (isupper(c) ? char(tolower(c)) : char(toupper(c)));
}

void solve()
{
    string s; cin >> s;
    int q; cin >> q;

    while (q--)
    {
        ll k; cin >> k;

        k--;
        int rem = k % s.length();
        k /= s.length();
        int cnt = 0;
        for (int i = 60; i >= 0; i--)
            if (k >> i & 1ll)
                cnt++;

        cout << (cnt % 2 == 0 ? s[rem] : C(s[rem]));
        cout << ' ';
    }
}
