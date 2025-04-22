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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> pos;
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            pos.push_back(i);
    if (!pos.empty())
    {
        if (n - pos.back() - 1 <= k)
        {
            k -= n - pos.back() - 1;
            swap(s[n - 1], s[pos.back()]);
            pos[(int)pos.size() - 1] = n - 1;
        }
        if (pos[0] != n - 1 && pos[0] <= k)
        {
            k -= pos[0];
            swap(s[0], s[pos[0]]);
        }
    }

    int res = 0;
    for (int i = 1; i < n; i++)
        res += stoi(s.substr(i - 1, 2));
    cout << res << '\n';
}
