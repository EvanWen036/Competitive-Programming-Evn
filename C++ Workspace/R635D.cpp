#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll calc(ll a, ll b, ll c){
    return 1LL*(a-b)*(a-b) + 1LL*(b-c)*(b-c) + 1LL*(c-a)*(c-a);
}
int main(){

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll nr, ng, nb;
        cin >> nr >> ng >> nb;
        set<ll> r;
        set<ll> g;
        set<ll> b;
        for(int i = 0; i < nr; i++){
            ll a;
            cin >> a;
            r.insert(a);
        }
        for(int i = 0; i < ng; i ++){
            ll x;
            cin >> x;
            g.insert(x);
        }
        for(int i = 0; i < nb ;i ++){
            ll y;
            cin >> y;
            b.insert(y);
        }
        ll ans =9223372036854775807;    
        for(ll red : r){
            auto it = g.lower_bound(red);
            auto it2 = g.upper_bound(red);
            if(it != g.begin() || (*it == red)){
                if(*it > red || it == g.end()){
                    it--;
                }
                auto it3 = b.lower_bound((red+*it)/2);
                auto it4 = b.upper_bound((red+*it)/2);
                //cout << red << " " << *it << " " <<  *it2 <<  " " << *it3 << endl;
                //cout << red << " " << *it << " " << *it2 << " " << *it4 << endl;
                if(it3 != b.begin() || *it3 == (red+*it)/2){
                    if(*it3 > (red+*it)/2 || it3 == b.end()){
                        it3--;
                    }
                    ans = min(ans, calc(red, *it, *it3));
                }
                if(it4 != b.end()){
                    ans = min(ans, calc(red, *it, *it4));
                }
            }
            if(it2 != g.end()){
                auto it3 = b.lower_bound((red+*it2)/2);
                auto it4 = b.upper_bound((red**it2)/2);
                //cout << red << " " << *it << " " <<  *it2 <<  " " << *it3 << endl;
                //cout << red << " " << *it << " " << *it2 << " " << *it4 << endl;

                if(it3 != b.begin() || (*it3 == (red+*it2)/2)){
                    if(*it3 > (red+*it2)/2 || it3 == b.end()){
                        it3--;
                    }
                    ans = min(ans, calc(red, *it, *it3));
                }
                if(it4 != b.end()){
                    ans = min(ans, calc(red, *it, *it4));
                }
            }
        }
        swap(g, b);
        for(ll red : r){
            auto it = g.lower_bound(red);
            auto it2 = g.upper_bound(red);
            if(it != g.begin() || (*it == red)){
                if(*it > red || it == g.end()){
                    it--;
                }
                auto it3 = b.lower_bound((red+*it)/2);
                auto it4 = b.upper_bound((red+*it)/2);
                //cout << red << " " << *it << " " <<  *it2 <<  " " << *it3 << endl;
                //cout << red << " " << *it << " " << *it2 << " " << *it4 << endl;
                if(it3 != b.begin() || *it3 == (red+*it)/2){
                    if(*it3 > (red+*it)/2 || it3 == b.end()){
                        it3--;
                    }
                    ans = min(ans, calc(red, *it, *it3));
                }
                if(it4 != b.end()){
                    ans = min(ans, calc(red, *it, *it4));
                }
            }
            if(it2 != g.end()){
                auto it3 = b.lower_bound((red+*it2)/2);
                auto it4 = b.upper_bound((red**it2)/2);
                //cout << red << " " << *it << " " <<  *it2 <<  " " << *it3 << endl;
                //cout << red << " " << *it << " " << *it2 << " " << *it4 << endl;

                if(it3 != b.begin() || (*it3 == (red+*it2)/2)){
                    if(*it3 > (red+*it2)/2 || it3 == b.end()){
                        it3--;
                    }
                    ans = min(ans, calc(red, *it, *it3));
                }
                if(it4 != b.end()){
                    ans = min(ans, calc(red, *it, *it4));
                }
            }
        }
       swap(r,g);
       for(ll red : r){
            auto it = g.lower_bound(red);
            auto it2 = g.upper_bound(red);
            if(it != g.begin() || (*it == red)){
                if(*it > red || it == g.end()){
                    it--;
                }
                auto it3 = b.lower_bound((red+*it)/2);
                auto it4 = b.upper_bound((red+*it)/2);
                //cout << red << " " << *it << " " <<  *it2 <<  " " << *it3 << endl;
                //cout << red << " " << *it << " " << *it2 << " " << *it4 << endl;
                if(it3 != b.begin() || *it3 == (red+*it)/2){
                    if(*it3 > (red+*it)/2 || it3 == b.end()){
                        it3--;
                    }
                    ans = min(ans, calc(red, *it, *it3));
                }
                if(it4 != b.end()){
                    ans = min(ans, calc(red, *it, *it4));
                }
            }
            if(it2 != g.end()){
                auto it3 = b.lower_bound((red+*it2)/2);
                auto it4 = b.upper_bound((red**it2)/2);
                //cout << red << " " << *it << " " <<  *it2 <<  " " << *it3 << endl;
                //cout << red << " " << *it << " " << *it2 << " " << *it4 << endl;

                if(it3 != b.begin() || (*it3 == (red+*it2)/2)){
                    if(*it3 > (red+*it2)/2 || it3 == b.end()){
                        it3--;
                    }
                    ans = min(ans, calc(red, *it, *it3));
                }
                if(it4 != b.end()){
                    ans = min(ans, calc(red, *it, *it4));
                }
            }
        }
        swap(b,g);
          for(ll red : r){
            auto it = g.lower_bound(red);
            auto it2 = g.upper_bound(red);
            if(it != g.begin() || (*it == red)){
                if(*it > red || it == g.end()){
                    it--;
                }
                auto it3 = b.lower_bound((red+*it)/2);
                auto it4 = b.upper_bound((red+*it)/2);
                //cout << red << " " << *it << " " <<  *it2 <<  " " << *it3 << endl;
                //cout << red << " " << *it << " " << *it2 << " " << *it4 << endl;
                if(it3 != b.begin() || *it3 == (red+*it)/2){
                    if(*it3 > (red+*it)/2 || it3 == b.end()){
                        it3--;
                    }
                    ans = min(ans, calc(red, *it, *it3));
                }
                if(it4 != b.end()){
                    ans = min(ans, calc(red, *it, *it4));
                }
            }
            if(it2 != g.end()){
                auto it3 = b.lower_bound((red+*it2)/2);
                auto it4 = b.upper_bound((red**it2)/2);
                //cout << red << " " << *it << " " <<  *it2 <<  " " << *it3 << endl;
                //cout << red << " " << *it << " " << *it2 << " " << *it4 << endl;

                if(it3 != b.begin() || (*it3 == (red+*it2)/2)){
                    if(*it3 > (red+*it2)/2 || it3 == b.end()){
                        it3--;
                    }
                    ans = min(ans, calc(red, *it, *it3));
                }
                if(it4 != b.end()){
                    ans = min(ans, calc(red, *it, *it4));
                }
            }
        }
        swap(r,g);
       for(ll red : r){
            auto it = g.lower_bound(red);
            auto it2 = g.upper_bound(red);
            if(it != g.begin() || (*it == red)){
                if(*it > red || it == g.end()){
                    it--;
                }
                auto it3 = b.lower_bound((red+*it)/2);
                auto it4 = b.upper_bound((red+*it)/2);
                //cout << red << " " << *it << " " <<  *it2 <<  " " << *it3 << endl;
                //cout << red << " " << *it << " " << *it2 << " " << *it4 << endl;
                if(it3 != b.begin() || *it3 == (red+*it)/2){
                    if(*it3 > (red+*it)/2 || it3 == b.end()){
                        it3--;
                    }
                    ans = min(ans, calc(red, *it, *it3));
                }
                if(it4 != b.end()){
                    ans = min(ans, calc(red, *it, *it4));
                }
            }
            if(it2 != g.end()){
                auto it3 = b.lower_bound((red+*it2)/2);
                auto it4 = b.upper_bound((red**it2)/2);
                //cout << red << " " << *it << " " <<  *it2 <<  " " << *it3 << endl;
                //cout << red << " " << *it << " " << *it2 << " " << *it4 << endl;

                if(it3 != b.begin() || (*it3 == (red+*it2)/2)){
                    if(*it3 > (red+*it2)/2 || it3 == b.end()){
                        it3--;
                    }
                    ans = min(ans, calc(red, *it, *it3));
                }
                if(it4 != b.end()){
                    ans = min(ans, calc(red, *it, *it4));
                }
            }
        }
        swap(g,b);
        for(ll red : r){
            auto it = g.lower_bound(red);
            auto it2 = g.upper_bound(red);
            if(it != g.begin() || (*it == red)){
                if(*it > red || it == g.end()){
                    it--;
                }
                auto it3 = b.lower_bound((red+*it)/2);
                auto it4 = b.upper_bound((red+*it)/2);
                //cout << red << " " << *it << " " <<  *it2 <<  " " << *it3 << endl;
                //cout << red << " " << *it << " " << *it2 << " " << *it4 << endl;
                if(it3 != b.begin() || *it3 == (red+*it)/2){
                    if(*it3 > (red+*it)/2 || it3 == b.end()){
                        it3--;
                    }
                    ans = min(ans, calc(red, *it, *it3));
                }
                if(it4 != b.end()){
                    ans = min(ans, calc(red, *it, *it4));
                }
            }
            if(it2 != g.end()){
                auto it3 = b.lower_bound((red+*it2)/2);
                auto it4 = b.upper_bound((red**it2)/2);
                //cout << red << " " << *it << " " <<  *it2 <<  " " << *it3 << endl;
                //cout << red << " " << *it << " " << *it2 << " " << *it4 << endl;

                if(it3 != b.begin() || (*it3 == (red+*it2)/2)){
                    if(*it3 > (red+*it2)/2 || it3 == b.end()){
                        it3--;
                    }
                    ans = min(ans, calc(red, *it, *it3));
                }
                if(it4 != b.end()){
                    ans = min(ans, calc(red, *it, *it4));
                }
            }
        }





        cout << ans << endl;
        
    }


}

