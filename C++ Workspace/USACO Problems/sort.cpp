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
bool mustShift[100005];
int main(){
    //freopen("sort.in", "r", stdin);
    //freopen("sort.out", "w", stduut);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    //int max = 0;
    //int minPos = 0;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        
    }
    int ans = n;
    oset<pair<int,int>> os;
    for(int i = 0; i < n; i++){
        int larger = i - os.order_of_key({a[i], 100000});
        //cout << i << " " << larger << "\n";
        os.insert({a[i], i});
        if(larger == 0)continue;
        //if(i == minPos)larger--;
        larger--;
        ans += larger;
    }
    int mi = 1e9;
    for(int i = n-1; i >= 0; i--){
        if(a[i] >= mi){
            mustShift[i] = true;
        }        
        mi = min(mi, a[i]);
    }
    os.clear();
    for(int i = n-1; i >= 0; i --){
        if(mustShift[i]){
            int larger = (n-1 - i) - os.order_of_key({a[i]-1,100000});
            cout << larger << "\n";
            ans += larger; 
        }
        os.insert({a[i], i});
    }

    cout << ans << endl;
    


}

