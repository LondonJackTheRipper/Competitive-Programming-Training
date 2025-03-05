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
const int mod = 998244353;

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
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m, 0)), b(m, vector<int>(k, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            cin >> b[i][j];

    Matrix A = Matrix(a), B = Matrix(b);
    Matrix C = A * B;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            cout << C.data[i][j] << (j == k - 1 ? '\n' : ' ');
}
