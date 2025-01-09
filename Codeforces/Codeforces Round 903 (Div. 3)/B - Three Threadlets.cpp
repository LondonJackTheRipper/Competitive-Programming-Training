#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

string name = "test";

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

void solve()
{
    priority_queue<int> pq;
    int mn = 1e9;
    for (int i = 0; i < 3; i++)
    {
        int x; cin >> x;

        mn = min(mn, x);
        pq.push(x);
    }

    for (int i = 0; i < 3; i++)
    {
        int tp = pq.top();
        pq.pop();

        if (tp == mn)
        {
            cout << "YES\n";
            return;
        }
        pq.push(mn);
        pq.push(tp - mn);
        mn = min(mn, tp - mn);
    }

    cout << (pq.top() == mn ? "YES\n" : "NO\n");
}
