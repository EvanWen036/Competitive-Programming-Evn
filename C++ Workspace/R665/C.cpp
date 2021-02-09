#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int n;
vector<int> a(100005);
vector<int> positions;
vector<int> val;
void solve(){
    cin >> n;
    int mi = 1000000000;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mi = min(mi, a[i]);
    }
    for(int i = 0; i < n;i ++){
        if(a[i] % mi == 0){
            positions.pb(i);
            val.pb(a[i]);
        }
    }
    sort(val.begin(), val.end());
    for(int i = 0; i < positions.size(); i++){
        cout << positions[i] << " " << val[i] << endl;
        a[positions[i]] = val[i];
    }
    positions.clear();
    val.clear();
    int mx = -1;
    for(int i = 0; i < n;i ++){
        //cout << a[i] << " ";
        if(a[i] < mx){
            cout << "No" << endl;
            //positions.clear();
            //val.clear();
            return;
        }
        mx = a[i];
    }
    cout << "Yes" << endl;
    
    
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

