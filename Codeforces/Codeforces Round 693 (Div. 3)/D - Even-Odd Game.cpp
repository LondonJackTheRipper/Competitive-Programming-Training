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
    priority_queue<int> even, odd;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (x % 2 == 0)
            even.push(x);
        else
            odd.push(x);
    }

    ll alice = 0, bob = 0;
    for (int i = 0; i < n; i++)
    {
        int player = i % 2;
        if (even.empty())
        {
            int x = odd.top();
            odd.pop();
            if (player == 1) bob += x;
        } else
        if (odd.empty())
        {
            int x = even.top();
            even.pop();
            if (player == 0) alice += x;
        } else
        {
            int x = even.top(), y = odd.top();

            if (x > y)
            {
                even.pop();
                if (player == 0) alice += x;
            } else
            {
                odd.pop();
                if (player == 1) bob += y;
            }
        }
    }

    if (alice == bob)
        cout << "Tie\n";
    else
        cout << (alice > bob ? "Alice\n" : "Bob\n");
}
