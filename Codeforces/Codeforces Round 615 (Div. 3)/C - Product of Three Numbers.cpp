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
    int x; cin >> x;

    vector<int> divs;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            divs.push_back(i);
            x /= i;
            break;
        }
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0 && (!divs.empty() && i != divs.back()))
        {
            divs.push_back(i);
            x /= i;
            break;
        }

    if (divs.size() != 2 || (x == divs[0] || x == divs.back()))
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << divs[0] << ' ' << divs[1] << ' ' << x << '\n';
}
