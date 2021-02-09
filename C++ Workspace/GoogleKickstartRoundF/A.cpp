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
void solve(int tc){
    queue<pii> q;
    int n, y;
    cin >> n >> y;
    vector<pii> a;
    for(int i= 0;i  < n; i++){
        int x;
        cin >> x;
        //a.pb(mp(x,i));
        a.push_back(mp(x/y, i+1));
    }
    sort(a.begin(), a.end());
    cout << "Case #" << tc << ": ";
    for(int i = 0; i < n;i ++){
        cout << a[i].s << " ";
    }
    cout << "\n";
    cout << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
    cin >> t;
    for(int tt =1; tt  <= t; tt++){
        solve(tt);
    }
}

