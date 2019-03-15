#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
//#define Max(a,b) (a>b?a:b)
//#define Min(a,b) (a<b?a:b)
using namespace std;
bool HotCheck(vector<int> v,int d,int k){
    //sort(v.begin(),v.end());
    for(int i = k-1;i<v.size();i++){
        if(v[i]<v[i-k+1]+d)//如果第i个中的时刻比第i-(k-1)个中的时刻+d小
            return true;   //说明他曾是热帖，若等于不行，因为是左闭右开
    }
    return false;
}
int main()
{
    map<int,vector<int> > idmap;//idmap[id为键]内容为点赞时刻
    vector<int> idout;//输出组
    int N,D,K;
    int tempts,tempid;//临时ts和id；
    cin>>N>>D>>K;
    for(int i=0;i<N;i++){
        cin>>tempts>>tempid;
        idmap[tempid].push_back(tempts);//存入map
    }
    for(int nindex = 1; nindex <= idmap.size(); nindex++)
        sort(idmap[nindex].begin(),idmap[nindex].end());//对idmap【id】内的时刻排序

//    for(int nindex = 1; nindex <= idmap.size(); nindex++)//遍历map
//        for(int i=0;i<idmap[nindex].size();i++)
//            cout<<idmap[nindex][i]<<endl;

    for(int nindex = 1; nindex <= idmap.size(); nindex++)
        if(HotCheck(idmap[nindex],D,K))//如果为热帖，进入idout
            idout.push_back(nindex);
    sort(idout.begin(),idout.end());//从小到大排序
    for(int i=0;i<idout.size();i++)//遍历输出
         cout<<idout[i]<<endl;

	return 0;
}
