#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, W;
    cin >> N >> W;
    vector<int> xVal;
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        xVal.push_back(y);
    }
    set<int> inStack;
    stack<int> s;
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(inStack.count(xVal[i]) == 0){
            while(!s.empty() && s.top() > xVal[i]){
                int x = s.top();
                inStack.erase(x);
                s.pop();
            }
            if(xVal[i] != 0){
                inStack.insert(xVal[i]);
                s.push(xVal[i]);
                ans++;
            }
        }
    }
    cout << ans << endl;
    


}

