#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    oset<pii> set;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        set.insert(mp(i,x));
    }
    for(int i = 0; i < n; i++){
        int pos;
        cin >> pos; pos--;
        int val = (*set.find_by_order(pos)).s;
        cout << val << " ";
        set.erase(set.find_by_order(pos));
    }


}

