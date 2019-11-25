#include<bits/stdc++.h>
using namespace std;

//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<typename T>
//using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define MAX             100005
#define MOD             1000000007
#define eps             1e-6
int fx[] =              {1,-1,0,0};
int fy[] =              {0,0,1,-1};

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0);
#define fRead           freopen("in.txt","r",stdin);
#define fWrite          freopen ("out.txt","w",stdout);

#define LL              long long
#define ULL              unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>
#define all(a)          a.begin(),a.end()

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))

#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define IT(it,x)	    for(it=x.begin();it!=x.end();it++)

#define MEM(a,x)        memset(a,x,sizeof(a))
#define Unique(a)       a.erase(unique(a.begin(),a.end()),a.end())
#define TC              int t;cin >> t;FOR(tc,1,t)
#define ABS(x)          ((x)<0?-(x):(x))
#define SQ(x)           ((x)*(x))
#define SP(x)           fixed << setprecision(x)


#define Make(x,p)       (x | (1<<p))
#define DeMake(x,p)     (x & ~(1<<p))
#define Check(x,p)      (x & (1<<p))
#define popcount(x)     __builtin_popcount(x)

int fnc(string str)
{
      int h=(str[0]-'0')*10+str[1]-'0';
      int m=(str[3]-'0')*10+str[4]-'0';
      return h*60+m;
}

int main()
{
      FastRead

      //fRead

      int t;
      cin >> t;
      for(int tc=1;tc<=t;tc++)
      {
            int n;
            cin >> n;

            int arr[1500]={0};

            for(int i=1;i<=n;i++)
            {
                  string s,r;
                  cin >> s >> r;
                  int x=fnc(s);
                  int y=fnc(r);

                  if(x<y){
                        arr[x]++;
                        arr[y]--;
                  }
                  else if(x>y){
                        arr[x]++;
                        arr[1440]--;
                        arr[0]++;
                        arr[y]--;
                  }
                  else{
                        arr[0]++;
                        arr[1440]--;
                  }
            }

            for(int i=1;i<1500;i++) arr[i]+=arr[i-1];
            int mx=0;
            for(int i=0;i<1440;i++) mx=max(mx,arr[i]);
            cout << "Case #" << tc << ": Mr.Xifu needs " << mx << " classroom(s)\n";
    }
}

