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
void prepare();
signed main()
{
    if (fopen((name + ".inp").c_str(), "r"))
    {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    prepare();
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

// main program
vector<ll> pre;
void prepare()
{
    pre.resize(2e5 + 9, 0);
    for (int i = 1; i <= (int)2e5; i++)
    {
        int x = i;
        int sum = 0;
        while (x)
        {
            sum += (x % 10);
            x /= 10;
        }
        pre[i] = sum + pre[i - 1];
    }
}

void solve()
{
    int n; cin >> n;

    cout << pre[n] << '\n';
}
