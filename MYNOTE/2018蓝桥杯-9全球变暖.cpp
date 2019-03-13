#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;
char Map[1005][1005];
struct node{
    int x;
    int y;
    node(int a,int b)
    {
        x = a;
        y = b;
    }
};
bool NoSea(int x,int y){//½�ص���������û�к�
    if(Map[x-1][y]=='#'&&Map[x+1][y]=='#'&&Map[x][y-1]=='#'&&Map[x][y+1]=='#')
        return true;
    else
        return false;
}
void bfs(int i,int j){
    queue<node> q;
    int nx,ny;
    node *v = new node(i,j);
    q.push(*v);
    while(!q.empty()){
        nx = q.front().x;
        ny = q.front().y;
        q.pop();
        Map[nx][ny] = '.';
        if(Map[nx-1][ny]=='#'){
            node *nv = new node(nx-1,ny);
            q.push(*nv);
        }
        if(Map[nx+1][ny]=='#'){
            node *nv = new node(nx+1,ny);
            q.push(*nv);
        }
        if(Map[nx][ny-1]=='#'){
            node *nv = new node(nx,ny-1);
            q.push(*nv);
        }
        if(Map[nx][ny+1]=='#'){
            node *nv = new node(nx,ny+1);
            q.push(*nv);
        }
    }
}
int main(int argc, char* argv[])
{
    int n;
    int out = 0;//��û����ĸ���
    scanf("%d",&n);//���뼸�м���
    for(int i=0;i<n;i++)//�����ͼ
        scanf("%s",&Map[i]);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(Map[i][j]=='#'&&NoSea(i,j))//���������첻���û
                bfs(i,j);//��ȱ�����ȥ�������
        }
//    for(int i=0;i<n;i++)
//        printf("%s\n",Map[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(Map[i][j]=='#'){//ʣ�µĻ��û�ĵ���
                out++;//������һ
                bfs(i,j);//��ȱ�����ȥ�������
            }
        }
    printf("\n��û�ĵ������Ϊ��%d\n",out);
	return 0;
}
