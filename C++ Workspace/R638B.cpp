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
        int k;
        cin >> k;
        vector<int> A(n);
        bool done = false;
        set<int> val;
        for(int i = 0; i < n;i ++){
            cin >> A[i];
            val.insert(A[i]);            
        }
        if(val.size() > k)cout << -1 << endl;
        
        else{
            vector<int> ans;
            vector<int> values;
            for(int i : val){
                values.push_back(i);
            }
            for(int i = 0; i < n;i ++){
                for(int i = 0; i < k; i++){
                    ans.push_back(values[i % values.size()]);
                    
                }
                
            }
            cout << ans.size() << endl;
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }

    }


}

