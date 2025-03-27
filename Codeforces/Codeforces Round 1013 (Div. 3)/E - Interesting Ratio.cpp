#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
vector<int> primes;
vector<int> prime;
void sieve(int n)
{
    primes.clear();
    prime.resize(n + 1, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == 0)
            continue;
        for (int j = i * i; j <= n; j += i)
            prime[j] = 0;
    }
    for (int i = 2; i <= n; i++)
        if (prime[i])
            primes.push_back(i);
}

void solve()
{
    int n; cin >> n;
    sieve(n);

    ll ans = 0;
    for (int p : primes)
    {
        ll cur = p;
        while (cur <= n)
        {
            int x = n / cur;
            x -= (x / p);
            ans += x;
            cur *= p;
        }
    }

    cout << ans << '\n';
}
