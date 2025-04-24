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

vector<vector<int>> digit =
{
    {1, 1, 1, 0, 1, 1, 1}, // 0
    {0, 0, 1, 0, 0, 1, 0}, // 1
    {1, 0, 1, 1, 1, 0, 1}, // 2
    {1, 0, 1, 1, 0, 1, 1}, // 3
    {0, 1, 1, 1, 0, 1, 0}, // 4
    {1, 1, 0, 1, 0, 1, 1}, // 5
    {1, 1, 0, 1, 1, 1, 1}, // 6
    {1, 0, 1, 0, 0, 1, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}, // 9
};

int convert(vector<int> v, int d)
{
    int res = 0;
    vector<int> tmp = digit[d];
    for (int i = 0; i < 7; i++)
        if (tmp[i] == 0 && v[i] == 1)
            return -1;
        else
            res += tmp[i] - v[i];
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> board[n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 7; j++)
        {
            char c; cin >> c;
            board[i].push_back(c - '0');
        }
    reverse(board + 1, board + n + 1);

    int dp[10][n + 1][k + 1], save[k + 1];
    memset(dp, 0, sizeof(dp));
    memset(save, 0, sizeof(save));
    dp[0][0][0] = save[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int d = 0; d < 10; d++)
        {
            int ops = convert(board[i], d);
            if (ops == -1)
                continue;
            for (int j = ops; j <= k; j++)
                dp[d][i][j] |= save[j - ops];
        }
        for (int j = 0; j <= k; j++)
        {
            save[j] = 0;
            for (int d = 0; d < 10; d++)
                save[j] |= dp[d][i][j];
        }
    }

    if (save[k] == 0)
    {
        cout << -1 << '\n';
        return;
    }

    string res = "";
    int ops = k;
    for (int i = n; i > 0; i--)
        for (int d = 9; d >= 0; d--)
            if (dp[d][i][ops] == 1)
            {
                res.push_back(char(d + '0'));
                ops -= convert(board[i], d);
                break;
            }
    cout << res << '\n';
}
