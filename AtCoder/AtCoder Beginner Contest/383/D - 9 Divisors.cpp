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
vector<int> primes, lpf;
void init(int n)
{
    lpf.resize(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        if (lpf[i] == 0)
        {
            primes.push_back(i);
            lpf[i] = i;
        }

        for (int p : primes)
        {
            if (p > lpf[i] || i > n / p) break;

            lpf[i * p] = p;
        }
    }
}

bool prime(int x) { return lpf[x] == x; }

void solve()
{
    init(2e6);

    ll n; cin >> n;

    ll res = 0;
    for (int i = 2; 1ll * i * i * i * i * i * i * i * i <= n; i++) if (prime(i)) res++;
    for (int i = 2; 1ll * i * i <= n; i++)
    {
        int l = lpf[i];

        //if (prime(l) && prime(i / l) && l != i / l) cout << i << '\n';
        int p = 1;
        bool flag = true;
        for (; p <= i; p *= l) if (p == i) flag = false;

        if (flag) res += (prime(l) && prime(i / l));
    }

    cout << res << '\n';
}
