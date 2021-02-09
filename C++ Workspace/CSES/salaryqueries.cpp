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
int val[200005];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    oset<pii> set;
    for(int i = 0; i < n; i++){
        cin >> val[i];
        set.insert(mp(val[i], i));
    }
    for(int i = 0; i < q; i++){
        char c;
        cin >> c;
        if(c == '!'){
            //update
            int k, x;
            cin >> k >> x; k--;
            set.erase(mp(val[k], k));
            set.insert(mp(x, k));
            val[k] = x;
        }
        else{
            int a, b;
            cin >> a >> b;
            cout << set.order_of_key(mp(b, 200006)) - set.order_of_key(mp(a-1, 200006)) << endl;
        }

    }
    

}

