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
const int mod = 1e9 + 7;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
int mul(int a, int b) { return 1ll * a * b % mod; }

struct Matrix
{
    vector<vector<int>> data;

    int row() { return data.size(); }
    int col() { return data[0].size(); }

    Matrix() = default;
    Matrix(int r, int c) : data(r, vector<int>(c, 0)) {}
    Matrix(vector<vector<int>> d) : data(d) {}

    static Matrix identity(int n)
    {
        Matrix a(n, n);
        while (n--)
            a.data[n][n] = 1;
        return a;
    }

    Matrix operator * (Matrix &b)
    {
        Matrix a = *this;
        Matrix ans = Matrix(a.row(), b.col());

        for (int i = 0; i < a.row(); i++)
            for (int j = 0; j < b.col(); j++)
                for (int k = 0; k < a.col(); k++)
                    ans.data[i][j] = add(ans.data[i][j], mul(a.data[i][k], b.data[k][j]));

        return ans;
    }

    Matrix power(ll exp)
    {
        Matrix base = *this;
        Matrix ans = identity(row());

        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1)
                ans = ans * base;

        return ans;
    }
};

void solve()
{
    ll n; cin >> n;

    if (n < 2)
    {
        cout << (n == 0 ? 0 : 1) << '\n';
        return;
    }

    Matrix a = Matrix(vector<vector<int>>{{0}, {1}}), i = Matrix(vector<vector<int>>{{0, 1}, {1, 1}}).power(n - 1);

    Matrix ans = i * a;
    cout << ans.data[1][0] << '\n';
}
