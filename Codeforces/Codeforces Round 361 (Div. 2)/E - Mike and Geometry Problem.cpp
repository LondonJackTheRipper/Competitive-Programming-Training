#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
const int mod = 1e9 + 7;
const int maxn = 2e5 + 1;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
int mul(int a, int b) { return 1ll * a * b % mod; }

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

vector<int> fac, inv;
void prepare(int n)
{
    fac.resize(n + 1, 1);
    inv.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
        fac[i] = mul(fac[i - 1], i);
    inv[n] = power(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; i--)
        inv[i] = mul(inv[i + 1], i + 1);
}
int C(int k, int n) { return (k <= n ? mul(fac[n], mul(inv[k], inv[n - k])) : 0); }

int n, k;
vector<int> p;
vector<pair<int, int>> segs;

void solve()
{
    prepare(2e5);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int l, r; cin >> l >> r;
        segs.push_back({l, r});
        p.push_back(l);
        p.push_back(r);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    sort(segs.begin(), segs.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int pos = 0, res = 0;
    for (int i = 0; i < (int)p.size(); i++)
    {
        int point = p[i];
        while (pos < n && segs[pos].first <= point)
        {
            pq.push({segs[pos].second, segs[pos].first});
            pos++;
        }

        int extra = 0;
        while (!pq.empty() && pq.top().first <= point)
        {
            extra += (pq.top().first == point);
            pq.pop();
        }
        int segment = pq.size();

        res = add(res, C(k, segment + extra));
        if (i != (int)p.size() - 1)
            res = add(res, mul(p[i + 1] - p[i] - 1, C(k, segment)));
    }

    cout << res << '\n';
}
