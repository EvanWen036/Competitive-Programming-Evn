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
    int N;
    cin >> N;
    ll MOD = 1000000007;
    ll pow = 2;
    ll fac = 1;
    for(ll i = 2; i <= N-1; i++){
        fac *= i;
        fac %= MOD;
        pow *= 2;
        pow %= MOD;
    }
    fac *= N;
    fac %= MOD;
    cout << (fac - pow+MOD)%MOD << endl;


}

