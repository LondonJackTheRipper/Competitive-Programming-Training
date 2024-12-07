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
    int total = 0, num2 = 0,num3 = 0, n = s.length();
    for (int i = 0; i < n; i++)
    {
        total += (s[i] - '0');
        if (s[i] == '2') num2++;
        if (s[i] == '3') num3++;
    }

    for (int i = 0; i <= num2; i++)
        for (int j = 0; j <= num3; j++)
            if ((total + 6 * j + 2 * i) % 9 == 0)
            {
                cout << "YES\n";
                return;
            }
    cout << "NO\n";
}
