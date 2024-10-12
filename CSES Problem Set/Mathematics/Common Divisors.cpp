#include <bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back
 
const int maxn = 1e6 + 9;
 
int divisor[maxn];
int n;
 
void process(int x)
{
	int up = (int)sqrt(x);
	for (int i = 1; i <= up; i++)
		if (x % i == 0)
		{
			divisor[i]++;
			if (i != (x / i)) divisor[x / i]++;
		}
}
 
void input()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		process(x);
	}
	
	for (int i = 1e6; i >= 0; i--)
		if (divisor[i] >= 2)
		{
			cout << i << '\n';
			return;
		}
}
 
int main()
{
	faster();
 
	input();
 
	return 0;
}
