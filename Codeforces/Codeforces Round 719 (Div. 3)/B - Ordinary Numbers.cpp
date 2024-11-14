#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int cs(int n)
{
	int ans = 0;
	
	while (n)
	{
		ans++;
		n /= 10;
	}
	
	return ans;
}

int pow(int a, int b)
{
	int res = 1;
	
	while (b)
	{
		if (b % 2 == 1) 
			res *= a;
		
		a *= a;
		b /= 2;
	}
	
	return res;
}

void input()
{
	int n; cin >> n;
	int tmp = cs(n), first_digit = n / pow(10, tmp - 1);
	if (tmp == 1) first_digit = n;
	int ans = 9 * (tmp - 1) + first_digit;
	int t = 0;
	for (int i = 1; i <= tmp; i++) t = t * 10 + first_digit;
	
	if (n < t) ans--;
	
	cout << ans << '\n';
}

int main()
{
	int t; cin >> t;
	while (t--) input();

    return 0;
}
