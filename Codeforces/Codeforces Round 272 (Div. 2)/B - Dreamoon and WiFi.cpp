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
const int maxn = 11;
int C[maxn][maxn];

void init(int n)
{
    for (int i = 0; i <= n; i++) C[i][i] = C[0][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            C[j][i] = C[j][i - 1] + C[j - 1][i - 1];
}

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}

void solve()
{
    init(10);
    string s1, s2; cin >> s1 >> s2;
    int left = 0, expect = 0;
    for (char c : s1)
        expect += (c == '+' ? 1 : -1);
    for (char c : s2)
    {
        if (c != '?') expect -= (c == '+' ? 1 : -1);
        left += (c == '?');
    }

    if ((left + expect < 0) || (left + expect) % 2 == 1)
    {
        cout << fixed << setprecision(9) << (long double)0 << '\n';
        return;
    }

    int total = power(2, left);
    int fraction = C[left + expect >> 1][left];

    cout << fixed << setprecision(9) << (long double)fraction / total << '\n';
}
