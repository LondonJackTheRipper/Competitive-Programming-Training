#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
#define pi pair<int, int>
 
bool cmp(pi a, pi b)
{
    return a.second < b.second;
}
 
pi a[200001];
 
void input()
{
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a, a + n, cmp);
    
    int cur = 0;
    int ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (a[i].first >= cur)
        {
            ans++;
            cur = a[i].second;
        }
    }
    
    cout << ans;
}
 
int main() {
    input();
    
    return 0;
}
