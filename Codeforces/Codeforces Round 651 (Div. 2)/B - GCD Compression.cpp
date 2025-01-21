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
    stack<pair<int, int>> even, odd;
    for (int i = 0; i < 2 * n; i++)
    {
        int x; cin >> x;
        if (x % 2 == 0)
            even.push({x, i + 1});
        else
            odd.push({x, i + 1});
    }
    if ((int)odd.size() % 2 == 1)
        odd.pop();
    else
        ((int)odd.size() > 0 ? odd.pop() : even.pop());
    ((int)odd.size() > 0 && (int)odd.size() % 2 == 1 ? odd.pop() : even.pop());

    while (!odd.empty())
    {
        int id1 = odd.top().second; odd.pop();
        int id2 = odd.top().second; odd.pop();

        cout << id1 << ' ' << id2 << '\n';
    }
    while (!even.empty())
    {
        int id1 = even.top().second; even.pop();
        int id2 = even.top().second; even.pop();

        cout << id1 << ' ' << id2 << '\n';
    }

}
