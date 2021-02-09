#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){

	//ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	cout << N;
	for(int i = 1; i<= N;i ++){
		cout << " " << i; 
	} 
	cout << '\n';
	fflush(stdout);
	int C;
	cin >> C;
	vector<int> pref(C+1);
	vector<int> ans(N+1);
	for(int i = C;i >= 1; i--){
		//binary search for where the first prefix that has i distinct
		int lo = 1;
		int hi = N;
		while(lo < hi){
			int mid = (lo+hi)/2;
			cout << mid;
			for(int j = 1; j <= mid;j ++){
				cout << " " << j;
			}
			cout << '\n';
			fflush(stdout);
			int amt; 
			cin >> amt;
			if(amt < i){
				//more distinct needed
				lo = mid+1;
			}
			else{
				hi = mid;
			}
			
		}
		pref[i] = lo;
	}
	for(int i = 1;i <= C; i++){
		ans[pref[i]] = i;
		//cout << pref[i] << '\n';
	}
	int ptr = 1;
	for(int i = 1;i <= N;i ++){
		if(i >= pref[ptr])ptr++;
		if(ans[i] == 0){
			for(int j = 1; j <= ptr; j++){
				cout << 2 << " " << pref[j] << " " << i << '\n';
				fflush(stdout);
				int curr;
				cin >> curr;
				if(curr == 1){
					ans[i] = j;
					break;
				}
			}
		}
	}
	cout << 0;
	for(int i = 1; i<=N;i ++){
		cout << " " << ans[i];
	}
	cout << '\n';
	fflush(stdout);
}
