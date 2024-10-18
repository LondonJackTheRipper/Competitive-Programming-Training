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

void solve()
{
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    priority_queue<int, vector<int>, greater<int>> pq;
    ll cur = 0;

    for (int i = 1; i <= n; i++)
    {
        cur += a[i];
        pq.push(a[i]);

        while (cur < 0)
        {
            cur -= pq.top();
            pq.pop();
        }
    }

    cout << pq.size() << '\n';
}