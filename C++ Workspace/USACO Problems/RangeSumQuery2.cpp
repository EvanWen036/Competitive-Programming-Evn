#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
ll BIT[200005];
int MAXVAL = 200004;
void update(int ind, int addValue){
    for(int i = ind; i <= MAXVAL; i += i&-i){
        BIT[i] += addValue;
    }
}
ll query(int ind){
    ll sum = 0;
    for(int i = ind; i >= 1; i -= i & -i){
        sum += BIT[i];
    }
    return sum;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int Q;
    cin >> N >> Q;
    memset(BIT, 0, sizeof(BIT));
    int array[N];
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        array[i] = x;
        update(i+1, x);
    }
    for(int i = 0; i < Q; i++){
        int cmd;
        cin >> cmd;
        if(cmd == 2){
            int a, b;
            cin >> a >> b;
            cout << query(b)-query(a-1) << endl;
        }
        else{
            int a, b;
            cin >> a >> b;
            update(a, b-array[a-1]);
            array[a-1] = b;
        }
    }
}

