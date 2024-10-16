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
int ask(int x)
{
    cout << "Q " << x << endl;
    int res; cin >> res;
    return res;
}

void rep(int x) 
{
    cout << "A " << x << endl;
}

void solve()
{
    int n; cin >> n;
    
    int l = 1, r = n;
    int res = -1;
    while (l <= r)
    {
        int mid = l + r >> 1;
        
        int ans = ask(mid);
        if (ans == 0)
        {
            res = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    
    rep(res);
}
