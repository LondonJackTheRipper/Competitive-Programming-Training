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
vector<int> lpf, primes;
void linear_sieve(int n)
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
            if (p > n / i) break;

            lpf[p * i] = p;
        }
    }
}

bool prime(int n) { return (lpf[n] == n); }

void solve()
{
    int n; cin >> n;
    linear_sieve(n);

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int num = 0;
        for (int j = 1; j <= i; j++)
            num += (i % j == 0 && prime(j));

        res += (num == 2);
    }

    cout << res << '\n';
}
