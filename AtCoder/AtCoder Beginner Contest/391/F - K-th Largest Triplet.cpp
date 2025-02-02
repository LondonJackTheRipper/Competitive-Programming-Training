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
const int maxn = 2e5 + 9;

int a[maxn], b[maxn], c[maxn];
int n, k;

struct State
{
    int u, v, w;
    ll val;

    State(ll val, int u, int v, int w) : val(val), u(u), v(v), w(w) {};
    bool operator < (const State& other) const
    {
        return val < other.val;
    }
};

State proc(int u, int v, int w)
{
    return State(1ll * a[u] * b[v] + 1ll * a[u] * c[w] + 1ll * b[v] * c[w], u, v, w);
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    sort(a, a + n, greater<int>());
    sort(b, b + n, greater<int>());
    sort(c, c + n, greater<int>());

    priority_queue<State> pq;
    pq.push(proc(0, 0, 0));
    map<tuple<int, int, int>, int> mp;
    while (k > 1)
    {
        State tp = pq.top();
        mp[make_tuple(tp.u, tp.v, tp.w)] = 1;
        pq.pop();

        if (tp.u < n - 1 && mp[make_tuple(tp.u + 1, tp.v, tp.w)] == 0)
            pq.push(proc(tp.u + 1, tp.v, tp.w));
        if (tp.v < n - 1 && mp[make_tuple(tp.u, tp.v + 1, tp.w)] == 0)
            pq.push(proc(tp.u, tp.v + 1, tp.w));
        if (tp.w < n - 1 && mp[make_tuple(tp.u, tp.v, tp.w + 1)] == 0)
            pq.push(proc(tp.u, tp.v, tp.w + 1));
        k--;
    }

    cout << pq.top().val << '\n';
}
