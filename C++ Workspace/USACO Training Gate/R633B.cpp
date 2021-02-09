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
        vector<int> A(n);
        for(int i = 0; i < n;i ++){
            cin >> A[i];
        }
        sort(A.begin(), A.end());
        vector<int> ans;
        int l = 0;
        int r = n-1;
        while(ans.size() < n){
            //cout << l << " " << r << endl;
            ans.push_back(A[l]);
            ans.push_back(A[r]);
            
            l++;
            r--;
        }
        for(int i = n-1; i >= 0;i --){
            cout << ans[i] << " ";
        }
        cout << endl;
    }

}

