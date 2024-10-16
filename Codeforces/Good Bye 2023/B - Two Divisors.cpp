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

int GCD(int a, int b) { return (b == 0 ? a : GCD(b, a % b)); }
ll LCM(int a, int b) { return 1ll * a / GCD(a, b) * b; }

void solve()
{
    int a, b; cin >> a >> b;

    ll lcm = LCM(a, b) ;

    if (lcm == b)
        cout << (a == 1 ? lcm * b : lcm * (b / a)) << '\n';
    else
        cout << lcm << '\n';
}
