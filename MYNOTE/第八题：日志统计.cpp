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
        if(v[i]<v[i-k+1]+d)//�����i���е�ʱ�̱ȵ�i-(k-1)���е�ʱ��+dС
            return true;   //˵�������������������ڲ��У���Ϊ������ҿ�
    }
    return false;
}
int main()
{
    map<int,vector<int> > idmap;//idmap[idΪ��]����Ϊ����ʱ��
    vector<int> idout;//�����
    int N,D,K;
    int tempts,tempid;//��ʱts��id��
    cin>>N>>D>>K;
    for(int i=0;i<N;i++){
        cin>>tempts>>tempid;
        idmap[tempid].push_back(tempts);//����map
    }
    for(int nindex = 1; nindex <= idmap.size(); nindex++)
        sort(idmap[nindex].begin(),idmap[nindex].end());//��idmap��id���ڵ�ʱ������

//    for(int nindex = 1; nindex <= idmap.size(); nindex++)//����map
//        for(int i=0;i<idmap[nindex].size();i++)
//            cout<<idmap[nindex][i]<<endl;

    for(int nindex = 1; nindex <= idmap.size(); nindex++)
        if(HotCheck(idmap[nindex],D,K))//���Ϊ����������idout
            idout.push_back(nindex);
    sort(idout.begin(),idout.end());//��С��������
    for(int i=0;i<idout.size();i++)//�������
         cout<<idout[i]<<endl;

	return 0;
}
