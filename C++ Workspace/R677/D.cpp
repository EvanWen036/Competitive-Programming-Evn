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
    bool diff = false;
    for(int i = 0; i < n;i++){
        cin >> a[i];
        if(i != 0 && a[i] != a[i-1])diff = true;
    }
    if(!diff){
        cout << "No\n";
        return;
    }
    bool placed[n];
    memset(placed,false,sizeof(placed));
    cout << "Yes\n";
    for(int i = 1; i < n;i ++){
        if(a[i] != a[0]){
            placed[i] =true;
            cout << 1 << " " << i+1 << "\n";
        }
    }
    for(int i = 1; i < n;i++){
        if(a[i] == a[0]){
            for(int j = 0; j < n;j++){
                if(a[j] != a[i]){
                    cout << i + 1 << " " << j+1 << "\n";
                    break;
                }
            }
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

