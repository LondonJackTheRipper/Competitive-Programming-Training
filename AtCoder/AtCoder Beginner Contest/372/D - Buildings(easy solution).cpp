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

void solve()
{
    int n; cin >> n;
    int h[n], res[n];
    for (int i = 0; i < n; i++) cin >> h[i];

    stack<int> st;
    res[n - 1] = 0;
    st.push(h[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        res[i] = st.size();

        while (!st.empty() && h[i] > st.top())
            st.pop();
        st.push(h[i]);
    }

    for (int i = 0; i < n; i++)
        cout << res[i] << ' ';
    cout << '\n';
}
