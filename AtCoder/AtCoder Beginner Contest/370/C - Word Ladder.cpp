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
	faster();

	string s, t; cin >> s >> t; 
	
	vector<string> res;
	while(1)
	{
		int pos1 = -1, pos2 = -1;
		for (int i = 0; i < s.length(); i++)
			if (s[i] != t[i])
			{
				pos1 = i;
				if (s[i] > t[i] && pos2 == -1)
					pos2 = i; 
			}
		if (pos1 == -1 && pos2 == -1) break;
		if (pos2 != -1)
			s[pos2] = t[pos2];
		else
			s[pos1] = t[pos1];
		res.push_back(s);
	}

	cout << res.size() << '\n';
	for (string str : res) 
		cout << str << '\n';

	return 0;
}
