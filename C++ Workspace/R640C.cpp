#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        cout << k + (k/(n-1)) + ((k + (k/(n-1)))%n == 0 ? -1:0)  << endl;

    }


}

