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

    string a = "", b = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '2')
        {
            a.push_back('1');
            b.push_back('1');
        } else
        if (s[i] == '0')
        {
            a.push_back('0');
            b.push_back('0');
        } else
        {
            a.push_back('1');
            b.push_back('0');
            break;
        }
    }
    while (a.length() < n) a.push_back('0');
    while (b.length() < n) b.push_back(s[b.length()]);

    cout << a << '\n' << b << '\n';
}
