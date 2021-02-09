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
int middle(int K){
    if(K%2 == 0){
        return K/2-1;
    }
    return K/2;
}
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    oset<pair<int,int>> set;
    for(int i = 0; i < K;i ++){
        set.insert(mp(A[i],i));    
    }
    int prevMedian = (*(set.find_by_order(middle(K)))).first;
    ll cost = 0;
    for(int i = 0; i < K; i++){
        cost += abs(A[i] - prevMedian);
    }
    cout << cost << " ";
    for(int j = K; j < N; j++){
        set.erase(mp(A[j-K], j-K));
        set.insert(mp(A[j], j));
        //subtract cost out of previous one
        ll newMedian = (*(set.find_by_order(middle(K)))).first;
        cost -= abs(prevMedian - A[j-K]);
        cost += abs(A[j] - newMedian);
        ll belowMedian = middle(K);   
        ll aboveMedian = K-(middle(K))-1;
        //cout << j << " " << prevMedian << " " << belowMedian << " " << aboveMedian << endl;
        if(newMedian > prevMedian){
            
            cost -= aboveMedian * (newMedian - prevMedian);
            cost += belowMedian * (newMedian - prevMedian);
        }
        if(newMedian < prevMedian){
            cost -= belowMedian * (prevMedian - newMedian);
            cost += aboveMedian * (prevMedian - newMedian);
        }
        //cout << (*(set.find_by_order(middle(K)))).first << " ";
        cout << cost << " ";
        prevMedian = newMedian;
    }
 
 
}
