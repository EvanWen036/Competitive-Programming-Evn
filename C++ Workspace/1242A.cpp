#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    int og = n;
    vector<int> factors;
    for(int i =2; i*i <= n; i++){
        //cuut << i << endl;
        bool wrk = false;
        while(n%i == 0){
            wrk = true;
            n /= i;
        }

        if(wrk){
            factors.pb(i);
        }
    }
    if(n != 1)factors.pb(n);
    //cout << factors.size() << endl;
    if(factors.size() >= 2)cout << 1 << endl;
  //  cout << factors[0] << endl;
    if(factors.size() == 1)cout << factors[0] << endl;
    //else{cout << 1 << endl;}


}

