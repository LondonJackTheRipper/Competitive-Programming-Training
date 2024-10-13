#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back

int n, m, k;

bool check(vector<int> order, vector<int>& hierachy)
{
	vector<int> cow_to_pos(n, -1);
	
	for (int i = 0; i < n; i++)
		if (order[i] != -1)
			cow_to_pos[order[i]] = i;
			
	int hier = 0;
	for (int i = 0; i < n && hier < m; i++)
	{
		if (cow_to_pos[hierachy[hier]] != -1)
		{
			if (i > cow_to_pos[hierachy[hier]]) return false;
			
			i = cow_to_pos[hierachy[hier]];
			hier++;
		} else 
		{
			while (i < n && order[i] != -1) i++;
			
			if (i == n) return false;
			
			order[i] = hierachy[hier];
			cow_to_pos[hierachy[hier]] = i;
			hier++;
		}
	}
	
	return true;
}

void input()
{
	cin >> n >> m >> k;
	
	vector<int> hierachy(m);
	for (int i = 0; i < m; i++)
	{
		cin >> hierachy[i];
		hierachy[i]--;
	}
	vector<int> order(n, -1);
	for (int i = 0; i < k; i++)
	{
		int x, pos; cin >> x >> pos;
		order[--pos] = --x;
		
		if (x == 0)
		{
			cout << pos + 1 << '\n';
			return;
		}
	}
	
	for (int i = 0; i < n; i++)
		if (order[i] == -1)
		{
			order[i] = 0;
			if (check(order, hierachy))
			{
				cout << i + 1 << '\n';
				return;
			}
			order[i] = -1;
		}
}

int main()
{
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);

	input();

	return 0;
}

