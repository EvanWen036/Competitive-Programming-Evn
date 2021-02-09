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
    long long n;
    cin >> n;
    //cout << n << "\n";
    long long ans = 1;
    for(int i = 0; i < n/2; i++){
        //cout << n-i << " ";
        ans *= n-i;
        //ans /= i+1;
    }
   //cout << ans << "\n";
    long long temp = 1;
    for(int i =0; i < n/2; i++){
        temp *= (i+1);
    }
    ans /= temp;
    //cout << ans << "\n";
    ans /= 2;
    for(int i = 2; i <= (n/2)-1; i++){
        ans *= i*i;
    }
    cout << ans;

}

