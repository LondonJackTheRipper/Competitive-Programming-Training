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

bool non_degenerate(int a, int b, int c) { return a + b > c && b + c > a && a + c > b; }
bool degenerate(int a, int b, int c) { return a + b == c || a + c == b || b + c == a; }

void solve()
{
    vector<int> sticks(4);
    for (int &x : sticks) cin >> x;

    bool not_degenerate = false, is_degenerate = false;
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
        {
            vector<int> rem;
            for (int k = 0; k < 4; k++)
                if (k != i && k != j)
                    rem.push_back(sticks[k]);

            if (non_degenerate(rem[0], rem[1], sticks[i]) || non_degenerate(rem[0], rem[1], sticks[j])) not_degenerate = true;
            if (degenerate(rem[0], rem[1], sticks[i]) || degenerate(rem[0], rem[1], sticks[j])) is_degenerate = true;
        }

    if (not_degenerate)
    {
        cout << "TRIANGLE\n";
        return;
    }
    if (is_degenerate)
    {
        cout << "SEGMENT\n";
        return;
    }
    cout << "IMPOSSIBLE\n";
}
