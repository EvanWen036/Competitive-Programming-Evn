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
        vector<ll> A(n);
        ll maxC = -10000000000;
        vector<ll> diff;
        ll maxDiff = 0;
        for(int i = 0; i < n;i ++){
            cin >> A[i];
            if(A[i] < maxC){
                maxDiff = max(maxDiff, maxC-A[i]);
            }
            maxC = max(maxC, A[i]);
            
        }
        //cout << maxDiff;
        ll pow = 1;
        ll steps =0;
        while(maxDiff > 0){
            maxDiff -= pow;
            pow *= 2;
            steps++;
        }
        cout << steps << endl;
        
    }


}

