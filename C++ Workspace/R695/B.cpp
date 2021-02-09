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
bool valley[300005];
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int amt = 0;
	for(int i = 1; i < n-1; i++){
		if(a[i] > a[i-1] && a[i] > a[i+1])amt++;
		if(a[i] < a[i-1] && a[i] < a[i+1])amt++;
	}
	int ans = amt;
	for(int i = 1; i < n-1; i++){
		int temp = a[i];
		a[i] = a[i-1];
		int changed = 1;
		if(i >= 2){
			if(a[i-2] > a[i-1] && a[i] <= a[i] && temp > a[i-1])changed++;
			else if(a[i-2] < a[i-1] && a[i] >= a[i-1] && temp < a[i-1])changed++;
		}
		if(i + 2 < n){
			if()
		}
		ans = max(ans, amt-changed);
	}

}
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)solve();
 
 
}