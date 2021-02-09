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
    int a, b;
    cin >> a >> b;
    int mod = 1e9+7;
    if(b == 1){
        cout << 0 << "\n";
        return 0;
    }
    ll temp = (a/2) * (2*b + b*a - b);
    temp %= mod;
    cout << (a+temp)%mod<< "\n";



}

