#include <bits/stdc++.h>
using namespace std;

/*
  John Watson
  https://codeforces.com/profile/quangminh98

  Mua Code nhu mua Florentino !!
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

signed main()
{
	if (fopen("test.inp", "r"))
	{
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	faster();

	char ab, ac, bc; cin >> ab >> ac >> bc;
	int t1 = (ab == '<');
	int t2 = (ac == '<');
	int t3 = (bc == '<');
 
 	if (t1 + t2 == 1)
 		cout << 'A';
 	else
 	if (t1 + t3 == 0 || t1 + t3 == 2)
 		cout << 'B';
 	else
 	cout << 'C';
 	
	return 0;
}
