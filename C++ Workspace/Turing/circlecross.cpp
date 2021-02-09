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
    for(int i = idx; i <= 100000; i += i & -i){
        BIT[i] += val;
    }
}
int query(int idx){
    int s = 0;
    for(int i = idx; i >= 1; i -= i & -i){
       s  += BIT[i];
    }
    return s;
}
int current[100005];
int firstPos[100005];
int secondPos[100005];
int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        firstPos[i] = -1;
    }
    for(int i= 1; i <= 2 * N; i++){
        int a;
        cin >> a;
        current[i] = a;
        if(firstPos[a] == -1){
            firstPos[a] = i;
        }
        else{
            secondPos[a] = i;
        }
    }
    for(int i = 1; i <= N;i ++){
        update(firstPos[i], 1);
        update(secondPos[i], -1);
    }
    int ans = 0;
    for(int i = 1; i <= 2 * N; i++){
        if(i == firstPos[current[i]]){
            //first time we see this cow
            ans += query(secondPos[current[i]]) - query(firstPos[current[i]]-1);
            update(secondPos[current[i]], 1);
        }
        
    }
    cout << ans << "\n";

}

