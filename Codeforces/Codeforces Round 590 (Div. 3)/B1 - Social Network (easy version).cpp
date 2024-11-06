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
    int n, k; cin >> n >> k;
    unordered_map<int, int> freq;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (freq[x] > 0) continue;

        if (q.size() < k)
        {
            q.push(x);
            freq[x]++;
        }
        else
        {
            freq[q.front()]--;
            q.pop();
            q.push(x);
            freq[x]++;
        }
    }

    cout << q.size() << '\n';
    vector<int> res;
    while (!q.empty())
    {
        res.push_back(q.front());
        q.pop();
    }
    reverse(res.begin(), res.end());
    for (int x : res) cout << x << ' ';
    cout << '\n';
}
