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
        cin >> n;
        int pyramidSize = 0;
        int d = 1;
        
        while(true){
            pyramidSize += d;
            if(n < pyramidSize){
                pyramidSize -= d;
                d-=2;
                break;
            }
            d+=2;
        }
        cout << pyramidSize << endl;
        int total = 0;
        while(n - pyramidSize >= 0){
            n -= pyramidSize;
            total++;
            pyramidSize -= d;
            if(pyramidSize <= 0)break;
            d-=2;
                    }
        cout << total << endl;
         
    }


}

