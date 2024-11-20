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
    string s; cin >> s;
    vector<int> cnt(30, 0);
    for (char c : s) cnt[c - 'a']++;

    int sum = 0, odd = 0;
    for (int i = 0; i < 26; i++)
    {
        odd += (cnt[i] & 1);
        sum += (cnt[i] == 1);
    }
    if (odd <= 1)
    {
        cout << "First\n";
        return;
    }

    if (sum == (int)s.length())
        cout << ((sum & 1) ? "First\n" : "Second\n");
    else
    {
        if ((int)s.length() == 2)
        {
            cout << "First\n";
            return;
        }
        cout << (((int)s.length() - 3) & 1 ? "Second\n" : "First\n");
    }
}
