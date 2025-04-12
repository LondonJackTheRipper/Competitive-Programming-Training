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
vector<int> lpf, primes;
void linear(int n)
{
    lpf.resize(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        if (lpf[i] == 0)
        {
            lpf[i] = i;
            primes.push_back(i);
        }

        for (int p : primes)
        {
            if (p > lpf[i] || 1ll * p * i > n)
                break;
            lpf[p * i] = p;
        }
    }
}

void solve()
{
    int q; cin >> q;
    vector<pair<ll, int>> qr;
    for (int i = 0; i < q; i++)
    {
        ll a; cin >> a;
        qr.push_back({a, i});
    }
    vector<ll> res(q);
    sort(qr.begin(), qr.end());

    linear(1e6);
    int idx = 1, ans = 36;
    for (int i = 0; i < q; i++)
    {
        ll lim = qr[i].first;
        while (1ll * (idx + 1) * (idx + 1) <= lim)
        {
            idx++;
            int cnt = 1, prev = lpf[idx], tmp = idx;
            while (lpf[tmp] != 0)
            {
                cnt += (lpf[tmp] != prev);
                prev = lpf[tmp];
                tmp /= lpf[tmp];
            }
            if (cnt == 2)
                ans = idx;
        }

        res[qr[i].second] = 1ll * ans * ans;
    }

    for (int i = 0; i < q; i++)
        cout << res[i] << '\n';
}
