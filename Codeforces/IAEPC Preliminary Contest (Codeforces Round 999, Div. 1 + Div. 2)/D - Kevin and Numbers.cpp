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
int ops;
bool CanCreate(int x, map<int, int>& mp)
{
    if (ops < 0)
        return false;
    if (mp[x])
    {
        mp[x]--;
        return true;
    } else
    {
        int u = x / 2, v = x - u;
        ops--;
        return (CanCreate(u, mp) && CanCreate(v, mp));
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x]++;
    }
    vector<int> b;
    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;

        if (mp[x])
            mp[x]--;
        else
            b.push_back(x);
    }

    ops = n - m;
    for (int x : b)
        if (!CanCreate(x, mp))
        {
            cout << "No\n";
            return;
        }

    cout << (ops == 0 ? "Yes\n" : "No\n");
}
