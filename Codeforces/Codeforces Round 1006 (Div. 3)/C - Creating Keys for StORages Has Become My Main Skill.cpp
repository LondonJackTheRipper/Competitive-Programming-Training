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
    int n, x; cin >> n >> x;

    int MEX = 1e9, OR = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int bit = 0; bit < 30; bit++)
            if (!(x >> bit & 1) && (i >> bit & 1) && MEX == (int)1e9)
                MEX = i;
        OR |= i;
    }

    vector<int> ans;
    if (MEX != (int)1e9)
    {
        for (int i = 0; i < MEX; i++)
            ans.push_back(i);
        while ((int)ans.size() < n)
            ans.push_back(x);
    } else
    {
        for (int i = 0; i < n - 1; i++)
            ans.push_back(i);
        if ((OR | (n - 1)) == x)
            ans.push_back(n - 1);
        else
            ans.push_back(x);
    }
    for (int val : ans)
        cout << val << ' ';
    cout << '\n';
}
