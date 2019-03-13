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
bool NoSea(int x,int y){//陆地的上下左右没有海
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
    int out = 0;//沉没岛屿的个数
    scanf("%d",&n);//输入几行几列
    for(int i=0;i<n;i++)//输入地图
        scanf("%s",&Map[i]);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(Map[i][j]=='#'&&NoSea(i,j))//如果这个岛屿不会沉没
                bfs(i,j);//广度遍历，去掉这个岛
        }
//    for(int i=0;i<n;i++)
//        printf("%s\n",Map[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(Map[i][j]=='#'){//剩下的会沉没的岛屿
                out++;//计数加一
                bfs(i,j);//广度遍历，去掉这个岛
            }
        }
    printf("\n沉没的岛屿个数为：%d\n",out);
	return 0;
}
