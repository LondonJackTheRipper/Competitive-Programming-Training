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
    int n, k; cin >> n >> k;
    set<int> se;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        se.insert(x);
    }

    if (se.size() > k)
    {
        cout << -1 << '\n';
        return;
    }

    vector<int> proc;
    for (int x : se) proc.push_back(x);
    while (proc.size() < k) proc.push_back(proc.front());

    cout << n * k << '\n';
    for (int i = 0; i < n; i++)
        for (int x : proc)
            cout << x << ' ';
    cout << '\n';
}
