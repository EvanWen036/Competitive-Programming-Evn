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
        for(int i =0; i < n;i ++){
            cin >> a[i];
        }
        int currPos = 0;
        int currNeg = -1000000000;
        ll sum = 0;
        bool turn = false;
        if(a[0] > 0){
            currPos = a[0];
            sum += a[0];
            turn = true;
        }
        else{
            currNeg = a[0];
            sum += a[0]; 
        }
        for(int i = 1; i < n;i++){
            bool pos = a[i] > 0;
            cout << sum << endl;
            if(pos && turn){
                //we just picked pos and we have another pos
                if(currPos < a[i]){
                    sum -= currPos;
                    sum += a[i];
                    currPos = a[i];
                }
            }
            else if(!pos && !turn){
                //we just picked neg and we have another neg
                if(a[i] > currNeg){
                    sum -= currNeg;
                    sum += a[i];
                    currNeg = a[i];
                }
            }
            else if(!pos && turn){
                //we just picked a positive and we have neg
                sum += a[i];
                currNeg = a[i];
                turn = false;
            }
            else{
                //we just picked a neg and we have pos
                sum += a[i];
                currPos = a[i];
                turn = true;
            }
        }
        cout << sum << endl;
    }


}

