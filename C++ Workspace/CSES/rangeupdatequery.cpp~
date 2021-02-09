#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
ll BIT[2*100000 + 5];
void update(int idx, int val){
    for(int i = idx; i <= 200000; i+=i&-i){
        BIT[i] += val;
    }
}
ll query(int idx){
    ll sum = 0;
    for(int i = idx; i >= 1; i-=i&-i){
        sum += BIT[i];
    }
    return sum;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, Q;
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        update(i+1, x);
        update(i+2, -1 * x);
    }
    for(int i = 0; i < Q; i++){
        int o;
        cin >> o;
        if(o == 2){
            int a;
            cin >> a;
            cout << query(a) << endl;
        }
        else{
            int x, y, u;
            cin >> x >> y >> u;
            update(x, u);
            update(y+1, -1 * u);
        }
    }


}



