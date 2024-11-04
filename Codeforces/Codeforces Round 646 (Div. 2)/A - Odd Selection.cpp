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
    int n, x; cin >> n >> x;
    int cnt_odd = 0, cnt_even = 0;
    for (int i = 0; i < n; i++)
    {
        int val; cin >> val;
        (val % 2 == 1 ? cnt_odd++ : cnt_even++);
    }

    for (int i = 1; i <= min(x, cnt_odd); i += 2)
    {
        int rem = x - i;
        if (rem <= cnt_even)
        {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}
