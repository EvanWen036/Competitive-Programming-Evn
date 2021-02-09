#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
int arr[100005];
int bit[100005];
void update(int addValue, int index){
    for(int i = index; i <= 2*N; i += i & -i){
        bit[i] += addValue;
    }
}
int query(int index){
    int sum = 0;
    for(int i = index; i >= 1; i-= i & -i){
        sum += bit[i];
    }
    return sum;
}
int main(){


	cin >> N;
    int firstPos[N+1];
    int secondPos[N+1];
    bool seen[N+1];
    memset(seen, false, sizeof(seen));
    int arr[2*N];
    for(int i = 0; i < 2* N; i++){
        cin >> arr[i];
        if(seen[arr[i]]){
            secondPos[arr[i]] = i+1;
        }
        else{
            firstPos[arr[i]] = i+1;
            seen[arr[i]] = true;
        }
    }
    
   // cout << "Hi" << endl;
    for(int i = 1; i <= N; i++){
       // cout << firstPos[i] << " " << secondPos[i] << endl;
        update(1, firstPos[i]);
        update(-1, secondPos[i]);
    }
    //cout << "Hi" << endl; 
    int ans = 0;
    for(int i = 0; i < 2 * N; i++){
        if(i+1 == firstPos[arr[i]]){
            ans += query(secondPos[arr[i]])-query(firstPos[arr[i]]-1);
            update(1, secondPos[arr[i]]);
        }
    }
    cout << ans << endl;
   
        

}

