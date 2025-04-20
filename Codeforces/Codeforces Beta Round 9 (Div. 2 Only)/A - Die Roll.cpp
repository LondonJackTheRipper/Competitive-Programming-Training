#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
    int h, w; cin >> h >> w;
    h = max(h, w);

    int num = 7 - h, dem = 6;
    if (dem % num == 0)
    {
        dem /= num;
        num = 1;
    }
    if (num == 4)
    {
        num = 2;
        dem = 3;
    }

    cout << num << '/' << dem << '\n';
}
