#include <bits/stdc++.h>
using namespace std;

/*
  Ben Watson
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
const int maxn = 2e5 + 1;

int n;
int r[maxn], cycles[maxn];
vector<int> rev[maxn];

int DFS(int u, int p = -1)
{
    int res = 1;
    for (int v : rev[u])
    {
        if (v == p)
            continue;
        res += DFS(v, u);
    }
    return res;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        rev[i].clear();
        cycles[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
        rev[r[i]].push_back(i);
    }

    int times = 0;
    vector<int> mark(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] != 0)
            continue;

        int ver = i;
        times++;
        stack<int> st;
        while (mark[ver] == 0)
        {
            st.push(ver);
            mark[ver] = times;
            ver = r[ver];
        }
        if (mark[ver] == times)
        {
            int base = ver;
            cycles[base] = 1;
            while (st.top() != base)
            {
                cycles[st.top()] = 1;
                st.pop();
            }
        }
    }

    int res = 2;
    for (int i = 1; i <= n; i++)
    {
        if (cycles[i] == 0)
            continue;

        for (int v : rev[i])
            if (cycles[v] == 0)
                res = max(res, 2 + DFS(v, i));
    }

    cout << res << '\n';
}
