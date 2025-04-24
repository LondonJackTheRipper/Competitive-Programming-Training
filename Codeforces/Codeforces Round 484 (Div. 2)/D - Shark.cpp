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
const int maxn = 1e5 + 1;

struct FenwickTree
{
    int n;
    vector<int> bits;

    FenwickTree(int n) : n(n) { bits.resize(n + 1, 0); }

    void update(int pos, int val)
    {
        for (; pos <= n; pos += (pos & (-pos)))
            bits[pos] += val;
    }

    int query(int pos)
    {
        int res = 0;
        for (; pos > 0; pos -= (pos & (-pos)))
            res += bits[pos];
        return res;
    }
    int query(int l, int r) { return query(r) - query(l - 1); }
};

int n, cnt;
int a[maxn];
vector<int> segment(maxn, 0);
FenwickTree bit(maxn + 3);

int lower_pos(int pos)
{
    int l = 0, r = pos - 1;
    int res = -1;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (bit.query(mid + 1, pos + 1) > 0)
        {
            res = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return res;
}

int upper_pos(int pos)
{
    int l = pos + 1, r = n + 1;
    int res = -1;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (bit.query(pos + 1, mid + 1) > 0)
        {
            res = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return res;
}

void solve()
{
    cin >> n;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    // Preset
    cnt = 1;
    segment[n] = 1;
    bit.update(1, 1);
    bit.update(n + 2, 1);
    int k = (int)1e9, locations = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({n, 1});

    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        int num = it->first;
        while (segment[pq.top().first] != pq.top().second)
            pq.pop();
        if (cnt - segment[0] == segment[pq.top().first] && cnt - segment[0] >= locations)
        {
            locations = cnt - segment[0];
            k = num + 1;
        }

        for (int pos : it->second)
        {
            int l = lower_pos(pos), r = upper_pos(pos);
            segment[r - l - 1]--;
            if (segment[r - l - 1])
                pq.push({r - l - 1, segment[r - l - 1]});
            segment[pos - l - 1]++;
            pq.push({pos - l - 1, segment[pos - l - 1]});
            segment[r - pos - 1]++;
            pq.push({r - pos - 1, segment[r - pos - 1]});
            cnt++;
            bit.update(pos + 1, 1);
        }
    }

    cout << k << '\n';
}
