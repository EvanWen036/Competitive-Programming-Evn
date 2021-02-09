#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int t[4*100000+5];
void build(int a[], int v, int l, int r){
    if(l == r){
        t[v] = a[l];
    }
    else{
        int mid = (l+r)/2;
        build(a,v*2,l, mid);
        build(a,v*2+1,mid+1,r);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int sum(int v, int lr, int rr, int l, int r){
    if(r < lr || l > rr || lr > rr)return 0;
    if(l <= lr && r >= rr){
        return t[v];
    }
    else{
        int tm = (lr + rr)/2;
        return sum(v*2,lr,tm,l,r) + sum(v*2+1, tm+1, rr, l, r);
    }
}
//update point p with val
void update(int v, int lr, int rr, int p, int val){
    //completely outside
    //cout << v << " " << lr << " " << rr << " " << p << " " << val << endl;
    if(p > rr || p < lr)return;
    
    if(lr == rr){
        t[v] += val;
        return;
    }
    int tm = (lr + rr)/2;
    //call on children
    update(2*v,lr,tm,p, val);
    update(2*v+1,tm+1,rr,p, val);
    t[v] = t[2*v] + t[2*v+1];
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N;
    int K; cin >> K;
    vector<int> prefix(N+1);
    prefix[0] = 0;
    for(int i = 1; i <= N; i++){
        int a;
        cin >> a;
        prefix[i] = prefix[i-1] + (a >= K ? 1:-1);
        //cout << prefix[i] << endl;
    }
    int zeroes[2*N+1]; memset(zeroes, 0, sizeof(zeroes));
    build(zeroes, 1, 0, 2*N);
    int inversions = 0;
    for(int i = 0; i <= N; i++){
        inversions += sum(1, 0, 2 * N, N+prefix[i]+1,2*N);
        //cout << inversiuns << endl;
        update(1,0,2*N, prefix[i]+N, 1);
    }
    cout << N*(N+1)/2 - inversions << endl;

}

