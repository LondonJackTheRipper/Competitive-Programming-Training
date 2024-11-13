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
    int n; cin >> n;

    vector<int> prefix;
    prefix.push_back(0);
    while (prefix.back() < n)
        prefix.push_back(prefix.back() + 5ll * (1ll << (prefix.size() - 1)));

    vector<string> res = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    cout << res[(n - prefix[prefix.size() - 2] - 1) / (1 << (prefix.size() - 2))] << '\n';
}
