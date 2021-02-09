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

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll p,y; cin >> p >> y;
    /**
    if(y < 2 * p){
        cout << -1 << "\n";
        return 0;
    }**/
    for(ll i = y; i >= p; i --){
        if(i % 2 == 0){
            continue;
        }
        bool bad = false;
        for(int j = 3; j * j <= i; j += 2){
            if(i % j == 0  && j <= p){
                bad = true;
                break;
            }
        }
        if(bad)continue;
        cout << i << endl;
        return 0;
    }
    cout << -1 << "\n";    


}

