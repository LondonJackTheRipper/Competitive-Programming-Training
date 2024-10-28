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
const int mod = 1e9 + 7;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
int sub(int a, int b) { a -= b; if (a < 0) a += mod; return a; }
int mul(int a, int b) { return (1ll * a * b) % mod; }

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b % 2 == 1)
            res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

void solve()
{
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    int cur = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++)
    {
        cur = add(cur, a[i]);
      
        int p = 0;
        while (a[i] % 2 == 0)
        {
            p++;
            a[i] /= 2;
        }
      
        while (!pq.empty())
        {
            int x = pq.top().first, cnt = pq.top().second;

            bool great= false;
            if (p > 31)
                great = true;
            else
                if (1ll * (1 << p) * a[i] >= x)
                    great = true;
            if (!great) break;

            pq.pop();

            cur = sub(cur, mul(power(2, p), a[i]));
            cur = add(cur, mul(power(2, p + cnt), a[i]));
            cur = sub(cur, mul(x, power(2, cnt)));
            cur = add(cur, x);
            p += cnt;
        }

        if (p != 0)
            pq.push({a[i], p});

        cout << cur << ' ';
    }
    cout << '\n';
}
