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
        map<int, int> mp;
        for(int i =0; i < n;i ++){
            cin >> A[i];
            mp[A[i]]++;
        }
        int maxSingle = 0;
        int maxVal = 0;
        map<int, int>::iterator it;
        for(it = mp.begin(); it != mp.end();it++){
            if(it->second > maxVal){
                maxVal = it->second;
                maxSingle = it->first;
            }
        }
        mp.erase(maxSingle);
        int size = mp.size();
        int ans = min(maxVal,size);
        if(maxVal > size){
            maxVal--;
            size++;
            ans = max(ans, min(maxVal,size));
        }
        cout << ans << endl;
    }


}

