#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;
ll pow(ll a, ll b){
    if(b == 1)return a;
    if(b==0)return 1;
    if(b%2){
        return a * pow(a,b-1) % mod;
    }
    else{
        ll temp = pow(a,b/2) % mod;
        return temp*temp%mod;
    }
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll a, b, c;
        cin >> a >> b >> c;
        mod--;
        ll temp = pow(b,c);
        mod++;
        cout << pow(a,temp) % mod << endl;
    }


}

