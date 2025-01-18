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

ll res = 0;
void magic(int mx, int pos, vector<int> digit, bool lim, ll cur)
{
    if (pos == (int)digit.size())
    {
        res += cur;
        return;
    }

    if (lim == false)
    {
        magic(mx, pos + 1, digit, false, cur * mx);
        return;
    }

    if (digit[pos] < mx)
        magic(mx, pos + 1, digit, true, cur);
    magic(mx, pos + 1, digit, false, cur * (min(mx, digit[pos] + 1) - (digit[pos] < mx)));
}

ll tmp_compute(ll x)
{
    if (x < 10) return 0;
    vector<int> digit;
    while (x)
    {
        digit.push_back(x % 10);
        x /= 10;
    }
    reverse(digit.begin(), digit.end());

    res = 0;
    magic(digit[0], 1, digit, true, 1);
    for (int i = 1; i < digit[0]; i++)
        magic(i, 1, digit, false, 1);
    return res;
}

int len(ll x) { return to_string(x).length(); }

ll compute(ll x)
{
    ll ans = tmp_compute(x);
    ll tmp = 0;
    int l = len(x);
    for (int i = 1; i < l; i++)
    {
        tmp = tmp * 10 + 9;
        ans += tmp_compute(tmp);
    }
    return ans;
}

void solve()
{
    ll l, r; cin >> l >> r;

    cout << compute(r) - compute(l - 1) << '\n';
}
