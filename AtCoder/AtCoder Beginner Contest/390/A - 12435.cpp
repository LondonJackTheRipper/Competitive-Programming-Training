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
    vector<int> a(5);
    for (int &x : a) cin >> x;

    int op = false;
    for (int i = 1; i < 5; i++)
        if (a[i] < a[i - 1])
        {
            swap(a[i], a[i - 1]);
            op = true;
            break;
        }
    if (!op)
    {
        cout << "No\n";
        return;
    }

    for (int i = 1; i < 5; i++)
        if (a[i] < a[i - 1])
        {
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
}
