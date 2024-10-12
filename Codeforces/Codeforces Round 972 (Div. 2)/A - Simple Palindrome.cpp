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
    
	int t;
	cin >> t;
	while (t--) solve();

    return 0;
}

// main program
string str = "ueoai";

void solve()
{
	int n; cin >> n;
	
	int num = n / 5, rem = n % 5;
	for (int i = 0 ; i < rem; i++)
		for (int j = 0; j < num + 1; j++)
			cout << str[i];
	for (int i = rem; i < 5; i++)
		for (int j = 0; j < num; j++)
			cout << str[i];
	cout << '\n';
}
