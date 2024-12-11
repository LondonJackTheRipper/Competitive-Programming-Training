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

    vector<int> cnt(26, 0);
    for (char c : s)
        cnt[c - 'a']++;
    int mx = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    int mn = mx;
    for (int i = 0; i < 26; i++)
        if (cnt[i] != 0 && cnt[i] <= cnt[mn])
            mn = i;

    bool get = false;
    for (char c : s)
    {
        int num = c - 'a';

        if (num == mn && get == false)
            cout << char(mx + 'a'), get = true;
        else
            cout << c;
    }
    cout << '\n';
}
