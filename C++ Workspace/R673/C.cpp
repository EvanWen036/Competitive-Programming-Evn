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
int prevOcc[3*100005];
int maxDist[3*100005];
void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    //int prevOcc[3*100005];
    //int maxDist[3*100005];
    memset(prevOcc, 0, sizeof(prevOcc));
    memset(maxDist, 0, sizeof(maxDist));
    for(int i =1; i <= n;i ++){
        
        cin >> a[i];
        maxDist[a[i]] = max(maxDist[a[i]], i - prevOcc[a[i]]);
        prevOcc[a[i]] = i;
    }
    //cout << "hi" << endl;
    multiset<int> numbers;

    vector<int> add[n+1];
    for(int i = 1; i <= n;i ++){
        maxDist[i] = max(maxDist[i], n - prevOcc[i] + 1);
        if(maxDist[i] > n)continue;
        //cout << maxDist[i] << "\n";
        add[maxDist[i]].pb(i);
    }
    //cout << "hi" << endl;
    for(int i = 1; i <= n; i++){
        for(auto it : add[i]){
            numbers.insert(it);
        }
        if(numbers.size() == 0){
            cout << -1 << " ";
        }
        else{
            cout << *numbers.begin() << " ";
        }
        //add[i].clear();
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

