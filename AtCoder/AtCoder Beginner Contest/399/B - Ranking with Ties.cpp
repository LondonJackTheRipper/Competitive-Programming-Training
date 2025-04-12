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
    int n; cin >> n;

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        int x; cin>> x;
        pq.push({x, i});
    }

    vector<int> ran(n + 1, 0);
    int r = 1;
    while (!pq.empty())
    {
        int x = pq.top().first, idx = pq.top().second;
        pq.pop();

        int k = 1;
        ran[idx] = r;
        while (!pq.empty() && pq.top().first == x)
        {
            k++;
            ran[pq.top().second] = r;
            pq.pop();
        }
        r += k;
    }

    for (int i = 0; i < n; i++)
        cout << ran[i] << '\n';
}
