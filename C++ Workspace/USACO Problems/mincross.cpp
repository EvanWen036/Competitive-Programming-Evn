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
    freopen("mincross.in", "r", stdin);
    freopen("mincross.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    
    map<int, int> mp;
    int A[N];
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        A[i] = a;
        mp[a] = i;
    }
    vector<int> P(N);
    map<int, int> mp2;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a; 
        mp2[a] = i;
        P[i] = mp[a];
        //cout << P[i] << endl;
    }
    /**
    for(int i = 0; i < N; i++){
        cout << P[i] << endl;
    }
    **/
    int zeroes[N];
    memset(zeroes, 0, sizeof(zeroes));
    
    build(zeroes, 1, 0, N-1);
    //update(1, 0, N-1, 2, 5);
    //cout << t[2] << endl;
    ll inversions = 0;
    for(int i = 0; i < N; i++){
        inversions += sum(1, 0, N-1, P[i], N-1);
        update(1, 0, N-1, P[i], 1);
        
    }
    //cout << inversions << endl;
    ll ans = inversions;
    for(int i = N-1; i >= 0; i--){
        inversions -= (N-1)-P[i];
        inversions += P[i];
        ans = min(ans, inversions);
    }
    build(zeroes, 1, 0, N-1);
    vector<int> P2(N);
    for(int i =0; i < N; i++){
        P2[i] = mp2[A[i]];
        //cout << P2[i] << endl;
    }
    inversions = 0;
    for(int i = 0; i < N; i++){
        inversions += sum(1,0,N-1, P2[i], N-1);
        update(1,0,N-1, P2[i], 1);
    }
    ans = min(ans, inversions);
    for(int i = N-1; i >= 0; i--){
        inversions -= (N-1)-P2[i];
        inversions += P2[i];
        ans = min(ans, inversions);
    }
    cout << ans << endl;
    

}

