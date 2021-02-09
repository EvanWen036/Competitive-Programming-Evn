#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        string s;
        cin >> s;
        //int ans = 0;
        //
        int cur = 0;
        int streak = 0;
        vector<int> endOne;
        vector<int> endZero;
        //cout << ans << endl;
        int nextFree = 1;
        vector<int> ans;
        for(int i = 0; i < N; i++){
            if(s[i] == '1'){
                if(endZero.empty()){
                    endOne.push_back(nextFree);
                    ans.pb(nextFree);
                    //cout << nextFree << " ";
                    nextFree++;
                }
                else{
                    endOne.push_back(endZero.back());
                    ans.pb(endZero.back());
                    //cout << endZero.back() << " ";
                    endZero.pop_back();
                }
            }
            else{
                if(endOne.empty()){
                    endZero.push_back(nextFree);
                    ans.pb(nextFree);
                    //cout << nextFree << " ";
                    nextFree++;
                }
                else{
                    endZero.push_back(endOne.back());
                    ans.pb(endOne.back());
                    //cout << endOne.back() << " ";
                    endOne.pop_back();
                }
            }
        }
        cout << nextFree-1 << endl;
        for(int i = 0; i < N; i++){
            cout << ans[i] << " ";
        }
    }

}

