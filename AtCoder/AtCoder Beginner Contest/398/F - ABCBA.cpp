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
vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve()
{
    string s; cin >> s;
    int n = (int)s.length();

    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    for (char c : s)
        tmp.push_back(c);

    vector<int> v = prefix_function(tmp);
    int res = v[2 * n - 1];

    if (n == res)
    {
        cout << s << '\n';
        return;
    }

    cout << s;
    for (int i = n - res - 1; i >= 0; i--)
        cout << s[i];
    cout << '\n';
}
