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
    int q; cin >> q;

    vector<int> a;
    bool flag = false;
    while (q--)
    {
        int x; cin >> x;

        if (a.empty())
        {
            a.push_back(x);
            cout << 1;
            continue;
        }

        int sz = a.size();
        if (flag == false)
        {
            if (x >= a.back())
                a.push_back(x);
            else
            if (x <= a[0])
            {
                a.push_back(x);
                flag = true;
            }
        } else
            if (x >= a.back() && x <= a[0])
                a.push_back(x);

        cout << (sz == (int)a.size() ? 0 : 1);
    }
    cout << '\n';
}
