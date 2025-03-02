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
    int n, q; cin >> n >> q;
    vector<int> nest(n + 1, 0), pos_nest(n + 1, 0), pigeon(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pigeon[i] = nest[i] = pos_nest[i] = i;

    while (q--)
    {
        int type; cin >> type;

        if (type == 1)
        {
            int a, b; cin >> a >> b;

            pigeon[a] = pos_nest[b];
        } else
        if (type == 2)
        {
            int a, b; cin >> a >> b;

            nest[pos_nest[a]] = b;
            nest[pos_nest[b]] = a;
            swap(pos_nest[a], pos_nest[b]);
        } else
        {
            int a; cin >> a;

            cout << nest[pigeon[a]] << '\n';
        }
    }
}
