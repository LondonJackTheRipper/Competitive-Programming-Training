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
pair<int, int> convert(string s) // 0, 1
{
    int n = (int)s.length();
    if (n == 3)
    {
        vector<int> cnt(2, 0);
        cnt[s[0] - '0']++;
        cnt[s[1] - '0']++;
        cnt[s[2] - '0']++;
        return make_pair(cnt[0] >= 2 ? 0 : 2 - cnt[0], cnt[1] >= 2 ? 0 : 2 - cnt[1]);
    }
    vector<pair<int, int>> res(3);
    res[0] = convert(s.substr(0, n / 3));
    res[1] = convert(s.substr(n / 3, n / 3));
    res[2] = convert(s.substr(2 * (n / 3), n / 3));

    vector<int> cnt[2];
    for (int i = 0; i < 3; i++)
    {
        cnt[0].push_back(res[i].first);
        cnt[1].push_back(res[i].second);
    }
    sort(cnt[0].begin(), cnt[0].end());
    sort(cnt[1].begin(), cnt[1].end());

    return make_pair(cnt[0][0] + cnt[0][1], cnt[1][0] + cnt[1][1]);
}

void solve()
{
    int n; cin >> n;
    string a; cin >> a;

    string tmp = a;
    while ((int)tmp.size() != 1)
    {
        string cur = "";
        for (int i = 2; i < (int)tmp.size(); i += 3)
        {
            vector<int> cnt(2, 0);
            cnt[tmp[i] - '0']++;
            cnt[tmp[i - 1] - '0']++;
            cnt[tmp[i - 2] - '0']++;

            cur.push_back(cnt[0] >= 2 ? '0' : '1');
        }
        tmp = cur;
    }
    int num = tmp[0] - '0';

    pair<int, int> res = convert(a);

    cout << (num == 0 ? res.second : res.first) << '\n';
}
