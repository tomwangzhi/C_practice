#include <stdio.h>  
//#include<conio.h>  
#define INFINITY 1000  
#define MAX_VERTEX_NUM 20  
#define ERROR 0  
#define OK 1  
typedef enum{DG,DN,UDG,UDN} GraphKind;  
typedef int VRType;  
typedef int InfoType;  
typedef char VertexTpye;  
typedef int Status;  
typedef struct Matrix  
    {  
        char adjvex;  
        int lowcost;  
    }Matrix,*ArcLink;  
typedef struct ArcCell  
{  
    VRType adj;//�û���Ȩֵ  
    InfoType *info;//�û������Ϣ��ָ��  
} ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  
typedef struct  
{  
    char vexs[MAX_VERTEX_NUM];  
    AdjMatrix arcs;  
    int vexnum,arcnum;  
    GraphKind kind;  
}MGraph;  
int LocateVertex(MGraph G,VertexTpye Vertex)  
{  
    int j=ERROR,k;  
    for(k=0;k<G.vexnum ;k++)  
    {  
        if(G.vexs[k]==Vertex)  
        {  
            j=k;  
            break;  
        }  
    }  
    return(j);  
}  
int Minimum(int q,   ArcLink p)  
{  
    int i,m=1;  
    int a=0;  
    //while(a==0)  
    //{  
    //  p++;  
    //  a=p->lowcost;  
    //};  
    for(i=0;i<q;i++)  
    {  
        if(a==0||a>(p+i)->lowcost&&(p+i)->lowcost !=0)  
        {  
            a=(p+i)->lowcost;  
            m=i;  
        }  
    }  
    return m;  
}  
 void PrintGraph(MGraph G)  
{  
    int i,j;  
    for(i=0;i<G.vexnum;i++)  
    {  
        for(j=0;j<G.vexnum ;j++)  
        {  
            if(G.arcs [i][j].adj!=1000)  
            {  
                printf("%c--->%c  %d/n",G.vexs[i],G.vexs[j],G.arcs[i][j]);  
            }  
        }  
    }  
}  
  
void MiniSpanTree_PRIM(MGraph G,char u)  
{  
 //int LocateVertex(MGraph G,VertexTpye Vertex);  
  Matrix closedge[MAX_VERTEX_NUM];  
  int k=LocateVertex(G,u);  
  int i,j=0;  
  for(j=0;j<G.arcnum ;j++)  
  {  
      if(j!=k)  
      {  
         /* closedge[j]={u,G.arcs [k][j].adj};*///<a href="http://lib.csdn.net/base/31" class='replace_word' title="�㷨�����ݽṹ֪ʶ��" target='_blank' style='color:#df3434; font-weight:bold;'>�㷨</a>������ôд��C�ﲻ�ܣ�  
          closedge[j].adjvex=u;  
          closedge[j].lowcost=G.arcs [k][j].adj;  
      }  
      else  
      {  
          closedge[k].lowcost=0;  
      }  
  }  
      for(i=1;i<G.vexnum ;i++)  
      {  
          k=Minimum(G.vexnum ,closedge);  
          printf("The MSF is %c---->%c/n",closedge[k].adjvex ,G.vexs[k]);  
          closedge[k].lowcost =0;  
          for(j=0;j<G.vexnum ;j++)  
          {  
              if(G.arcs[k][j].adj <closedge[j].lowcost )  
              {  
                  closedge[j].adjvex =G.vexs [k];  
                  closedge[j].lowcost =G.arcs[k][j].adj ;  
              }  
          }  
      }  
  }  
  
  
main()  
{  
    MGraph G;  
    int i,j,k,w,IncInfo;  
    char v1,v2;  
    int LocateVertex(MGraph,VertexTpye);  
    int getche(void);  
    //int MiniSpanTree_PRIM(MGraph G,char u);  
    printf("please Enter into the number of Vertex Arc and Arc_information:/n");  
    scanf("%d,%d,%d",&G.vexnum ,&G.arcnum,&IncInfo);  
    getchar();  
    printf("The Number of Vertex is %d,The Number of Arc is %d/n",G.vexnum ,G.arcnum );   
    for(i=0;i<G.vexnum ;i++)  
    {   printf("NO.%d Vertex is:",i);  
        //G.vexs[i]=getchar();  
        scanf("%c",&G.vexs[i]);  
        getchar();  
    }  
    for(i=0;i<G.vexnum ;i++)  
    {  
        printf("/nThe Vertex you Enter into is %c:",G.vexs[i]);  
    }  
  
    for(i=0;i<G.vexnum ;i++)  
    {  
        for(j=0;j<G.vexnum ;j++)  
        {  
            G.arcs [i][j].adj =INFINITY;//��ʼ������ȨֵΪ1000  
            //*(G.arcs [i][j].info) =INFINITY;//�û��������Ϣ  
        }  
    }  
    for(k=0;k<G.arcnum ;k++)  
    { printf("/n please Enter into NO.%d Arc:",k+1);  
      v1=getche();  
      printf("/t");  
      v2=getche();  
      printf("/t");  
      scanf("%d",&w);  
      printf("The value between %c and %c is %d/n",v1,v2,w);  
       i=LocateVertex(G,v1);  
       j=LocateVertex(G,v2);  
       G.arcs[i][j].adj =w;  
        G.arcs [j][i]=G.arcs [i][j];//���������������������  
       if(IncInfo)  
       {  
       }  
    }  
       
      PrintGraph(G);  
      MiniSpanTree_PRIM(G,'A');  
       getchar();  
      getchar();  
}  
