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
	string s1, s2; cin >> s1 >> s2;
	
	for (int i = 0; i < s1.length(); i++)
		cout << (s1[i] != s2[i]);
}

int main()
{
   faster();

	input();

	return 0;
}
