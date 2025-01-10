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

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int cnt = 0;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            while (!st.empty() && i - st.top() <= k)
                st.pop();
            st.push(i);
            cnt++;

            continue;
        }

        if (st.empty() || i - st.top() > k)
            st.push(i);
    }

    cout << st.size() - cnt << '\n';
}
