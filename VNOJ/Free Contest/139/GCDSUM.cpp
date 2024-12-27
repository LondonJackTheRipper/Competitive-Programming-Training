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
const int maxv = 1e6;
const int mod = 1e9 + 7;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
int sub(int a, int b) { a -= b; if (a < 0) a += mod; return a; }
int mul(int a, int b) { return 1ll * a * b % mod; }

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b % 2 == 1) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

ll cnt[maxv + 9];

void solve()
{
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j * j <= a[i]; j++)
        {
            if (a[i] % j != 0) continue;

            cnt[j]++;
            if (j * j != a[i]) cnt[a[i] / j]++;
        }
    }

    for (int i = 1; i <= maxv; i++) cnt[i] = sub(power(2, cnt[i]), 1);
    for (int i = maxv; i >= 1; i--)
        for (int j = 2 * i; j <= maxv; j += i)
            cnt[i] = sub(cnt[i], cnt[j]);

    int res = 0;
    for (int i = 1; i <= maxv; i++)
        res = add(res, mul(i, cnt[i]));

    cout << res << '\n';
}
