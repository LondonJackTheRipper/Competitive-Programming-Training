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
void prepare(int n);
signed main()
{
    if (fopen((name + ".inp").c_str(), "r"))
    {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    prepare(1e5);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

// main program
const ll oo = 1e18;

vector<int> primes, lpf;
void prepare(int n)
{
    lpf.resize(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        if (lpf[i] == 0)
        {
            lpf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes)
        {
            if (i > n / p) break;

            lpf[i * p] = p;
        }
    }
}

void solve()
{
    int d; cin >> d;

    ll res = oo;
    for (int p : primes)
        if (p - 1 >= d)
        {
            if (1ll * p * p - p >= d)
                res = min(res, 1ll * p * p * p);
            auto it = lower_bound(primes.begin(), primes.end(), p + d);
            if (it != primes.end())
            {
                res = min(res, 1ll * p * (*(it)));
                break;
            }
        }

    cout << res << '\n';
}
