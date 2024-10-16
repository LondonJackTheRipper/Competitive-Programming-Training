#include <bits/stdc++.h>
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
	string s; getline(cin, s);
	int cnt = count(s.begin(), s.end(), '0');
	
	if (cnt == 0)
	{
		cout << 0 << '\n';
		return;
	}
	
	int first = s.find('0');
	int last = s.rfind('0');
	
	if (last - first + 1 == cnt)
		cout << 1;
	else 
		cout << 2;
	cout << '\n';
	
}

int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	int t; cin >> t;
	cin.ignore();
	while (t--) input();
	
	return 0;
}

