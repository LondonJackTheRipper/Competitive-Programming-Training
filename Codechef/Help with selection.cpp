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
const int maxp = 1e5 + 9;

ll n, k;
int p;

int add(int a, int b) { a += b; if (a >= p) a -= p; return a; }
int mul(int a, int b) { return 1ll * a * b % p; }

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

int fac[maxp], inv[maxp];
void init(int n)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++) 
        fac[i] = mul(fac[i - 1], i);
    inv[n] = power(fac[n], p - 2);
    for (int i = n - 1; i >= 0; i--)
        inv[i] = mul(inv[i + 1], i + 1);
}

int comb(int k, int n) 
{
    if (k > n) return 0;
    return mul(fac[n], mul(inv[k], inv[n - k]));
}

void solve()
{
    cin >> n >> k >> p;
    init(p - 1);

    int res = 1;
    int highest = max((int)pow(n, 1.0/(double)p), (int)pow(k, 1.0/(double)p));
    for (int i = highest; i >= 0; i--)
    {
        ll num = pow(p, i);
        int n_i = n / num; n %= num;
        int k_i = k / num; k %= num;

        res = mul(res, comb(k_i, n_i));
    }
    
    cout << res << '\n';
}
