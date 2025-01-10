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
bool flag = false;
void backtrack(int pos, int sum, vector<int>& cnt)
{
    if (pos == 3)
    {
        if (sum % 10 == 3)
            flag = true;
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        if (cnt[i] == 0) continue;
        cnt[i]--;
        backtrack(pos + 1, sum + i, cnt);
        cnt[i]++;
    }
}

void solve()
{
    int n; cin >> n;
    vector<int> cnt(10, 0);
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;

        cnt[x % 10]++;
    }

    flag = false;
    backtrack(0, 0, cnt);

    cout << (flag == true ? "YES\n" : "NO\n");
}
