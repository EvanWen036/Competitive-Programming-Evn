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
	int n;
	cin >> n;
	if(n == 3 || n == 2){
		cout << "NO SOLUTION";
		return 0;
	}
	if(n == 4){
		cout << "2 4 1 3";
		return 0;
	}
	int og = n-1;
	while(n > 0){
		cout << n << " ";
		n -= 2;
	}
	while(og > 0){
		cout << og << " ";
		og -= 2;
	}



}
