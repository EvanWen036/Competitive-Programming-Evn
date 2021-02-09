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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n;i ++){
            cin >> a[i];
        }
        
        int pref[2*k+5];
        int pref2[2*k];
        memset(pref, 0, sizeof(pref));
        memset(pref2, 0, sizeof(pref2));
        for(int i = 0; i < n/2; i ++){
            int x = a[i];
            int y = a[n-i-1];
            int currM = max(x,y) + k;
            int currMi = min(x,y) + 1;
            //max value you can form by switch 1 = max(x,y) -> k
            pref[currMi]++;
            pref[currM+1]--;
            pref2[1]++;
            pref2[currMi]--;
            pref2[currM+1]++;
            pref2[2*k]--;
        }
        int ans = 1000000000;

        int real[2*k + 5];
        memset(real, 0, sizeof(real));
        for(int i = 1; i <= 2 * k; i++){
            real[i] = real[i-1] + pref[i] + 2 * pref2[i];
            ans = min(ans, real[i]);
        }
        cout << ans << endl;
    }

}

