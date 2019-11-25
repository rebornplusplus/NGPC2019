#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<sstream>
#include<set>
#include<utility>
#include<time.h>
using namespace std;



int main()
{
    //freopen("input_03.txt", "r", stdin);
    //freopen("output_03.txt", "wb", stdout);
    int tcase, i, ans, n, h1, m1, h2, m2, t1, t2, cs=1, cnt[2000], tot=24*60;
    scanf("%d", &tcase);

    while(tcase--)
    {
        memset(cnt, 0, sizeof cnt);
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
            t1 = h1*60+m1;
            t2 = h2*60+m2;
            //printf("%d %d\n", t1, t2);
            if(t1<t2)
            {
                for(i=t1; i<t2; i++)
                    cnt[i]++;
            }
            else
            {
               for(i=t1; i<=tot; i++)
                    cnt[i]++;
                for(i=0; i<t2; i++)
                    cnt[i]++;
            }
        }

        ans = 0;
        for(int i=0; i<=tot; i++)
        {
            //printf("%d\n", cnt[i]);
            ans = max(ans, cnt[i]);
            //printf("%d %c %d\n", vec[i].time, vec[i].type, cnt);
        }
        printf("Case #%d: Mr.Xifu needs %d classroom(s)\n", cs++, ans);

    }
    return 0;

}
