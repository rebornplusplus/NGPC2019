#include <bits/stdc++.h>
using namespace std;
const int MX=1000006;
char s[MX];
int n,size,last;
int p[MX],pn[MX],c[20][MX],cn[MX],cnt[MX];
struct sub{
    int i,j;
    bool operator < (const sub &d) const
    {
        int x=i,y=j,p=d.i,q=d.j;
        if(y-x<q-p) q-=(q-p)-(y-x);
        else if(q-p<y-x) y-=(y-x)-(q-p);
        int l=y-x+1,k=__lg(y-x+1);
        pair<int,int> a={c[k][x],c[k][(x+l-(1<<k))%n]};
        pair<int,int> b={c[k][p],c[k][(p+l-(1<<k))%n]};
        return (a==b)?(j-i<d.j-d.i):(a<=b);
    }
} st[MX];
struct node{
    int len,link;
    int pos,to[26];
} pt[MX];
void sort_cyclic_shifts(char s[],int n)
{
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++) cnt[s[i]]++;
    for(int i=1;i<256;i++) cnt[i]+=cnt[i-1];
    for(int i=0;i<n;i++) p[--cnt[s[i]]]=i;
    int classes=1;
    for(int i=0;i<n;i++){
        if(i && s[p[i]]!=s[p[i-1]]) classes++;
        c[0][p[i]]=classes-1;
    }
    for(int k=0;(1<<k)<n;k++){
        for(int i=0;i<n;i++){
            pn[i]=p[i]-(1<<k);
            if(pn[i]<0) pn[i]+=n;
        }
        fill(cnt,cnt+classes,0);
        for(int i=0;i<n;i++) cnt[c[k][pn[i]]]++;
        for(int i=1;i<classes;i++) cnt[i]+=cnt[i-1];
        for(int i=n-1;i>=0;i--) p[--cnt[c[k][pn[i]]]]=pn[i];
        classes=1,cn[p[0]]=0;
        pair <int,int> x,y;
        for(int i=1;i<n;i++){
            x={c[k][p[i]],c[k][(p[i]+(1<<k))%n]};
            y={c[k][p[i-1]],c[k][(p[i-1]+(1<<k))%n]};
            if(x!=y) classes++;
            cn[p[i]]=classes-1;
        }
        for(int i=0;i<n;i++) c[k+1][i]=cn[i];
    }
}
void init_node(int n)
{
    pt[n].len=0;
    pt[n].link=-1;
    memset(pt[n].to,-1,sizeof(pt[n].to));
}
void init_pt()
{
    init_node(0);
    init_node(1);
    pt[0].len=pt[0].link=-1;
    pt[1].link=0;
    size=2,last=1;
}
int find(int n,char s[],int i)
{
    while(n){
        int j=i-pt[n].len-1;
        if(j>=0 && s[i]==s[j]) return n;
        n=pt[n].link;
    }
    return n;
}
void extend(char s[],int i)
{
    int c=s[i]-97;
    int n=find(last,s,i);
    if(pt[n].to[c]==-1){
        int m=size++;
        init_node(m);
        pt[n].to[c]=m;
        pt[m].len=pt[n].len+2;
        pt[m].pos=i-pt[m].len+1;
        if(pt[m].len==1) pt[m].link=1;
        else{
            int v=find(pt[n].link,s,i);
            pt[m].link=pt[v].to[c];
        }
        last=m;
    }
    else last=pt[n].to[c];
}
int main()
{
    int q,k;
    scanf("%s %d",s,&q);
    n=strlen(s);
    s[n]='$';
    sort_cyclic_shifts(s,n+1);
    init_pt();
    for(int i=0;i<n;i++) extend(s,i);
    int m=size-2;
    for(int i=1;i<=m;i++){
        int x=pt[i+1].pos;
        int y=x+pt[i+1].len-1;
        st[i]={x,y};
    }
    sort(st+1,st+m+1);
    while(q--){
        scanf("%d",&k);
        if(k>m) printf("-1\n");
        else printf("%d %d\n",st[k].i+1,st[k].j+1);
    }
    return 0;
}
