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
const int maxn = 1e3 + 9;
const int mod = 1e9 + 7;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
int sub(int a, int b) { a -= b; if (a < 0) a += mod; return a; }

int p[maxn];
int n;

struct FenwickTree
{
    int n;
    vector<int> bits;

    FenwickTree(int n) : n(n) { bits.resize(n + 1, 0); }

    void update(int pos, int val)
    {
        for (; pos <= n; pos += (pos & (-pos)))
            bits[pos] = add(bits[pos], val);
    }

    int query(int pos)
    {
        int res = 0;
        for (; pos > 0; pos -= (pos & (-pos)))
            res = add(res, bits[pos]);
        return res;
    }
    int query(int l, int r) { return sub(query(r), query(l - 1)); }
};

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];

    FenwickTree bit(n);
    bit.update(1, 2);
    for (int i = 2; i <= n; i++)
    {
        int val = add(bit.query(p[i], i - 1), 2);
        bit.update(i, val);
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = add(res, bit.query(i, i));

    cout << res << '\n';
}
