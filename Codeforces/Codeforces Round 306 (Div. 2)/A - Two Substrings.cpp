#include <bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back

void input()
{
	string s; cin >> s;
	size_t found1 = s.find("AB");
	size_t found2 = s.find("BA");
	if (found1 != string::npos) found1 = s.find("BA", found1 + 2);
	if (found2 != string::npos) found2 = s.find("AB", found2 + 2);
	
	if ((found1 != string::npos) || (found2 != string::npos))
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
   faster();

	input();

	return 0;
}
