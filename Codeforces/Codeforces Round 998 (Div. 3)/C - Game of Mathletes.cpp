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
    vector<int> cards(n);
    for (int &x : cards)
        cin >> x;

    sort(cards.begin(), cards.end());
    int res = 0;
    int last = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (i >= last)
            break;

        while (i < last && cards[i] + cards[last] > k)
            last--;

        if (i < last && cards[i] + cards[last] == k)
        {
            res++;
            last--;
        }
    }

    cout << res << '\n';
}
