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
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i = 0; i < n;i ++){
        cin >> a[i];
    }
    int halves = 0;
    //cout << n / 2.0 << "\n";
    for(int i = 0; i < n; i++){
        if((double)a[i] < t / 2.0){
            cout << "1 ";
        }
        else if(a[i] > t/2.0){
            cout  << "0 ";
        }
        if(a[i] == t/2 && t % 2 == 0){
            cout << halves % 2 << " ";
            halves++;
        }
    }
    cout << "\n";
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

