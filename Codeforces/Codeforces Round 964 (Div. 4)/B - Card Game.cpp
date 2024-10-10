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
	int a1, a2, b1, b2; 
	cin >> a1 >> a2 >> b1 >> b2;
	
	int p11 = (a1 > b1) + (a2 > b2), p12 = (b1 > a1) + (b2 > a2); 
	int p21 = (a1 > b2) + (a2 > b1), p22 = (b2 > a1) + (b1 > a2); 
	int p31 = (a2 > b1) + (a1 > b2), p32 = (b1 > a2) + (b2 > a1); 
	int p41 = (a2 > b2) + (a1 > b1), p42 = (b2 > a2) + (b1 > a1); 
	cout << (p11 > p12) + (p21 > p22) + (p31 > p32) + (p41 > p42) << '\n';
} 

int main()
{
   faster();

	int t; cin >> t;
	while (t--) input();

	return 0;
}
