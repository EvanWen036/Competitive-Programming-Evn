#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> mp(n+1);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mp[a[i]]++;    
        }
        int pref[n+1];
        pref[0] = 0;
        for(int i = 1; i <= n; i++){
            pref[i] = pref[i-1] + a[i-1];
        }
        
        int ans = 0;
        
        for(int i = 0; i <= n;i ++){
            for(int j = i+2; j <= n; j++){
                    if(pref[j]-pref[i] > n)continue; 
                    ans += mp[pref[j]-pref[i]];
                    mp[pref[j]-pref[i]] = 0;                
            }
        } 
        cout << ans << endl;
    }


}

