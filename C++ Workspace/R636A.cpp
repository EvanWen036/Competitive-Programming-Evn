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
        for(ll pow = 2; pow < n; pow*=2){
            ll sum = pow*2-1;
            if(n % sum == 0){
                cout << n/sum << endl;
                break;
            }
        }
        
    }


}

