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
    string s; cin >> s;

    vector<int> res(n, 0), cnt(2, 0);
    queue<int> mark[2];
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        int num = s[i] - '0';

        if (cnt[num ^ 1] != 0)
        {
            cnt[num ^ 1]--;
            res[i] = mark[num ^ 1].front();
            mark[num].push(res[i]);
            mark[num ^ 1].pop();
            cnt[num]++;
        } else
        {
            mark[num].push(++cur);
            res[i] = cur;
            cnt[num]++;
        }
    }

    cout << cur << '\n';
    for (int i = 0; i < n; i++)
        cout << res[i] << ' ';
    cout << '\n';
}
