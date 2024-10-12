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
	int n; cin >> n;
	vector<pair<ll, ll>> coor(n);
	for (auto &it : coor) cin >> it.first >> it.second;
	ll res = 0;
	
	for (int i = 0; i < n - 1; i++)
		res = res + coor[i].first * coor[i + 1].second - coor[i].second * coor[i + 1].first;
	res = res + coor[n - 1].first * coor[0].second - coor[n - 1].second * coor[0].first;
	
	cout << abs(res) << '\n';
}
 
int main()
{
	faster();
 
	input();
 
	return 0;
}
