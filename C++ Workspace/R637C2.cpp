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
        map<int, int> pos;
        for(int i = 0; i < n;i ++){
            int a;
            cin >> a;
            pos[a] = i;
        }
        int next[n+1];
        int size[n+1];
        multiset<int> sizes;
        for(int i = 0; i < n; i++){
            next[i] = i;
            size[i] = 1;
            sizes.insert(1);
        }
        next[n] = -1;
        int maxSize = 1;
        bool done = false;
        
        for(int i = 1; i <= n; i++){
            for(int i = 0; i < n; i++){
                cout << next[i] << " ";
            }
            cout << "\n";
            if(size[pos[i]] < maxSize){
                done = true;
                cout << "No" << endl;
                break;
            }
            
            
            if(next[pos[i]+1] != -1){
                sizes.erase(sizes.find(size[next[pos[i]+1]]));
                sizes.erase(sizes.find(size[next[pos[i]]]));
                size[next[pos[i]+1]]+=size[next[pos[i]]];
                sizes.insert(size[next[pos[i]]]-1);
                sizes.insert(size[next[pos[i]+1]]);
                maxSize = max(maxSize, *--sizes.end());
                next[pos[i]] = next[pos[i]+1];
            }
            else{
                size[next[pos[i]]]--;
                next[pos[i]] = -1;
                sizes.erase(sizes.find(size[next[pos[i]]]));
                sizes.insert(size[next[pos[i]]]-1);
                
            }
        }
        if(!done){
            cout << "Yes" << endl;
        }
    }   
}




