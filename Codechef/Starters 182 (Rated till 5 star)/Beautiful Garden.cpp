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

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

// main program

void solve()
{
    int n, k, d; cin >> n >> k >> d;
    int t[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    sort(t + 1, t + n + 1);
    
    int num = 0;
    vector<int> die(n + 1, -1);
    for (int i = 1; i <= d; i++)
    {
        int rem = 0;
        for (int j = 1; j <= n; j++)
        {
            if (die[j] == -1)
                rem++;
            else
            if (die[j] + t[j] <= i)
            {
                die[j] = -1;
                rem++;
            }
        }
        
        if (rem > k)
        {
            for (int j = 1; j <= n; j++)
            {
                if (rem == k)
                    break;
                if (die[j] != -1)
                    continue;
                die[j] = i;
                rem--;
                num++;
            }
        }
    }
    
    cout << num << '\n';
}
