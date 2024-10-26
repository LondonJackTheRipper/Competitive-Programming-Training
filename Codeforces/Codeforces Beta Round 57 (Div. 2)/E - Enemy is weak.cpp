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

struct FenwickTree
{
    int n;
    vector<ll> bits;

    FenwickTree(int n = 0) : n(n) { bits.resize(n + 1, 0); }

    void update(int pos, ll val)
    {
        for (pos; pos <= n; pos += (pos & (-pos)))
            bits[pos] += val;
    }

    ll query(int pos)
    {
        ll res = 0;
        for (pos; pos > 0; pos -= (pos & (-pos)))
            res += bits[pos];
        return res;
    }
};

int n;
int a[maxn];

int cur = 0;
void compress(unordered_map<int, int>& cmp)
{
    vector<int> cop(a + 1, a + n + 1);
    sort(cop.begin(), cop.end());
    for (int x : cop)
        cmp[x] = ++cur;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    unordered_map<int, int> cmp;
    compress(cmp);

    FenwickTree bit[4];
    for (int i = 1; i <= 3; i++)
        bit[i] = FenwickTree(cur);

    for (int i = n; i > 0; i--)
    {
        int v = a[i];
        ll tmp1 = bit[1].query(cmp[v]);
        ll tmp2 = bit[2].query(cmp[v]);
        bit[1].update(cmp[v], 1);
        bit[2].update(cmp[v], tmp1);
        bit[3].update(cmp[v], tmp2);
        
    }
    
    cout << bit[3].query(cur) << '\n';
}
