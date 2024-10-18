#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  Handle codeforces : quangminh98

  Mua Code nhu mua Florentino !!
*/

#define ll long long

void input()
{
	int n, k; cin >> n >> k;
	
	while (k--)
	{
		if (n % 10 != 0) n--; else n /= 10;
	}
	
	cout << n;
}

int main()
{
	input();
	
    return 0;
}
