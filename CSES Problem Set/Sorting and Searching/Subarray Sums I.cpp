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
	int n; cin >> n;
	ll x; cin >> x;
	vector<ll> arr(n);
	for (ll &i : arr) cin >> i;
	ll res = 0, left = 0, right = -1;
	ll sum = 0;
	
	while (right < n)
	{
		while (right < n && sum < x)
			sum += arr[++right];
		while (left <= right && sum > x)
			sum -= arr[left++];
			
		if (sum == x)
		{
			res++;
			sum -= arr[left];
			left++;
		}
	}
	
	cout << res << '\n';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
