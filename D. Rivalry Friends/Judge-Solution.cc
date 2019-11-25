#include<bits/stdc++.h>

using namespace std;
typedef long long ll ;

ll arr[100005],tree[4*100005], in [100006];


void init(int root, int b, int e )
{
    if(b==e)
    {
        tree[root]= arr[in[b]];
        return;
    }
    ll left = root*2;
    ll right = (root*2) + 1;
    ll mid = (b+e)/2;
    init (left,b,mid);
    init(right,mid +1, e);
    tree[root]= tree[left]+tree[right];
}


ll que(int root , int b, int e, int x , int y)
{
    if(x>e||y<b)return 0;
    if(b>=x&&e<=y)return tree[root];
    ll right = root*2 +1;
    ll left = root*2;
    ll mid = (b+e)/2;
    ll p1= que(left,b,mid,x,y);
    ll p2 = que(right,mid+1,e,x,y);
    return p1+p2;
}

void update(int root , int b, int e, int x ,ll val)
{
    if(x>e||x<b)return;
    if(b>=x&&e<=x)
    {
        tree[root] = arr[val];
        return;
    }
    ll right = root*2 +1 ;
    ll left = root*2 ;
    ll mid = (b+e)/2;
    update(left,b,mid,x,val);
    update(right,mid+1,e,x,val);
    tree[root]=tree[left]+tree[right];
}

int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}


int main()
{

  //  freopen("input_21.txt", "r", stdin);
  //  freopen("output_21.txt", "w", stdout);

    for( int i = 1; i<=100000; i++)
    {
        arr[i] = phi(i);
    }

    int n , q ;
    scanf("%d%d",&n,&q);
    for( int i = 1 ; i <= n ; i ++)
    {
        scanf("%lld",&in[i]);
    }
    init(1,1,n);
    while( q-- )
    {
        int type, i , j;
        ll val ;

        scanf("%d", &type);

        if( type == 1)
        {
            scanf("%d%lld",&i ,&val);
            update(1,1,n,i,val);
        }

        else
        {
            scanf("%d%d",&i,&j);
            printf("%lld\n", que(1,1,n,i,j));
        }
    }


}
