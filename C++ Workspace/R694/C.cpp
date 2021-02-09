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
	int n, m;
	cin >> n >> m;
	vector<int> k(n);
	vector<int> c(m);
	multiset<int> pres;
	for(int i = 0; i< n;i++){
		cin >> k[i];
		k[i]--;
	}
	for(int i = 0;i < m;i++){
		cin >> c[i]; 
		pres.insert({c[i]});
	}
	sort(k.begin(), k.end());
	reverse(k.begin(), k.end());
	ll cost = 0;
	for(int i = 0; i < n;i++){
		//pres.insert(c[i]);
		int present = 1e9;
		if(pres.size() > 0){
			present = *(pres.begin());
		}
		int mon = c[k[i]];
		if(present < mon){
			cost += present;
			pres.erase(pres.begin());
		}
		else{
			cost += mon;
		}
		//remove the ones you can't use anymore
		int curr = k[i];
		if(i == n-1)continue;
		while(i < n-1 && curr > k[i+1] && curr > 0){
			if(pres.find(c[curr]) != pres.end()){
				pres.erase(c[curr]);
			}
			curr--;
		}
		//cout << cost << '\n';
	}
	//bool given[m];

	cout << cost << '\n';
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)solve();


}
