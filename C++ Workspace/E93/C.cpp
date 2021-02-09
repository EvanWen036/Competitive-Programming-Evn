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
        string s;
        cin >> s;
        //map<int, int> mp;
        ll prefix[n+1];
        ll ans = 0;
        map<int,ll> count;
        set<ll> val;
        prefix[0] = 0;
        for(int i = 1; i <= n;i ++){
            A[i-1] = s[i-1] - '0';
            prefix[i] = A[i-1];
            prefix[i] += prefix[i-1];
            val.insert(prefix[i]-i);
            count[prefix[i]-i]++;
            //cout << A[i] << endl;
        }
        count[0]++;
        for(auto it : val){
            //cout << it << endl;
            ans += (count[it] * (count[it]-1))/2;
        }
        
        cout << ans<< endl;
    }
    


}

