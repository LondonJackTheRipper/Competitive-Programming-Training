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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<vector<int>> cnt(k, vector<int>(26, 0));
    for (int st = 0; st < k; st++)
        for (int i = st; i < n; i += k)
            cnt[st][s[i] - 'a']++;

    int res = (k % 2 == 1 ? n / k - (*max_element(cnt[k / 2].begin(), cnt[k / 2].end())) : 0);
    int i = 0, j = k - 1;
    while (i < j)
    {
        vector<int> merge_cnt(26, 0);
        for (int it = 0; it < 26; it++)
            merge_cnt[it] = cnt[i][it] + cnt[j][it];

        res += 2 * (n / k) - (*max_element(merge_cnt.begin(), merge_cnt.end()));

        i++;
        j--;
    }

    cout << res << '\n';
}
