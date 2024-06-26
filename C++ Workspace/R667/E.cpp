#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int coord[2*100000 + 5];
int ansL[2*100000 + 5];
int ansR[2*100000 + 5];
void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        //int x;
        cin >> coord[i];
    }
    //ignore y coordinates
    for(int i = 0 ;i < n; i++){
        int x;
        cin >> x;
    }
    //cout << "hi" << endl;
    sort(coord, coord+n);
    //never optimal for segments to overlap
    //can be treated as disjoint segments
    //calculate value for prefix then calculate value for suffix then get the two max and get the answer
    oset<pii> active;
    for(int i = 0; i < n; i++){
        //say we include the i'th point in the first segment
        active.insert(mp(coord[i], i));
        //cout << active.order_of_key(mp(coord[i],i))+1 << " " << active.order_of_key(mp(coord[i]-k-1, 200005)) << endl;
        int current = active.order_of_key(mp(coord[i],i))+1 - active.order_of_key(mp(coord[i] -k-1, 200005));
        ansL[i] = current;
        if(i != 0)ansL[i] = max(ansL[i], ansL[i-1]);
        //cout << ansL[i] << endl;
    }
    active.clear();
    for(int i = n-1; i >= 0; i--){
        active.insert(mp(coord[i],i));
        int current = active.order_of_key(mp(coord[i]+k, 200005)) - active.order_of_key(mp(coord[i]-1,200005));
        ansR[i] = current;
        if(i != n-1)ansR[i] =max(ansR[i], ansR[i+1]);
        //cout << ansR[i] << endl;
    }
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        ans = max(ans, ansL[i] + ansR[i+1]);
    }
    if(n == 1)ans = 1;
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

