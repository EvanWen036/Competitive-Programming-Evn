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
        int n,k; 
        cin >> n >> k;
        string s;
        cin >> s;
        vector<string> sub;
        map<string, int> mp;
        for(int i = 0; i < n; i++){
            sub.push_back(s.substr(i,1));
        }
        sort(sub.begin(), sub.begin() + n);
        string ans = "";
        if(k==1){
            for(int i = 0; i < sub.size();i ++){
                ans += sub[i];
            }
            cout << ans << endl;
            continue;
        }
        ans += sub[k-1];
        if(sub[k-1] != sub[0] || k == n){
            cout << ans << endl;
            continue;
        }
        if(sub[n-1] == sub[k]){
            int left = n-k;
            int amt = left/k;
            if(amt * k < left)amt++;
            for(int i =0; i < amt; i++){
                ans += sub[n-1];
            }
            cout << ans << endl;
            continue;
        }
        else{
            for(int i = k;i < n; i++){
                ans += sub[i];
            }
            cout << ans << endl;
            continue;
        }
    }


}

