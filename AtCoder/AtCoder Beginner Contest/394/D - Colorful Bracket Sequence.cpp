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
    string s; cin >> s;

    string frame = "(<[", str = ")>]";
    stack<char> st;
    for (char c : s)
    {
        if (frame.find(c) != string::npos)
            st.push(c);
        else
        {
            if (!st.empty() && st.top() == frame[str.find(c)])
                st.pop();
            else
                st.push(c);
        }
    }

    cout << (st.empty() ? "Yes\n" : "No\n");
}
