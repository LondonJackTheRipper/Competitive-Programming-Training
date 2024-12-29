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
    int k; cin >> k;
    string s, t; cin >> s >> t;

    if (s == t)
    {
        cout << "Yes\n";
        return;
    }
    if (abs((int)s.length() - (int)t.length()) > 1)
    {
        cout << "No\n";
        return;
    }
    if (s.length() == t.length())
    {
        int diff = 0;
        for (int i = 0; i < (int)s.length(); i++)
            diff += (s[i] != t[i]);
        cout << (diff > 1 ? "No\n" : "Yes\n");
        return;
    }
    if (s.length() < t.length()) swap(s, t);
    int used = 0;
    int j = 0;
    bool cc1 = true;
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (j >= (int)t.length()) continue;
        if (s[i] == t[j])
            j++;
        else
        if (used == 1)
        {
            cc1 = false;
        } else
            used = 1;
    }
    j = 0;
    bool cc2 = true;
    for (int i = 0; i < (int)t.length(); i++)
    {
        if (j >= (int)s.length()) continue;
        if (t[i] == s[j])
            j++;
        else
        if (used == 1)
        {
            cc2 = false;
        } else
        {
            used = 1;
            j++;
        }
    }

    cout << (cc1 == true || cc2 == true ? "Yes\n" : "No\n");
}
