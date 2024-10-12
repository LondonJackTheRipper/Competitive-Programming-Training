#include <bits/stdc++.h>
using namespace std;
 
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define ii pair<int, int>
#define ll long long
#define pb push_back
 
const double eps = 1e-9;
 
struct vec
{
	double x, y;
	
	vec(double x, double y): x(x), y(y) {};
	
	vec operator - (const vec& a) const { return vec{x - a.x, y - a.y}; }
};
 
using point = vec;
 
int sign(double x)
{
	if (x > eps) return 1;
	if (x < -eps) return -1;
	return 0;
}
 
double cross(vec a, vec b)
{
	return a.x * b.y - a.y * b.x;
}
 
double dot(vec a, vec b)
{
	return a.x * b.x + a.y * b.y;
}
 
bool intersect(point a, point b, point c, point d)
{
	int abc = sign(cross(b - a, c - a));
	int abd = sign(cross(b - a, d - a));
	int cda = sign(cross(d - c, a - c));
	int cdb = sign(cross(d - c, b - c));
	if (abc == 0 || abd == 0 || cda == 0 || cdb == 0)
	{
		if (abc == 0 && dot(a - c, b - c) <= 0) return true;
		if (abd == 0 && dot(a - d, b - d) <= 0) return true;
		if (cda == 0 && dot(c - a, d - a) <= 0) return true;
		if (cdb == 0 && dot(c - b, d - b) <= 0) return true;
	}
	return (abc * abd < 0 && cda * cdb < 0);
}
 
void input()
{
	double x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	point a = {x1, y1};
	point b = {x2, y2};
	point c = {x3, y3};
	point d = {x4, y4};
	
	cout << (intersect(a, b, c, d) ? "YES\n" : "NO\n");
}
 
int main()
{
	faster();
 
	int t; cin >> t;
	while (t--) input();
 
	return 0;
}
