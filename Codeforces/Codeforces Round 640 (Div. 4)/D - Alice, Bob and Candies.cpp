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
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    int i = 2, j = n, alice = a[1], bob = 0, prev_alice = a[1], prev_bob = 0, moves = 1, turns = 1;
    while (i <= j)
    {
        if (turns == 0)
        {
            int sum = 0;
            while (i <= j && sum <= prev_bob) sum += a[i++];
            alice += sum;
            prev_alice = sum;
        } else
        {
            int sum = 0;
            while (i <= j && sum <= prev_alice) sum += a[j--];
            bob += sum;
            prev_bob = sum;
        }

        moves++;
        turns ^= 1;
    }

    cout << moves << ' ' << alice << ' ' << bob << '\n';
}
