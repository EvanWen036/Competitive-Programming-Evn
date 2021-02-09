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
	vector<int> a(n);
	int s = 0;
	int ones = 0;
	int twos = 0;
	for(int i = 0; i < n;i ++){
		cin >> a[i];
		if(a[i] == 1)ones++;
		else{twos++;}
	}
	if(twos % 2 == 0 && ones % 2 == 0){
		cout << "Yes\n";
		return;
	}
	if(ones >= 2){
		ones -= 2;
		twos++;
		if(twos % 2 == 0 && ones % 2 ==0){
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)solve();


}
