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
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int aPos = 0;
        int bPos = n-1;
        int aSum = 0;
        int bSum = 0;
        int prevTurn = 0;
        bool turn = false;
        aSum += a[0];
        aPos++;
        prevTurn = a[0];
        int moves = 0;
        while(aPos <= bPos){
            int currTurn = 0;
            //cout << aSum << " " << bSum<< " " << turn << endl;
            while(currTurn <= prevTurn && aPos <= bPos){
                if(turn){
                    currTurn += a[aPos];
                    aSum += a[aPos];
                    aPos++;
                }
                if(turn == false){
                    currTurn += a[bPos];
                    bSum += a[bPos];
                    bPos++;
                }
            }
            prevTurn = currTurn;
            moves++;
            if(turn == true)turn = false;
            else if(turn == false)turn = true;
        }
        cout << ++moves << " " << aSum << " " << bSum << endl;
    }


}

