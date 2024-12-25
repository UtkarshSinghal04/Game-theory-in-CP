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

vector<int> findFactors(int n) {
    vector<int> factors;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
        }
    }
    return factors;
}

void solve() {
    int n;
    cin>>n;

   if(n%2==0){
    cout<<"Alice will win"<<endl;
    while(n){
        cout<<"Alice - 1 "<<" final - "<<n-1<<endl;
        n=n-1;
        vector<int> factors = findFactors(n);
        srand(std::time(0));
        int randomIndex = rand() % factors.size();
        int randomFactor = factors[randomIndex];
         cout<<"Bob - "<<randomFactor<<" final - "<<n-randomFactor<<endl;
        n=n-randomFactor;
        
    }
   }
   else{
    cout<<"Bob will win"<<endl;
    while(n){
       
        vector<int> factors = findFactors(n);
        srand(std::time(0));
        int randomIndex = rand() % factors.size();
        int randomFactor = factors[randomIndex];
         cout<<"Alice - "<<randomFactor<<" final - "<<n-randomFactor<<endl;
        n=n-randomFactor;
         cout<<"Bob - 1 "<<"final - "<<n-1<<endl;
         n=n-1;
        
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

