#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>

using namespace std;
#define ll long long

ll UB=(ll)(1e18);
vector<ll>v;
int main(){
    //freopen("input0.txt", "r", stdin);
    //freopen("output0.txt", "w", stdout);
    int n, q;
    cin>>n>>q;
    assert(n >= 1 && n <= 100000);
    assert(q >= 1 && q <= 100000);
    ll max_val = 0LL;
    for(int i = 0; i < n; ++i) {
        ll x;
        cin>>x;
        assert(x <= UB);
        max_val = max(max_val, x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    ll sm = 0LL;
    bool flg=false;
    while(q--){
        ll op,x,y,z;
        cin>>op;
        if(op == 1){
            cin>>x;
            if(sm <= max_val) {
                sm += x;
            }
            else flg=1;
        }
        else{
            cin>>x>>y>>z;
            if(flg) {
                cout<<-1<<endl;
            }
            else{
                int idl = lower_bound( v.begin(), v.end(), x + sm) - v.begin();
                int idr = upper_bound( v.begin(), v.end(), y + sm) - v.begin();
                if( (idr - idl) >= z) {
                    cout<<v[idl + z - 1] - sm<<endl;
                }
                else cout<<-1<<endl;
            }
        }
    }
    return 0;
}
