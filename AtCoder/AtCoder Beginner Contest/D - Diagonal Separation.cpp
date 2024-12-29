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
struct P
{
    int x, y;
    char c;

    P() = default;
    P(int x, int y, char c) : x(x), y(y), c(c) {}

    bool operator < (const P& other) const
    {
        return c < other.c;
    }
};

struct SegmentTree
{
    int n;
    vector<int> st;

    SegmentTree(int n, vector<int>& arr) : n(n)
    {
        st.resize(4 * n + 5, 0);
        build(1, 0, n - 1, arr);
    }

    void build(int head, int l, int r, vector<int>& arr)
    {
        if (l == r)
        {
            st[head] = arr[l];
            return;
        }

        int mid = l + r >> 1;
        build(2 * head, l, mid, arr);
        build(2 * head + 1, mid + 1, r, arr);

        st[head] = max(st[2 * head], st[2 * head + 1]);
    }

    int query(int head, int l, int r, int u, int v)
    {
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return st[head];

        int mid = l + r >> 1;
        return max(query(2 * head, l, mid, u, v), query(2 * head + 1, mid + 1, r, u, v));
    }
    int query(int u, int v) { if (u > v) return 0; else return query(1, 0, n - 1, u, v); }
};

void solve()
{
    int n, m; cin >> n >> m;
    vector<P> points(m);
    int cnt = 0;
    for (P &it : points)
    {
        cin >> it.x >> it.y >> it.c;
        if (it.c == 'W')
            cnt++;
    }
    if (cnt == m)
    {
        cout << "Yes\n";
        return;
    }
    sort(points.begin(), points.end());

    map<int, int> rows, cols;
    for (P it : points)
    {
        if (it.c == 'W')
            break;

        rows[it.x] = max(rows[it.x], it.y);
        cols[it.y] = max(cols[it.y], it.x);
    }
    vector<int> r1, r2, c1, c2;
    for (auto it : rows)
    {
        r1.push_back(it.first);
        r2.push_back(it.second);
    }
    for (auto it : cols)
    {
        c1.push_back(it.first);
        c2.push_back(it.second);
    }

    SegmentTree st1(r2.size(), r2), st2(c2.size(), c2);
    for (P it : points)
    {
        if (it.c == 'B')
            continue;

        {
            int from = lower_bound(r1.begin(), r1.end(), it.x) - r1.begin();
            int mx = st1.query(from, r1.size() - 1);
            if (mx >= it.y)
            {
                cout << "No\n";
                return;
            }
        }
        {
            int from = lower_bound(c1.begin(), c1.end(), it.y) - c1.begin();
            int mx = st2.query(from, c1.size() - 1);
            if (mx >= it.x)
            {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
}
