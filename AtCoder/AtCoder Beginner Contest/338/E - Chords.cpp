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
const int maxn = 2e5 + 9;

int lg[maxn];
void init()
{
    lg[1] = 0;
    for (int i = 2; i <= (int)2e5; i++)
        lg[i] = lg[i / 2] + 1;
}

int sp[20][maxn];

int seg(int l, int r)
{
    if (l > r) return 0;
    int LG = lg[r - l + 1];
    return max(sp[LG][l], sp[LG][r - (1 << LG) + 1]);
}

void solve()
{
    init();
    int n; cin >> n;
    vector<pair<int, int>> points(n);
    for (pair<int, int> &it : points)
    {
        cin >> it.first >> it.second;
        if (it.first > it.second)
            swap(it.first, it.second);
    }

    // sparse table
    sort(points.begin(), points.end());
    vector<int> cop;
    for (int i = 0; i < n; i++)
        cop.push_back(points[i].first);
    for (int i = 0; i < n; i++)
        sp[0][i] = points[i].second;
    for (int j = 1; j < 20; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            sp[j][i] = max(sp[j - 1][i], sp[j - 1][i + (1 << (j - 1))]);
    //

    for (pair<int, int> it : points)
    {
        int pos1 = upper_bound(cop.begin(), cop.end(), it.first) - cop.begin();
        int pos2 = upper_bound(cop.begin(), cop.end(), it.second) - cop.begin();

        int mx = seg(pos1, pos2 - 1);
        if (mx > it.second)
        {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}
