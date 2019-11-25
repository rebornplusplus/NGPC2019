#include <bits/stdc++.h>
#define pi acos(-1.0)

using namespace std;

typedef long long ll;

int main ()
{
    int t;
    double ab, ad, bad;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lf%lf%lf", &ab, &ad, &bad);
        double bd_2 = ab*ab + ad*ad - 2.0*ab*ad*cos(bad*pi/180.0);
        double ans = bd_2 + ad*ad;
        ans = 2.0 * ans;
        printf("%.10f\n", ans);
    }
    return 0;
}

