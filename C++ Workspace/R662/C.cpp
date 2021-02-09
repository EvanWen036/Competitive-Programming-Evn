#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
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
        set<int> s;
        map<int, int> mp;
        int cnt = 0;
        for(int i = 0 ;i  < n;i ++){
            cin >> A[i];
            s.insert(A[i]);
            mp[A[i]] ++;
        }
        int ans = s.size()-1;
        if(mp.size() == 1){
            cout << ans << endl;
            continue;
        }
        for(int i = 1; i <= n; i++){
            if(mp[i] >= 2){
                ans -= (mp[i] - 2);
            }
        }
        cout << ans << endl;
    }


}

