#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define int long long
#define pb(x) push_back(x)
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define vc vector<char>
#define ss second
#define ff first
#define MOD 1000000007
#define INF 1e18


void solve() {
    int n;
    cin>>n;
    if(n%4==0){
           cout<<"Bob Will win"<<endl;
        while(n){
         
            int num= (rand() % 3) + 1;
            cout<<"Alice - "<<num<<" state - "<<n-num<<endl;
            n=n-num;
            if(n==0){
                return;
            }
            cout<<"Bob - "<<n%4<<" state - "<<n-n%4<<endl;
            n=n-n%4;
        }


       
    }
    else{
           cout<<"Alice will win"<<endl;
        while(n){
         
            cout<<"Alice - "<<n%4<<" state - "<<n-n%4<<endl;
            n=n-n%4;
            if(n==0){
                return;
            }
            int num= (rand() % 3) + 1;
            cout<<"Bob - "<<num<<" state - "<<n-num<<endl;
            n=n-num;
        }
    }
   

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}

