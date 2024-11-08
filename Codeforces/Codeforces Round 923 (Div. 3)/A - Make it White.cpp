#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pll pair<long long, long long>
#define vll vector<long long>
#define lui long unsigned int
#define vs vector<string>
#define pi pair<int, int>
#define vc vector<char>
#define vi vector<int>
#define ll long long
#define pb push_back

void input()
{
	int n; cin >> n;
	cin.ignore();
	string s; getline(cin, s);
	int f = -1, l = -1;
	
	for (int i = 0; i < s.length(); i++) if (s[i] == 'B')
	{
		if (f == -1) f = i;
		l = i;
	}
	
	cout << l - f + 1 << '\n';
}

int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
	int t; cin >> t;
	while (t--) input();
	
	return 0;
}

