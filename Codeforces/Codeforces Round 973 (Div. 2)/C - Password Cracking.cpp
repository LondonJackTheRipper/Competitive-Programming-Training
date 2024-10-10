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

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		
		bool isrev = false;
		string cur;
		cout << "? 1" << '\n'; cout.flush();
		int res; cin >> res;
		cur = (res == 1 ? "1" : "0");
		for (int i = 2; i <= n; i++)
		{
			if (!isrev)
			{
				string qr1 = cur + "1";
				string qr2 = cur + "0";
				
				cout << "? " << qr1 << '\n'; cout.flush();
				int res1; cin >> res1;
				cout << "? " << qr2 << '\n'; cout.flush();
				int res2; cin >> res2;
				
				if (res1 == 0 && res2 == 0)
				{
					isrev = true;
					string more = "1" + cur;
					cout << "? " << more << '\n'; cout.flush();
					int res; cin >> res; 
					cur = (res == 1 ? "1" : "0") + cur;
				} else
					cur = cur + (res1 == 1 ? "1" : "0");
			} else
			{
				string qr1 = "0" + cur;
				
				cout << "? " << qr1 << '\n'; cout.flush();
				int res; cin >> res;
				
				cur = (res == 1 ? "0" : "1") + cur;
			}
		}
		cout << "! " << cur << '\n'; cout.flush();
	}
	
	return 0;
}
