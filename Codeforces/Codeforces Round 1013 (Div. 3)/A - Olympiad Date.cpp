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

void solve()
{
    int n; cin >> n;
    vector<int> cnt(10, 0);

    // 01032025
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        cnt[x]++;

        if (flag == false && cnt[0] >= 3 && cnt[1] >= 1 && cnt[2] >= 2 && cnt[3] >= 1 && cnt[5] >= 1)
        {
            cout << i << '\n';
            flag = true;
        }
    }
    if (flag == false)
        cout << 0 << '\n';
}
