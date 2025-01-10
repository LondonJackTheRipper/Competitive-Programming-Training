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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    int res = -1;
    while (l <= r)
    {
        int mid = l + r >> 1;

        ll points = a[mid].first;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (i == mid)
                continue;

            if (a[i].first > points)
            {
                flag = false;
                break;
            }
            points += a[i].first;
        }

        if (flag == true)
        {
            res = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }

    vector<int> ans;
    for (int i = res; i < n; i++)
        ans.push_back(a[i].second);
    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int x : ans)
        cout << x << ' ';
    cout << '\n';
}
