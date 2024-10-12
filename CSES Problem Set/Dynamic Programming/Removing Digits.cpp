#include <bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back
 
int compute(int n)
{
	int res = 0;
	while (n)
	{
		res = max(res, n % 10);
		n /= 10;
	}
	return res;
}
 
void input()
{
	int n; cin >> n;
	int res = 0;
	
	while (n)
	{
		n -= compute(n);
		res++;
	}
	
	cout << res << '\n';
}
 
int main()
{
	faster();
 
	input();
 
	return 0;
}
