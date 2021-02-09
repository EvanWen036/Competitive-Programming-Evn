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
int BIT[100005];
void update(int idx, int val){
    for(int i = idx; i <= 100000; i+= i&-i){
        BIT[idx]+=val;
    }
}
int query(int idx){
    int sum = 0;
    for(int i = idx; i >= 1; i -= i & -i){
        sum += BIT[i];
    }
    return sum;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> a(N+1);
    cout << "test\n";
    for(int i = 1; i <= N;i ++){
        cin >> a[i];
    }
    multiset<int> values;
    vector<pii> empodia;
    for(int i = 1; i <= N;i ++){
        values.insert(a[i]);
        update(a[i]+5, 1);
        for(int j = i+1; j <= N; j++){
            values.insert(a[j]);
            if(values.count(a[j]) == 1){
                update(a[j]+5, 1);
                //cout << a[j] << "\n";
            }
            cout << *(--values.end()) << " " << *values.begin() << " " << values.size() << " " << query(a[j]+5) << " " << query(a[i]+4) << "\n";
            if(*(--values.end()) == a[j] && *values.begin() == a[i] && values.size() == j-i+1 && query(a[j]+5) - query(a[i]+4) == j-i+1){
                empodia.pb(mp(i,j));
                break;
            }
        }
        memset(BIT,0,sizeof(BIT)); 
        values.clear();
    }
    cout << empodia.size() << "\n";
    for(pii u : empodia){
        cout << u.f << " " << u.s << "\n";
    }
}

