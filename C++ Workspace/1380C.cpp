#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int min = 1000000000;
    int l = 0;
    for(int i = n-1; i >= 0; i --){
        l++;
        if(l * a[i] >= x){
            ans++;
            l = 0;
        }
    }
    cout << ans << endl;
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

