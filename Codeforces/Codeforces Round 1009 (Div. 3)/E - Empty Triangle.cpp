#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int random(int l, int r) {
    uniform_int_distribution<int> dist(l, r);
    return dist(rd);
}

int ask(int i, int j, int k)
{
    cout << "? " << i << ' ' << j << ' ' << k << endl;
    int p; cin >> p;
    return p;
}

void rep(int i, int j, int k)
{
    cout << "! " << i << ' ' << j << ' ' << k << endl;
}

void solve()
{
    int n; cin >> n;

    vector<int> ver = {1, 2, 3};
    int middle = ask(1, 2, 3);
    while (middle != 0)
    {
        int idx = random(0, 2);
        ver[idx] = middle;
        middle = ask(ver[0], ver[1], ver[2]);
    }

    rep(ver[0], ver[1], ver[2]);
}
