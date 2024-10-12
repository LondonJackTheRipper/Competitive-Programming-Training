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
	ll x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	ll a = y1 - y2, b = x2 - x1;
	ll c = -a * x1 - b * y1;
	ll t = a * x3 + b * y3 + c; 
	
	if (t == 0)
		cout << "TOUCH\n";
	else 
		cout << (t > 0 ? "LEFT\n" : "RIGHT\n");
}
 
int main()
{
	faster();
 
	int t; cin >> t;
	while (t--) input();
 
	return 0;
}
