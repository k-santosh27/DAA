#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct
{
  int u,v;
}edge;
int dfn[MAX]={0};
int L[MAX]={0};
int num=1;
int n;
int a[MAX][MAX];
edge stack[MAX];
int top=-1;
void push(edge e)
{
  if(top==MAX-1)  printf("stack is full");
  else stack[++top]=e;
}
edge pop()
{
  edge e;
  if(top==-1) printf("stack is empty");
  else e=stack[top--];
  return e;
}

void bicom(int u, int v)
{
  int w;
  edge e;
  dfn[u]=num;  L[u]=num;  num++;
  for(w=1;w<=n;w++)
    if(a[u][w]==1)
    {
		if((v!=w) && (dfn[w]<dfn[u]))
		{
	  		e.u=u;
	  		e.v=w;
	  		printf("edge %d-%d is pushed to stack\n",e.u,e.v);
	  		push(e);
		}
		if(dfn[w]==0)
		{
	  		bicom(w,u);
	  		printf("pushed\n");
	  		L[u] = (L[u] < L[w]) ? L[u] : L[w];
	  		if(L[w] >= dfn[u])
	  		{
	    		printf("\nnew bicomponent for AP %d\n",u);
	    		do
	    		{
					e=pop();
					printf("%d-%d\t",e.u,e.v);
	    		}while(!((e.u == u && e.v == w)||(e.u == w && e.v == u)));
	  		}
		}
		else
	  		if(w != v)  L[u] = (L[u] < dfn[w]) ? L[u] : dfn[w];
    }
}

   int main()
{
  int i,j;
  printf("enter no.of nodes\n");
  scanf("%d",&n);
  printf("adj matrix:\n");
  for(i=1;i<=n;i++) for(j=1;j<=n;j++)  scanf("%d",&a[i][j]);
  for(i=1;i<=n;i++) { for(j=1;j<=n;j++) {  printf("%d ",a[i][j]); } printf("\n"); }
  bicom(1,0);
}

