#include <bits/stdc++.h>
using namespace std;

/*
  John Watson

  Mua Code nhu mua Florentino !!
  
  Tags:
*/

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

void input()
{
	string s1, s2; cin >> s1 >> s2;
	int i = 0, j = 0;
	
	while (i < s1.length())
	{	
		if (j < s2.length() && s1[i] == s2[j])
			j++;
		else 
		if (s1[i] == '?')
		{
			s1[i] = (j >= s2.length() ? 'a' : s2[j]);
			j++;
		} 
		
		i++;
	}
	
	if (j >= s2.length())
	{
		cout << "YES\n";
		cout << s1 << '\n';
	} else 
		cout << "NO\n";
}

int main()
{
        faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
