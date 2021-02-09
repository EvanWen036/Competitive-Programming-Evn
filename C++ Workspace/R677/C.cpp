#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> diff;
    int mx = -1;
    int mxPos = 0;
    for(int i = 0; i < n;i ++){
        cin >> a[i];
        if(a[i] > mx){
            mx = a[i];
            mxPos = i;
        }
        diff.insert(a[i]);
    }
    if(diff.size() == 1){
        cout << -1 << "\n";
        return;
    }
    for(int i = 0; i < n;i ++){
        int val = a[i];
        if(i != 0 && a[i] > a[i-1])val++;
        if(i != n-1 && a[i] > a[i+1])val++;
        if(val > mx){
            cout << i+1 << "\n";
            return;
        }
    }

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

