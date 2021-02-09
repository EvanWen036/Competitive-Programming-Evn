
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
    int te;
    cin >> te;
    //cout << " hi";
    for(int i = 1; i <= te; i++){
        vector<int> t;
        ll d;
        int n;
        cin >> n >> d;
        //cout << n << " " << d;
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            t.push_back(x);
        }
        ll low = 1;
        ll high = d;
        while(low < high){
            //cout << low << " " << high << endl;
            ll mid = (low+high+1)/2;
            
            ll curr = mid;
            for(ll i : t){
                if(curr % i == 0)continue;
                curr += i-(curr % i);
            }
            if(curr <= d){
                
                low = mid;
            } 
            else{
                high = mid-1;
            }
        }
        
        cout << "Case #" << i << ": " << low << endl;
    }


}


