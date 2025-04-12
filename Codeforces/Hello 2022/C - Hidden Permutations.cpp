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
int n;

int ask(int i)
{
    cout << "? " << i << endl;
    int res; cin >> res;
    return res;
}

void rep(vector<int> res)
{
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    cout << endl;
    return;
}

void solve()
{
    cin >> n;

    vector<int> res(n + 1, -1);
    vector<int> prev;
    int st = 0;
    for (int i = 1; i <= n; i++)
    {
        if (res[i] != -1)
            continue;
        prev.push_back(ask(i));
        int tmp;
        while ((tmp = ask(i)) != prev[st])
            prev.push_back(tmp);
        prev.push_back(tmp);
        for (int j = st; j < (int)prev.size() - 1; j++)
            res[prev[j]] = prev[j + 1];
        st = (int)prev.size();
    }

    rep(res);
}
