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
    vector<int> fibo;
    fibo.push_back(0);
    fibo.push_back(1);
    while (fibo[fibo.size() - 2] < n - fibo[fibo.size() - 1])
        fibo.push_back(fibo[fibo.size() - 2] + fibo[fibo.size() - 1]);

    if (n == 0)
        cout << "0 0 0\n";
    else
    if (n == 1)
        cout << "0 0 1\n";
    else
    if (n == 2)
        cout << "0 1 1\n";
    else
        cout << fibo[fibo.size() - 1] << ' ' << fibo[fibo.size() - 3] << ' ' << fibo[fibo.size() - 4] << '\n';
}
