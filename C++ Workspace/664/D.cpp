#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
 
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll N, D, M;
    cin >> N >> D >> M;
    vector<ll> A;
    vector<ll> B;
    for(int i = 0; i < N; i++){
        //cin >> A[i];
        int x;
        cin >> x;
        if(x > M){
            B.pb(x);
        }
        else{
            A.pb(x);
        }
    }
    //int maxMuzzled = N/(D+1);
    sort(A.begin(), A.end(), greater <int>());
    sort(B.begin(), B.end(), greater <int>());
    vector<ll> prefix(A.size());
    //prefix.pb(A.back());
    for(auto it : A){
        //cout << it << endl;
    }
    ll sum = 0;
    if(A.empty()){
        for(int i = 1; i <= B.size(); i++){
            ll space = (i-1)*(D+1) + 1;
            if(space > N)break;
            sum += B[i-1];
        }
        cuut << sum << endl;
        return 0;

    }
    prefix[0] = A[0];
    for(int i =1; i < A.size() ; i++){
        prefix[i] = prefix[i-1];
        prefix[i] += A[i];
        //cout << prefix[i] << endl;
    }
    //cout << prefix.size() << endl;
    ll ans = 0;
    sum = 0;
    //if(prefix.s
    for(int i = 0; i <= B.size(); i++){
        //cout << i << endl;
        //try to pick i big numbers
        if(i == 0){
            ans = max(ans, prefix[prefix.size()-1]); 
        }
        else{
            ll space = (i-1) * (D+1)+1;
            //cout << i << " " << space << endl;
            if(space > N)continue;
            //cuut << i << " " << space << " " << prefix[min((int)prefix.size()-1, N-space-1)] << " " << sum << endl;
            if(N-space-1 < 0){
                ans = max(ans, sum);
            }
            else{
                ans = max(ans, sum + prefix[min((ll)prefix.size()-1,N-space-1)]);
            }
         }
        if(i == B.size())break;
        sum += B[i];
        
    }
    cout << ans << endl;
}
