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
    int t;
    cin >> t;
    int n, x;
    cin >> n >> x;
    if(n <= 2){
        cout << 1 << "\n";
        return;
    }
    int rooms = 2;
    for(int i = 2; i <= 1000;i ++){
        rooms += x;
        if(rooms >= n){
            cout << i << "\n";
            break;
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

