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
    vector<int> a(n);
    map<int,  int> cnt;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    //int maxNumber = (*(--cnt.end())).first;
    //int maxAmt = cnt[maxNumber];
    int maxAmt = 0;
    for(int i = 1; i <= 1e5; i++){
        if(cnt[i] % 2 == 1){
            cout << "Conan" << "\n";
            return 0;
        }
    }
    cout << "Agasa";


}

