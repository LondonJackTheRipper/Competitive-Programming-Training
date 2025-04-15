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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int cnt = 0;
    for (char c : s)
        cnt += (c == 'o');
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == 'o')
            s[i] = '.';
        else
        if (s[i] == 'o' && s[i - 1] == '?')
            s[i - 1] = '.';
    }

    if (cnt == k)
    {
        for (char &c : s)
            if (c == '?')
                c = '.';
        cout << s << '\n';
        return;
    }

    cnt = k - cnt;
    int cur = 0, sum = 0;
    vector<pair<int, int>> proc;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
            cur++;
        else
        if (cur != 0)
        {
            proc.push_back({i - cur, cur});
            sum += ((cur + 1) / 2);
            cur = 0;
        }
    }
    if (cur != 0)
    {
        proc.push_back({n - cur, cur});
        sum += ((cur + 1) / 2);
    }

    for (pair<int, int> it : proc)
    {
        int rem = cnt - sum + ((it.second + 1) / 2);
        if (rem <= 0)
            continue;

        if (rem == ((it.second + 1) / 2) && it.second % 2 == 1)
        {
            s[it.first] = 'o';
            for (int i = it.first + 1; i < it.first + it.second; i++)
                s[i] = (s[i - 1] == 'o' ? '.' : 'o');
        }
    }
    cout << s << '\n';
}
