#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
bool seen[105];
bool seen2[105];
void solve(){
    int n;
    cin >> n;
    memset(seen, false,sizeof(seen));
    memset(seen2, false, sizeof(seen2));
    vector<int> a;
    vector<int> b;
    for(int i = 0; i < n;i ++){
        int x;
        cin >> x;
        if(!seen[x]){
            a.pb(x);
            seen[x] = true;
        }
        else if(seen[x] && !seen2[x]){
            b.pb(x);
            seen2[x] = true;
        }
        
        
    }
    /**
    for(auto it: a){
        cout << it << endl;
    }
    for(auto it:b){
        cout << it << endl;
    }**/
    //vectur<int> a;
    //set<int> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int curr = 0;
    int ans = 0;
    for(int i = 0; i <= a.size(); i++){
        //cout << a[i] << endl;
        if(i == (int)a.size() || a[i] != curr){
            ans += curr;
            break;
        }
        curr++;        
    }
    curr = 0;
    for(int i = 0; i <= b.size(); i++){
        //cout << b[i] << endl;
        if(i == (int)b.size() || b[i] != curr){
            ans += curr;
            break;
        }
        curr++;
    }
    cout << ans << "\n";
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
	


}

