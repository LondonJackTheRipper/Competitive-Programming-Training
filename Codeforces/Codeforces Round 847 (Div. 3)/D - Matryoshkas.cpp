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
int proc(vector<int> a)
{
    int prev = -1;
    int res = 0;
    for (int x : a)
    {
        if (x != prev + 1 && prev != -1)
            res++;

        prev = x;
    }

    return res + 1;
}

void solve()
{
    int n; cin >> n;
    map<int, int> mp;
    vector<int> arr[n];
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;

        arr[mp[x]++].push_back(x);
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].empty())
            break;

        sort(arr[i].begin(), arr[i].end());
        res += proc(arr[i]);
    }

    cout << res << '\n';
}
