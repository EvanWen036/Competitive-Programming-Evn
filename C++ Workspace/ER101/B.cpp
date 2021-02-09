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
	int n;
	cin >> n;
	vector<int> r(n);
	int s1[n];
	memset(s1, 0, sizeof(s1));
	for(int i = 0; i < n;i ++){
		cin >> r[i];
		s1[i] = r[i];
		if(i > 0){
			s1[i] += s1[i-1];
		}
	}
	int m;
	cin >> m;
	vector<int> b(m);
	int s2[m];
	memset(s2,0,sizeof(s2));
	for(int i = 0; i < m;i ++){
		cin >> b[i];
		s2[i] = b[i];
		if(i > 0){
			s2[i] += s2[i-1];
		}
	}
	sort(s1, s1 + n);
	sort(s2, s2 + m);
	cout << max(max(s1[n-1],s2[m-1]),max(0,s1[n-1]+s2[m-1])) << '\n';

}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)solve();


}
