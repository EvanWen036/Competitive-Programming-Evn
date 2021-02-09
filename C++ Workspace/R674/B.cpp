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
    int n, m;
    cin >> n >> m;
    vector<int> pii;
    bool hasSymmetric = false;
    for(int i = 0; i < n;i ++){
        int a, b;
        cin >> a >> b;
        int x, y;
        cin >> x >> y;
        if(x == b)hasSymmetric = true;    
    }
    bool even = (m%2 == 0);
    
    cout << (even && hasSymmetric ? "Yes":"No") << "\n";    
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

