#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

string s;
string cur = "";
int res = -1;

void check()
{
	int x = stoi(cur);
	if (x % 8 == 0) res = x;
}

void recur(int i, int l)
{
	if (l == 0)
	{
		check();
		return;
	}
	if (i == s.length()) return;
	
	recur(i + 1, l);
	cur += s[i];
	recur(i + 1, l - 1);
	cur.pop_back();
}

int main()
{
   faster();

	cin >> s;
	
	recur(0, 1);
	recur(0, 2);
	recur(0, 3);
	
	if (res == -1)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		cout << res << '\n';
	}

	return 0;
}
