#include<bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 9;
int tele[maxn], visited[maxn], des[maxn];
int n, step;
queue<int> q;
 
void dfs(int u)
{
	q.push(u);
	if (visited[u])
	{
		step += tele[u];
		return;
	}
	
	visited[u] = 1;
	step++;
	dfs(des[u]);
}
 
void input()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> des[i], des[i]--;
		
	for (int i = 0; i < n; i++) if (!visited[i])
	{
		step = 0;
		dfs(i);
		int decre = 1;
		
		while (!q.empty())
		{
			if (q.front() == q.back()) decre = 0;
			tele[q.front()] = step;
			step -= decre;
			q.pop();
		}
	}
	
	for (int i = 0; i < n; i++) cout << tele[i] << ' ';
}
 
int main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	faster();
 
	input();
 
	return 0;
}
