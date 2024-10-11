#include<bits/stdc++.h>

using namespace std;

#define ll long long

string name = "test";

void solve();
signed main()
{
    if (fopen((name + ".INP").c_str(), "r"))
    {
        freopen((name + ".INP").c_str(), "r", stdin);
        freopen((name + ".OUT").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}

// main program
const int maxn = 2e5 + 9;

int m[maxn];
int n;

void solve()
{
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> m[i];
		sum += m[i];
	}
	sort(m + 1, m + n + 1, greater<int>());

    int higher = sum % n;
    int div = sum / n + 1;
    int ans = 0;
    for (int i = 1; i <= higher; i++)
        ans += max(0, m[i] - div);
    for (int i = higher + 1; i <= n; i++)
        ans += max(0, m[i] - (div - 1));
    cout << ans << '\n';
}

