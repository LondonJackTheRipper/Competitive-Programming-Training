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
    vector<int> cnt(4, 0);
    for (int i = 0; i < 6; i++)
    {
        char c; cin >> c;
        cnt[c - '0']++;
    }

    cout << (cnt[1] == 1 && cnt[2] == 2 && cnt[3] == 3 ? "Yes\n" : "No\n");
}
