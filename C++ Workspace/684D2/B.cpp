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
void solve(){

	ll n, k;
	cin >> n >> k;
	vector<ll> A(n*k+1);
	for(int i = 1; i <= n*k; i++){
		cin >> A[i];
	}
	ll temp1 = 0;
	for(int i = 1;i <= n*k;i += n){
		temp1 += A[i];
	}
	ll temp2 = 0;
	if(n == 2 || n==1){
		cout << temp1 << '\n';
		return;
	}
	int mid = (n+1)/2;
	for(int i = n*k - (n-mid); i > k * (mid-1); i-= (n-mid+1)){
		temp2 += A[i];
	}
	cout << max(temp1, temp2) << '\n';

}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}


}
