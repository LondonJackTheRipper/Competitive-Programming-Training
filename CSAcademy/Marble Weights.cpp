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
int ask(int a, int b)
{
    cout << "Q 2 " << a << ' ' << b << endl;
    int res; cin >> res;
    return res;
}

void rep(vector<int> ans)
{
    cout << "A ";
    for (int x : ans) cout << x << ' ';
    cout << endl;
}

void solve()
{
    int n; cin >> n;
    
    int xy = ask(1, 2), yz = ask(2, 3), xz = ask(1, 3);
    vector<int> ans;
    ans.push_back((xy + xz - yz) / 2);
    ans.push_back((xy + yz - xz) / 2);
    ans.push_back((xz + yz - xy) / 2);
    for (int i = 4; i <= n; i++)
    {
        int res = ask(1, i);
        ans.push_back(res - ans[0]);
    }
    
    rep(ans);
}
