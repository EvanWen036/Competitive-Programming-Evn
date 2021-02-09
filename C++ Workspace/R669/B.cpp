#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
bool inc[1005];
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i ++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    memset(inc, false, sizeof(inc));
    cout << a[n-1] << " ";
    int curr = a[n-1];
    inc[n-1] = true;
    for(int i =1; i < n; i++){
        int mx = 0;
        int mxPos = -1;
        for(int j = 0; j < n; j++){
            if(inc[j])continue;
            if(__gcd(curr, a[j]) > mx){
                mx = __gcd(curr, a[j]);
                mxPos = j;
            }
        }
        inc[mxPos] = true;
        cout << a[mxPos] << " ";
        curr = mx;
    }
    cout << endl;
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

