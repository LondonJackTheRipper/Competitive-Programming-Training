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
int ask(int x, int n)
{
    cout << "Q ";
    for (int i = 0; i < n; i++) cout << x; 
    cout << endl;
    int res; cin >> res;
    return res;
}

void solve()
{
    int n; cin >> n;
    
    int sum = 0;
    vector<int> cnt(10, 0);
    for (int i = 9; i > 0; i--)
    {
        cnt[i] = ask(i, n);
        sum += cnt[i];
    }
    cnt[0] = n - sum;
        
    cout << "A ";
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < cnt[i]; j++)
            cout << i;
    }
    cout << endl;
}
