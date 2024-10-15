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
    int n; cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        pq.push(x);
    }

    int Alice = 0, Bob = 0;
    int turns = 0;
    while (!pq.empty())
    {
        int u = pq.top();
        pq.pop();

        if (turns == 0)
            Alice += u;
        else
            Bob += u;
        turns ^= 1;
    }

    cout << Alice - Bob << '\n';
}
