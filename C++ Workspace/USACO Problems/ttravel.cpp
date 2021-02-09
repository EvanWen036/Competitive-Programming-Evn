#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    map<int, int> par;
    map<int, int> pos;
    int r=1;
    int currentIndex = 0;
    for(int i = 0; i < N;i ++){
        string s;
        cin >> s;
        pos[i] = currentIndex;
        if(s == "a"){
            int x;
            cin >> x;
            int originalX = x;
            
           
            par[x] = currentIndex;
            currentIndex = x;
            cout << x << endl;
        }
        if(s == "s"){
            currentIndex = par[currentIndex];
            cout << (currentIndex != 0 ? currentIndex:-1)  << endl;
        }
        if(s == "t"){
            int x;
            cin >> x;
            currentIndex = pos[x-1];

            cout <<  (currentIndex != 0 ? currentIndex:-1) << endl;
        }
    }

}

