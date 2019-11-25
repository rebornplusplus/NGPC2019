#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    long double AB,AD,A;
    int T;

    cin>>T;

    for (int t=1;t<=T;t++)
    {
        cin>>AB>>AD>>A;
        long double ang1=((A)*(2*acos(0)))/180;
        long double BD = sqrt((AB*AB) + (AD*AD) - (2*AB*AD*cos(ang1)));
        long double res1=2*((AD*AD)+(BD*BD));

        cout<<fixed<<setprecision(9)<<res1<<endl;
    }

    return 0;
}

