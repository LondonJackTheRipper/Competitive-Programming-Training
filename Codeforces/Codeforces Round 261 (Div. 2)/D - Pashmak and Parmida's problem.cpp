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
const int maxn = 1e6 + 9;

int n, N;
int a[maxn];
int LEFT[maxn], RIGHT[maxn];

int cur = 0;
unordered_map<int, int> cmp;
void compress()
{
    vector<int> cop(a + 1, a + n + 1);
    sort(cop.begin(), cop.end());
    for (int x : cop)
        if (cmp[x] == 0)
            cmp[x] = ++cur;
}

int freq1[maxn], freq2[maxn];

struct FenwickTree
{
    int n;
    vector<ll> bits;

    FenwickTree(int n) : n(n) { bits.resize(n + 1, 0); }

    void update(int pos, ll val)
    {
        for (; pos <= n; pos += (pos & (-pos)))
            bits[pos] += val;
    }

    ll query(int pos)
    {
        ll res = 0;
        for (; pos > 0; pos -= (pos & (-pos)))
            res += bits[pos];
        return res;
    }
};

void solve()
{
    cin >> n;
    N = sqrt(n);
    for (int i = 1; i <= n; i++) cin >> a[i];

    compress();

    for (int i = 1; i <= n; i++)
    {
        freq1[cmp[a[i]]]++;
        LEFT[i] = freq1[cmp[a[i]]];
    }
    for (int i = n; i > 0; i--)
    {
        freq2[cmp[a[i]]]++;
        RIGHT[i] = freq2[cmp[a[i]]];
    }

    ll res = 0;
    FenwickTree bit(n);
    for (int i = n; i > 0; i--)
    {
        res += bit.query(LEFT[i] - 1);
        bit.update(RIGHT[i], 1);
    }

    cout << res << '\n';
}
