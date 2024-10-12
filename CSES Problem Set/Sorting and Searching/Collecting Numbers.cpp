#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
#define ll long long
#define lui long unsigned int
#define vs vector<string>
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define fi first
#define la last
 
int a[200001], cnt[200001];
 
void input()
{
	int n; cin >> n;
	
	for (int i = 0; i < n; i++) 
	{
		cin >> a[i];
		cnt[a[i]] = i;
	}
	
	int indx = 1, res = 0;
	
	while (indx <= n)
	{
		res++;
		int tmp = cnt[indx];
		while (indx <= n && cnt[indx] >= tmp)
		{
			tmp = cnt[indx];
			indx++;
		}
	}
	
	cout << res;
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	input();
	
    return 0;
}
