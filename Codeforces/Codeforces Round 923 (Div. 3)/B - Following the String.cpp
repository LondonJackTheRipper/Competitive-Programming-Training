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
    int n; cin >> n;
    vector<int> cnt(30, 0);

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;

        for (int j = 0; j < 26; j++)
            if (cnt[j] == x)
            {
                cout << char(j + 'a');
                cnt[j]++;
                break;
            }
    }
    cout << '\n';
}
