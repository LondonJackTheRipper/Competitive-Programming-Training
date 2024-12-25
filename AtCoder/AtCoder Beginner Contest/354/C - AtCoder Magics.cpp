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
struct Card
{
    int a, c, id;

    Card() = default;
    Card(int a, int c, int id) : a(a), c(c), id(id) {};

    bool operator < (const Card& other) const
    {
        return a < other.a;
    }
};

void solve()
{
    int n; cin >> n;
    vector<Card> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].a >> arr[i].c;
        arr[i].id = i + 1;
    }

    sort(arr.begin(), arr.end());
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        int c = arr[i].c;

        while (!pq.empty() && pq.top().first > c)
            pq.pop();

        pq.push({c, arr[i].id});
    }

    vector<int> res;
    while (!pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    for (int x : res) cout << x << ' ';
    cout << '\n';
}
