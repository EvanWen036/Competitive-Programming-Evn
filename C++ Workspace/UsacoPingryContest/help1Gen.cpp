#include <bits/stdc++.h>
#include "testlib.h"
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

int main(int argc, char* argv[]){

	registerGen(argc, argv, 1);
	int n = atoi(argv[1]);
	cout << n << endl;
	for(int i = 0; i < n;i ++){
		cout << rnd.next(1, 1000);
		if(i != n-1){
			cout << " ";
		}
	}
	cout << endl;


}
