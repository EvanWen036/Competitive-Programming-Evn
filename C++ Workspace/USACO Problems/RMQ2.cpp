#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int st[4*2*100002];
void build(int a[], int k, int l, int r){
    if(l == r){
        st[k] = a[l];
        return;
    }
    int tm = (l+r)/2;
    build(a, 2*k, l, tm);
    build(a, 2*+1,tm+1, r);
    st[k] = min(st[2*k], st[2*k+1]);
}
int query(int k, int l, int r, int i, int j){
    if(l > i || r < i)return 1e9 + 10000;
    if(l >= i && r <= j)return st[k];
    int tm = (l+r)/2;
    return min(query(2*k,l, tm, i, j), query(2*k+1, tm+1, r, i, j));
}

void update(int k, int l, int r, int i, int j){
    //cout << k << " " << l << " " << r << " " << i << " " << j << endl;
    if(l > i || r < i)return;
    if(l == r){
        st[k] = j;
        return;
    }
    int tm = (l+r)/2;
    update(2*k, l, tm, i , j);
    update(2*k+1, tm+1, r, i , j);
    st[k] = min(st[2*k], st[2*k+1]);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    int Q;
    cin >> Q;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    build(A, 1, 0, N-1);
    for(int i = 0; i < Q; i++){
        int cmd;
        cin >> cmd;
        if(cmd == 2){
            int a, b;
            cin >> a >> b;
            a--; b--;
            cout << query(1, 0, N-1, a, b) << "\n";
        }
        else{
            int a, b;
            cin >> a >> b;
            a--; b;
            update(1, 0, N-1, a, b);
        }
    }


}

