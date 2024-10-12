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

    int t = 1;
    while (t--) solve();

    return 0;
}

// main program
int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}

void solve()
{
    string str; cin >> str;

    int tmp = 1;
    for (int i = 1; i < str.length(); i++)
        tmp += power(2, i);
    for (int i = 0; i < str.length(); i++)
        if (str[i] == '7')
            tmp += power(2, str.length() - i - 1);
    cout << tmp << '\n';
}
