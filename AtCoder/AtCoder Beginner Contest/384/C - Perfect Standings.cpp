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
string tmp = "ABCDE";

vector<int> p(5);
vector<pair<int, string>> str;
int points;
string s;

void backtrack(int pos)
{
    if (pos == 5)
    {
        str.push_back({points, s});
        return;
    }

    backtrack(pos + 1);

    s += tmp[pos];
    points += p[pos];
    backtrack(pos + 1);
    points -= p[pos];
    s.pop_back();
}

bool cmp(pair<int, string> a, pair<int, string> b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

void solve()
{
    for (int &x : p) cin >> x;

    backtrack(0);

    sort(str.begin(), str.end(), cmp);
    for (pair<int, string> it : str)
        cout << it.second << '\n';
}
