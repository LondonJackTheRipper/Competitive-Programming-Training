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
const int maxn = 5e5 + 9;

struct state
{
    int pos, num, id;

    state(int pos, int num, int id) : pos(pos), num(num), id(id) {}
};

int n;
string t;
string str[maxn];

void process(vector<int>& res)
{
    queue<state> q;
    for (int i = 0; i < n; i++)
        q.push({0, 0, i});
    int total = n;
    for (char c : t)
    {
        int tmp = total;
        while (tmp > 0)
        {
            state cc = q.front();
            q.pop();
            while (cc.pos < (int)str[cc.id].length() && str[cc.id][cc.pos] != c)
                cc.pos++;
            if (cc.pos == (int)str[cc.id].length())
                total--;
            else
            {
                cc.pos++;
                cc.num++;
                q.push(cc);
            }
            res[cc.id] = cc.num;
            tmp--;
        }
    }
}

void solve()
{
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> str[i];

    vector<int> pre(n, 0);
    process(pre);
    reverse(t.begin(), t.end());
    for (int i = 0; i < n; i++)
        reverse(str[i].begin(), str[i].end());
    vector<int> suff(n, 0);
    process(suff);
    sort(suff.begin(), suff.end());

    ll res = 0;
    for (int x : pre)
    {
        int pos = lower_bound(suff.begin(), suff.end(), (int)t.length() - x) - suff.begin();

        res += n - pos;
    }

    cout << res << '\n';
}
