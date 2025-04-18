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

void solve()
{
    int q; cin >> q;

    stack<int> st;
    for (int i = 0; i < 100; i++)
        st.push(0);
    while (q--)
    {
        int type; cin >> type;

        if (type == 2)
        {
            cout << st.top() << '\n';
            st.pop();
        } else
        {
            int x; cin >> x;
            st.push(x);
        }
    }
}
