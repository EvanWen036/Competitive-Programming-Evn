#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){

        int a,b,c;
        cin >> a >> b >> c;
        int b1 = 0;
        while(b1 < b && a > 20){
            //cout << a << endl;
            if(b1 < b){
                a = a/2  + 10;
                b1++;
            }
        }
        cout << (a <= 0 ? "YES":"NO");
    }


}

