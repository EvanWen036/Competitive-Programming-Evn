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
        if(n==1){
            cout << 1 << "\n" << 0 << endl;
            continue;
        }
        ll cur = 1;
        ll pow = 2;
        vector<int> list;
        list.push_back(1);
        int cnt = 2;
        while(cur + pow < n){
            cur += pow;
            list.push_back(pow);
            pow *= 2;
            cnt++;
        }
        list.push_back(n-cur);
        sort(list.begin(), list.end());
        cout << list.size()-1 << endl;
        
        for(int i = 0; i < list.size()-1; i++){
            cout << list[i+1]-list[i] << " ";    
        }
        cout << endl;
    }
	


}

