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
const int maxv = 200009;

int pos[maxv];
vector<int> lpf, primes;
void linear(int n)
{
    lpf.resize(n + 1, 0);

    for (int i = 2; i <= n; i++)
    {
        if (lpf[i] == 0)
        {
            primes.push_back(i);
            lpf[i] = i;
        }
        for (int p : primes)
        {
            if (i > n / p || p > lpf[i]) break;

            lpf[i * p] = p;
        }
    }

    for (int i = 0; i < primes.size(); i++)
        pos[primes[i]] = i;
}

void solve()
{
    linear(200000);
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    priority_queue<int, vector<int>, greater<int>> small[primes.size() + 2];

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1) continue;
        int x = lpf[a[i]], cnt = x; a[i] /= x;
        while (a[i] != 1)
        {
            if (lpf[a[i]] == x)
                cnt *= x;
            else
            {
                small[pos[x]].push(cnt);
                cnt = lpf[a[i]];
                x = lpf[a[i]];
            }
            a[i] /= x;
        }
        small[pos[x]].push(cnt);
    }

    ll res = 1;
    for (int i = 0; i < primes.size(); i++)
    {
        if (small[i].size() == n)
        {
            small[i].pop();
            res *= small[i].top();
        } else
            res *= (small[i].size() == n - 1 ? small[i].top() : 1);
    }

    cout << res << '\n';
}
