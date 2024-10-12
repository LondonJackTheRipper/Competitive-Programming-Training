#include<bits/stdc++.h>
using namespace std;
 
int a[200001];
bool check[200001];
 
void input()
{
    int n, k; cin >> n >> k;
    
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    
    int i = 0, j = n - 1;
    int ans = 0;
    
    while (i < j)
    {
        if (a[i] + a[j] > k)
        {
            j--;
        } else 
        {
            ans++;
            check[i] = check[j] = 1;
            i++; j--;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        ans += check[i] == false;
    }
    
    cout << ans;
}
 
int main() {
    input();
    
    return 0;
}
