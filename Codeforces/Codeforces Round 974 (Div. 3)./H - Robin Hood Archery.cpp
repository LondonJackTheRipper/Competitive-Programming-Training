#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

string name = "main";

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
const int maxn = 2e5 + 9;
const int maxv = 1e6 + 9;

int n, q;
int a[maxn];

int num, N;
int freq[maxv];

struct Query
{
    int l, r, id;

    Query() = default;
    Query(int l, int r, int id) : l(l), r(r), id(id) {};
};

bool cmp(Query a, Query b)
{
    if (a.l / N == b.l / N)
        return a.r < b.r;
    return a.l / N < b.l / N;
}

void add(int x)
{
    freq[x]++;
    num += (freq[x] % 2 == 1 ? 1 : -1);
}

void rem(int x)
{
    freq[x]--;
    num += (freq[x] % 2 == 1 ? 1 : -1);
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        freq[a[i]] = 0;
    }

    num = 0;
    N = sqrt(n);
    vector<Query> qr;
    for (int i = 0; i < q; i++)
    {
        int l, r; cin >> l >> r;
        qr.push_back({l, r, i});
    }
    sort(qr.begin(), qr.end(), cmp);

    int cur_l = qr[0].l, cur_r = qr[0].l;
    vector<int> ans(q, 0);
    add(a[qr[0].l]);
    for (Query Q : qr)
    {
        int l = Q.l, r = Q.r;

        while (cur_l > l)
            add(a[--cur_l]);
        while (cur_r < r)
            add(a[++cur_r]);
        while (cur_l < l)
            rem(a[cur_l++]);
        while (cur_r > r)
            rem(a[cur_r--]);

        ans[Q.id] = (num == 0);
    }

    for (int i = 0; i < q; i++)
        cout << (ans[i] == 1 ? "YES" : "NO") << '\n';
}
