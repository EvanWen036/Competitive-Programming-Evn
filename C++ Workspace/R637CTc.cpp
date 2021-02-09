#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i ++){
        a[i] = i+1;
    }
    for(int i = 0; i < n;i ++){
        int ind = rand()%(n-1);
        swap(a[i], a[ind]);
    }
    for(int i = 0; i < n;i ++){
        cout << a[i] << " ";
    }


}

