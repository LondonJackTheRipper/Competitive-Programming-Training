#include <bits/stdc++.h>
using namespace std;
 
/*
  John Watson
  https://codeforces.com/profile/quangminh98
 
  Mua Code nhu mua Florentino !!
*/
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
const int oo = 1e9;
const int maxn = 2e5 + 9;
 
vector<pair<int, int>> adj[maxn];
int del[maxn], sz[maxn], h[maxn];
vector<int> cnt;
int n, k, res = oo;
 
int subtree(int u, int p = -1)
{
  sz[u] = 1;
  for (pair<int, int> nxt : adj[u])
  {
    int v = nxt.first;
    if (v == p || del[v]) continue;
    
    sz[u] += subtree(v, u);
  }
  return sz[u];
}
 
int find_centroid(int u, int p, int N)
{
  for (pair<int, int> nxt : adj[u])
  {
    int v = nxt.first;
    if (v == p || del[v]) continue;
    
    if (sz[v] > N / 2)
      return find_centroid(v, u, N);
  }
  return u;
}
 
void count(int u, int p, int w, int h)
{
	if (w > k) return;
	if (cnt[k - w] != oo)
		res = min(res, cnt[k - w] + h);
		
	for (pair<int, int> nxt : adj[u])
	{
		int v = nxt.first;
		if (del[v] || v == p) continue;
		
		count(v, u, w + nxt.second, h + 1);
	}
}
 
int mx_w = 0;
void update(int u, int p, int w, int h)
{
	if (w > k) return;
	mx_w = max(mx_w, w);
	cnt[w] = min(cnt[w], h);
	
	for (pair<int, int> nxt : adj[u])
	{
		int v = nxt.first;
		if (del[v] || v == p) continue;
		
		update(v, u, w + nxt.second, h + 1);
	}
}
 
void centroid_decomposition(int u)
{
	int centroid = find_centroid(u, -1, subtree(u));
	del[centroid] = 1;
	
	mx_w = 0;
	
	for (pair<int, int> nxt : adj[centroid])
	{
		int v = nxt.first;
		if (del[v]) continue;
		
		count(v, centroid, nxt.second, 1);
		update(v, centroid, nxt.second, 1);
	}
	
	for (int i = 1; i <= mx_w; i++) cnt[i] = oo;
	
	for (pair<int, int> nxt : adj[centroid])
	{
		int v = nxt.first;
		if (del[v]) continue;
		
		centroid_decomposition(v);
	}
}
 
int best_path(int _n, int _k, int H[][2], int l[]) 
{
	n = _n;
	k = _k;
	cnt.resize(k + 5, oo);
	cnt[0] = 0;
	for (int i = 0; i < n - 1; i++)
	{
	  int w = l[i];
	  int u = H[i][0], v = H[i][1];
	  adj[u].push_back({v, w});
	  adj[v].push_back({u, w});
	}
	
	centroid_decomposition(1);
	
	return (res == oo ? -1 : res);
}
