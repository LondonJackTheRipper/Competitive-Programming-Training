#include<bits/stdc++.h>
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
	string res = "";
	string f = "ueoaiyYUEOAI";
	
	for (char x : s)
	{
		if (f.find(x) != string::npos) continue;
		res += '.';
		res += tolower(x);
	}
	
	cout << res << '\n';
}

int main()
{
   faster();

	input();

	return 0;
}

