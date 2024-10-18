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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string dir = "LRUD";

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    map<pair<int, int>, int> last;
    pair<int, int> pre = {0, 0};
    last[{0, 0}] = 1;
    int fi, res = 1e9;
    for (int i = 1; i <= n; i++)
    {
        pre.first = pre.first + dx[dir.find(s[i - 1])];
        pre.second = pre.second + dy[dir.find(s[i - 1])];
        int &prev = last[{pre.first, pre.second}];
        if (prev != 0 && i - prev + 1 < res)
        {
            res = i - prev + 1;
            fi = prev;
        }
        prev = i + 1;
    }

    if (res == 1e9)
        cout << -1 << '\n';
    else
        cout << fi << ' ' << fi + res - 1 << '\n';
}
