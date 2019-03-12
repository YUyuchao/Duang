#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;
typedef struct Node{
    int a;
    int b;
}NodeList;
bool Cmpare(NodeList aa,NodeList bb){
     return aa.a<bb.a;
}
int main(int argc, char* argv[])
{
    NodeList z[2];
    z[0].a = 2;
    z[0].b = 20;
    z[1].a = 1;
    z[1].b = 10;
    sort(z,z+2,Cmpare);
    printf("%d\n",z[0].a);
    printf("%d\n",z[0].b);
    printf("%d\n",z[1].a);
    printf("%d\n",z[1].b);

	return 0;
}
