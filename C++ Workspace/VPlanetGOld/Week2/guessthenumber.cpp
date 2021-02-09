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
	int lo = 1;
	int hi = 1000000;
	while(lo < hi){
		int mid = (lo+hi+1)/2;
		cout << mid << '\n';
		fflush(stdout);
		string response;
		cin >> response;
		if(response == ">="){
			lo = mid;
		}
		else{
			hi = mid-1;
		}
	}
	cout << "! " << lo << '\n';
	fflush(stdout);
}
