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
        int ans = 0;
        int pow = 2;
        for(int i = 0; i < n/2 ;i++){
            ans += pow;
            pow *= 2;
        }
        cout << ans <<  endl;
    }


}

