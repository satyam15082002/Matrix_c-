#include<bits/stdc++.h>
#include<string>
using namespace std;
uint64_t fib_r(uint64_t n)
{
    if(n==1||n==2)
        return 1;
    else
        return fib_r(n-1)+fib_r(n-2);
}
uint64_t fib_m(uint64_t n,uint64_t memo[])
{
    uint64_t result;
    if(memo[n])
        return memo[n];

    if(n==1||n==2)
        return 1;
    else
        result=fib_m(n-1,memo)+fib_m(n-2,memo);
    memo[n]=result;
    return result;
}
uint64_t fib_2(uint64_t n)
{
    uint64_t result[n]={0};
    uint64_t r=fib_m(n,result);
    return r; 
}
uint64_t fib_bup(uint64_t n)
{
    if(n==1||n==2)
        return 1;
    uint64_t bottom_up[n+1];
    bottom_up[1]=1;
    bottom_up[2]=1;
    for(uint64_t i=3;i<=n;i++)
        bottom_up[i]=bottom_up[i-1]+bottom_up[i-2];
    return bottom_up[n];
}

int main()
{
 
    return 0;
}