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
	int N;
	cin >> N;
	vector<int> A(2 * N);
	vector<int> sorted;
	map<int,int> pos;
	for(int i = 0; i < 2 * N;i ++){
		cin >> A[i];
		sorted.pb(A[i]);
		pos[A[i]] = i;
	}
	sort(sorted.begin(), sorted.end());
	map<int, int> pairing;
	for(int i = 0; i < 2*N;i ++){
		pairing[A[i]] = sorted[2*N-i-1];
		//cout << A[i] << " " << pairing[A[i]] << "\n";
	}
	int ans = 0;
	for(int i = 0; i < 2* N; i+=2){
		if(A[i+1] != pairing[A[i]]){
			ans++;
			swap(A[i+1], pos[pairing[A[i]]]);
		}
	}
	cout << ans << "\n";
 
}