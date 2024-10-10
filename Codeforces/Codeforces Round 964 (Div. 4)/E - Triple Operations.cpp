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

const int maxn = 2e5 + 9;

ll pre[maxn], a[maxn];
ll lt[100];

void input()
{
	int l, r; cin >> l >> r;
	
	cout << pre[r] - pre[l - 1] + a[l] << '\n';
}

int main()
{
   faster();

	lt[0] = 1;
    for(int i = 1; i <= 15; i++) lt[i] = lt[i-1] * 3;
	for (int i = 1; i <= 200000; i++)
	{
        ll j = 0;
        while(i / lt[j] != 0) j++;
		pre[i] = pre[i - 1] + j;
		a[i] = j;
	}
	
	int t; cin >> t;
	while (t--) input();

	return 0;
}
