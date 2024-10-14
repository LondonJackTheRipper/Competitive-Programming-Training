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

    prepare(2e5);
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

// main program
const int mod = 998244353;
const int maxn = 2e5 + 9;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
int sub(int a, int b) { a -= b; if (a < 0) a += mod; return a; }
int mul(int a, int b) { return 1ll * a * b % mod; }

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

vector<int> fac, inv;
void prepare(int n)
{
    fac.resize(n + 1, 1);
    inv.resize(n + 1, 1);
    for (int i = 2; i <= n; i++)
        fac[i] = mul(fac[i - 1], i);
    inv[n] = power(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; i--)
        inv[i] = mul(inv[i + 1], i + 1);
}

int P(int k, int n)
{
    if (k > n) return 0;
    return mul(fac[n], inv[n - k]);
}

void solve()
{
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    if (a[n] == a[n - 1])
        cout << fac[n] << '\n';
    else
    if (a[n] - a[n - 1] != 1)
        cout << 0 << '\n';
    else
    {
        int ans = 0, cnt = 0;
        for (int i = 1; i <= n; i++) if (a[i] == a[n - 1]) cnt++;
        for (int i = 1; i <= n; i++)
                ans = add(ans, sub(fac[n - 1], mul(P(cnt, i - 1), fac[n - 1 - cnt])));

        cout << ans << '\n';
    }
}
