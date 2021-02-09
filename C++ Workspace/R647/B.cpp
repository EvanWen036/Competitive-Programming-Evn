#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
   
    for(int k = 1; k <= 1024; k++){
        multiset<int> curr;
        for(int i = 0; i < n; i++){
            curr.insert((a[i] ^ k));
        }
        for(int i = 0; i < n;i ++){
            if(curr.count(a[i]) > 0){
                curr.erase(a[i]);
            }
            else{
                break;
            }
            if(i == n-1){
                cout << k << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
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

