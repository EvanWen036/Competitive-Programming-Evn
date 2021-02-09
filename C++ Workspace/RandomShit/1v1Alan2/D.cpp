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
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll x, y, n;
    cin >> x >> y >> n;
    //x += mod;
    //y += mod;
    ll mod = 1e9+7;
    n %= 6;   
    if(n == 1){
        cout << (x+mod)%mod;
    }
    else if(n == 2){
        cout << (y + 2*mod)%mod;
    }
    else if(n == 3){
        cout << (y-x + 2*mod)%mod;
    }
    else if(n == 4){
        cout << (0 - x + 2*mod)%mod;
    }
    else if(n == 5){
        cout << (0 - y + 2*mod)%mod;
    }
    else{
        cout << (0-(y-x) + 2*mod)%mod;
    }
}

