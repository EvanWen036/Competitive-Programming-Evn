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
        int n;
        int a;
        int b;
        int c;
        int d;
        cin >> n >> a >>b >> c >> d;
        int lowP = c-d;
        int highP = c+d;
        int r1 = a-b;
        int r2 = a+b;
        if((double)lowP/n > r2 || (double)highP/n < r1){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }


}

