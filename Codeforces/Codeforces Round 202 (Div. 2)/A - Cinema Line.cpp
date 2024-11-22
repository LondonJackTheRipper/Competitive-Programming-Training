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

    vector<int> cnt(3, 0);
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;

        if (x == 25)
            cnt[0]++;
        else
        if (x == 50)
        {
            if (cnt[0] == 0)
            {
                cout << "NO\n";
                return;
            }
            cnt[1]++;
            cnt[0]--;
        } else
        {
            if (cnt[1] > 0 && cnt[0] > 0)
            {
                cnt[1]--;
                cnt[0]--;
            } else
            if (cnt[0] > 2)
                cnt[0] -= 3;
            else
            {
                cout << "NO\n";
                return;
            }
            cnt[2]++;
        }
    }

    cout << "YES\n";
}
