#include<bits/stdc++.h>
using namespace std;

string str = "codeforces";

int main(){
   int t;cin >> t;
   while(t--){
      string c; cin >> c;
      cout << (str.find(c) == string::npos ? "NO\n" : "YES\n");
   }
   
   return 0;
}
