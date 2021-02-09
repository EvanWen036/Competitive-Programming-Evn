#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> A(n);
        map<int, int> firstOcc;
        map<int, int> lastOcc;
        for(int i =0; i <= 30; i++){
            firstOcc[i] = 10000000;
            lastOcc[i] = -1;
        }
        for(int i = 0; i<n; i++){
            cin >> A[i];
            firstOcc[A[i]] = min(firstOcc[A[i]], i);
            lastOcc[A[i]] = max(lastOcc[A[i]], i);
        }
        int ans = 0;
        for(int i = 0; i <= 30; i++){
            cout << "hi";
            int times = 0;
            if(firstOcc[i] != 10000000)continue;
            for(int j = firstOcc[i]; j <= lastOcc[i]; j++){
                if(A[j] == i){
                    times++;
                }
            }
            int occ[30];
            memset(occ, 0, sizeof(occ));
            for(int j = 0; j < firstOcc[i]; j++){
                occ[A[j]]++;
            }
            for(int j = lastOcc[i] + 1; j < n; j++){
                occ[A[j]]++;
            }
            for(int j = 0; j <= 30; j++){
                ans = max(ans, times + occ[A[j]]);
            }
        }
        cout << ans << endl;
    }

}

