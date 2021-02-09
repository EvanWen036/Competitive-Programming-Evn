#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
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
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        //cout << ans << endl;
        int ans = 0;
        for(int s = 2; s <= 2 * n; s++){
            
            int count = 0;
            for(int i = 1; i <=s/2; i++){
                if(i == s-i){
                    count += mp[i]/2;
                }
                else{
                    count += min(mp[i], mp[s-i]);
                }
            }
            //cout << count << " " <<s << endl;
            ans = max(ans, count);
        }
        cout << ans << endl;
    }


}

