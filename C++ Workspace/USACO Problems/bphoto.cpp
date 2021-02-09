#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int BIT[100005];
void update(int ind, int addVal){
    for(int i = ind; i <= 100000; i += i&-i){
        BIT[i] += addVal;
    }
}
int query(int ind){
    int sum = 0;
    for(int i = ind; i >= 1; i -= i & -i){
        sum += BIT[i];
    }
    return sum;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for(int i =0; i < N; i++){
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B.begin(), B.end());
    map<int, int> mp;
    int x= 1;
    for(int i =0; i < N; i++){
        mp[B[i]] = x;
        //cout << A[i] << " " << mp[A[i]] << endl;
        x++;
    }
    memset(BIT, 0, sizeof(BIT));
    int l[N];
    //cout << query(100000);
    for(int i=  0; i < N;i ++){
        l[i] = query(100000)-query(mp[A[i]]);
        //cout << A[i] << " " << mp[A[i]] << endl;
        update(mp[A[i]], 1);
        //cout << l[i] << endl;
    
    }


    memset(BIT, 0, sizeof(BIT));
    int r[N];
    for(int i= N-1; i>= 0; i--){
        r[i] = query(100000)-query(mp[A[i]]);
        
        update(mp[A[i]], 1);
    }
    int ans = 0;
    for(int i = 0;i < N;i ++){
        if(l[i] * 2 < r[i] || r[i] * 2 < l[i]){
            ans++;
        }
    }
    cout << ans << endl;


}

