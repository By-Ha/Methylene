#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=500005;
int a[maxn],c[maxn];
int n,m;
inline int lowbit(int x)
{return x&-x;}
inline void add(int x,int y)
{
  while(x<=n)
  {
    c[x]+=y;
    x+=lowbit(x);
  }
}
inline int sum(int x)
{
  int s=0;
  while(x>0)
  {
    s+=c[x];
    x-=lowbit(x);
  }
  return s;
}
int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
    add(i,a[i]);
  }
  while(m--)
  {
    int flag;
    scanf("%d",&flag);
    if(flag==1)
    {
      int x,y;
      scanf("%d%d",&x,&y);
      add(x,y);
    }
    else
    {
      int i,j;
      scanf("%d%d",&i,&j);
      printf("%d\n",sum(j)-sum(i-1));
    }
  }
  return 0;
}
