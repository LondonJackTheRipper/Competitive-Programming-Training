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
    string str; getline(cin, str);
    int num = 0;
    for (char c : str)
    {
        if (!isdigit(c)) continue;
        num = num * 10 + (c - '0');
    }

    int sq = sqrt(num);
    cout << (sq * sq == num ? "Yes\n" : "No\n");
}

