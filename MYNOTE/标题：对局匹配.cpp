#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,k,cont[100005]={0};
int MAX_NUM=0;
int main()
{   //dp[i]=max(dp[i-1],dp[i-2]+a[i])
    int ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int tempa;
        cin>>tempa;
        cont[tempa]++;
        if(tempa>MAX_NUM)
            MAX_NUM = tempa;
    }
    if(k==0){
        for(int i=1;i<=MAX_NUM;i++)
            if(cont[i]>0)
                ans++;
    }
    else{
        for(int i=1;i<=k;i++){
            int val[MAX_NUM/k+1];
            int dp[MAX_NUM]={0};
            int m=0;
            for(int j=i;j<=MAX_NUM;j+=k){
                val[m]=cont[i];
                if(m==0)
                    dp[m]=val[m];
                else if(m==1){
                    dp[m]=max(dp[m-1],val[m]);
                }
                else{
                    dp[m]=max(dp[m-1],dp[m-2]+val[m]);
                }
                m++;
            }
            ans+=dp[m-1];
        }
    }
    cout<<ans<<endl;
    return 0;
}
