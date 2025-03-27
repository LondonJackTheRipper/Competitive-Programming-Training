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
const int maxn = 2e5;

int n, q;
ll x[maxn + 1], ans[maxn + 1];

struct State
{
    ll x, y, w;

    State(ll x, ll y, ll w) : x(x), y(y), w(w) {}
    bool operator > (const State& other) const
    {
        return w > other.w;
    }
};

void solve()
{
    cin >> n >> q;
    priority_queue<State, vector<State>, greater<State>> pq;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];

        if (i != 1)
            pq.push({i - 1, i, x[i] - x[i - 1]});
    }

    vector<ll> dir(2, 0);
    ll pre = 0;
    while (q--)
    {
        ll w; cin >> w;

        int turns = (w < 0 ? 0 : 1);
        pre += w;
        if ((pre < 0 && turns == 0) || (pre > 0 && turns == 1))
            dir[turns] = max(dir[turns], abs(pre));

        while (!pq.empty() && pq.top().w < dir[0] + dir[1])
        {
            int x = pq.top().x, y = pq.top().y;
            ll val = pq.top().w;
            pq.pop();

            ans[x] += (turns == 0 ? dir[1] : min(val - dir[0], dir[1]));
            ans[y] += (turns == 0 ? min(val - dir[1], dir[0]) : dir[0]);
        }
    }
    while (!pq.empty())
    {
        ans[pq.top().x] += dir[1];
        ans[pq.top().y] += dir[0];
        pq.pop();
    }
    ans[1] += dir[0];
    ans[n] += dir[1];

    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
    cout << '\n';
}
