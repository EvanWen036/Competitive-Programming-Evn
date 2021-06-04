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
vector<int> v;
const int maxA = 1e7+5;
ll psum[maxA];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> a(N);
	for(int i = 0;i  < N;i ++){
		cin >> a[i];
		psum[a[i]]++;
	}
	for(int i = 1; i <= 1e7;i ++){
		psum[i] += psum[i-1];
	}
	ll ans = 0;
	for(int i = 1; i <= 1e6;i ++){
		int start = i;
		int end = 2*i-1;
		//cout << i << '\n';
		//cout << start << " " << end << " " << psum[end]-psum[start-1] << '\n';
		//case 1: 1 is the only odd 
		if((psum[end]-psum[start-1])%2 == 1){
			bool good = true;
			while(end + 1 <= 1e6){
				start = end+1;
				end = start + i -1;
				if((psum[end]-psum[start-1])%2 == 1)good = false;
			}
			if(good){
				ans += (psum[2*i-1]-psum[i-1]);
			}
		}
		//case 2: there are two odds next to each other
		vector<int> odds;
		int cnt = 1;
		start = i;
		end = 2*i-1;
		while(start <= 1e6){
			if((psum[end]-psum[start-1])%2 == 1){
				odds.pb(cnt);
			}
			start = end+1;
			end = start + i-1;
			cnt++;
		}
		if(odds.size() == 2){
			if(odds[0]+1 == odds[1]){
				//cout << i << '\n';
				assert(odds[1] >= odds[0]);
				ans += psum[i*odds[1]+i-1]-psum[i*odds[1]-1];
			}
		}
		//cout << ans << '\n';
		
	}
	cout << ans << '\n';

}
