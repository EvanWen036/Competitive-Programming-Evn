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
int l[100005];
int r[100005];
set<int> correct[100005];
int pos[100005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> A(N+1);
	for(int i=  0;i  < N;i ++){
		cin >> A[i];
		l[A[i]] = i;
		r[A[i]] = N-1- i;
		pos[A[i]] = i;
	}
	vector<int> B(N);
	for(int i =0 ;i < N;i ++){
		cin >> B[i];
	}
	for(int i = 0; i < N; i++){
		B.push_back(B[i]);
	}	
	for(int i = 0; i < 2*N;i ++){
		//if A[i] is in the right position
		if(i - pos[B[i]] >= 0){
			//cout << B[i] << " " << B[i-pos[B[i]]] << "\n";
			correct[B[i-pos[B[i]]]].insert(B[i]);
		} 
	}
	
	set<int> before;
	set<int> after;
	int ans = 1e9;
	int temp = 0;
	for(int i=  0; i < N; i++){
		if(i < pos[B[i]]){
			before.insert(B[i]);
		}
		else{
			after.insert(B[i]);
		}
		temp += abs(i - pos[B[i]]);
	}
	ans = min(ans, temp);
	for(int i = 1; i < N; i++){
		//this is the first element
		temp -= before.size();
		after.erase(B[i+N]);
		before.insert(B[i+N]);
		temp += after.size();
		temp -= r[B[i+N]];
		temp += l[B[i+N]];
		cout << temp << '\n';
		ans = min(ans, temp);
		for(auto it : correct[B[i]]){
			before.erase(it);
			after.insert(it);
		}
	}
	cout << ans << '\n';
}
