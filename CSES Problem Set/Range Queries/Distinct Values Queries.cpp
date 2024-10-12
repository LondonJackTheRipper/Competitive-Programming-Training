#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pll pair<long long, long long>
#define vll vector<long long>
#define lui long unsigned int
#define vs vector<string>
#define pi pair<int, int>
#define vc vector<char>
#define vi vector<int>
#define pb push_back
 
struct query
{
	int l, r, id;
	
	query(int ul, int ur, int ud): l(ul), r(ur), id(ud) {};	
};
 
const int maxn = 2e5 + 9;
 
vector<query> queries;
int fre[maxn];
int arr[maxn];
int distinct;
int n, N, q;
 
bool cmp(query a, query b)
{
	if (a.l / N != b.l / N)
		return a.l / N < b.l / N;
	return a.r < b.r;
}
 
void add(int &val)
{
	if (!fre[val]) distinct++;
	fre[val]++;
}
 
void remove(int &val)
{
	fre[val]--;
	if (!fre[val]) distinct--;
}
 
void MO()
{
	sort(queries.begin(), queries.end(), cmp);
	vector<int> ans(q + 1);
	
	int curl = queries[0].l;
	int curr = queries[0].l;
	fre[arr[curl]]++;
	distinct = 1;
	
	for (query qr : queries)
	{
		int l = qr.l, r = qr.r;
		
		while (l < curl)
		{
			curl--;
			add(arr[curl]);
		}
		while (r < curr)
		{
			remove(arr[curr]);
			curr--;
		}
		while (l > curl)
		{
			remove(arr[curl]);
			curl++;
		}
		while (r > curr)
		{
			curr++;
			add(arr[curr]);
		}
		
		ans[qr.id] = distinct;
	}
	
	for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}
 
void input()
{
	cin >> n >> q;
	N = sqrt(n);
	
	int num = 1;
	map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (mp.find(arr[i]) != mp.end())
			arr[i] = mp[arr[i]];
		else
		{
			mp[arr[i]] = num;
			arr[i] = num++;
		}
	}
	
	for (int i = 0; i < q; i++)
	{
		int x, y; cin >> x >> y;
		queries.pb({x - 1, y - 1, i});
	}
	MO();
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
	
	input();
 
	return 0;
}
