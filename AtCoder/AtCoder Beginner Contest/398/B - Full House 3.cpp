#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
    vector<int> cnt(15, 0);
    for (int i = 0; i < 7; i++)
    {
        int x; cin >> x;
        cnt[x]++;
    }

    sort(cnt.begin(), cnt.end(), greater<int>());
    cout << (cnt[0] >= 3 && cnt[1] >= 2 ? "Yes\n" : "No\n");
}
