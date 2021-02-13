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
#define int long long
int N, X, K;
const int maxN = 1e6+5;
int cst[maxN];
int d[maxN];
int sum[maxN];

bool ok(int c){
	int currSum = 0;
	multiset<int> poss;
	for(int i = 1; i <= c;i ++){
		currSum += d[i];
		if(i + K - 1 <= c){
			poss.insert(cst[i]);
		}
	}
	//cout << 1 << " " << c << " " << currSum << " " <<  *(--poss.end()) << " " << currSum - *(--poss.end()) << '\n';
	if(currSum - *(--poss.end()) <= X)return true;
	for(int i = 2; i+c-1 <= N; i++){
		//cout << i << " " << i+c-1 << " " <<  i+c-K << endl;
		//add and remove stuff
		
		poss.insert(cst[i + c - K]);
		poss.erase(poss.find(cst[i-1]));
		currSum += d[i+c-1];
		currSum -= d[i-1];
		//cout << i << " " << i + c- 1 << " " << currSum << " " <<  *(--poss.end()) << " " << currSum - *(--poss.end()) << '\n';
		if(currSum - *(--poss.end()) <= X)return true;
		
	}
	return false;
}
main(){
	freopen("robreplace.in", "r", stdin);
	freopen("robreplace.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> X >> K;
	for(int i = 1; i <= N;i ++){
		cin >> d[i];
		sum[i] = sum[i-1]+d[i];
	}
	for(int i = 1; i <= N;i ++){
		if(i + K - 1 <= N){
			cst[i] = sum[i+K-1]-sum[i-1];
			//cout << cst[i] << '\n';
		}
	}
	int lo = K;
	int hi = N;
	while(lo < hi){
		int mid = (lo+hi+1)/2;
		if(ok(mid)){
			//can try longer
			lo = mid;
		}
		else{
			hi = mid-1;
		}
	}
	cout << lo << '\n';

}
