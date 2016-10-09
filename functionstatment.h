/******************函数声明*********************************/
typedef  int  vextype;
typedef vextype mgraph[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
mgraph G1;
Mgraph g,g1;   //声明一个邻接矩阵的图 
LGraph tg;   // 声明邻接表 
int n,e;      //定义全局变量 
void disp(LGraph *tg);
void BFSTraverse(LGraph *tg);  
void initQueue(Queue &Q);   //构造队列 
int QueueFull(Queue &Q);   //队列判空 
void EnQueue(Queue &Q,int e);  //入队 
void DeQueue(Queue &Q,int *e);   //出队 
int creat_Graph(Mgraph *mg,LGraph *lg);   //创建邻接矩阵和邻接表的图   * 
int locatevex(Mgraph *mg,char v);   //找出图的某个顶点位置    * 
void creat_mygraph1(Mgraph *g);   //创建无向图邻接矩阵       * 
void adj_table_noway(LGraph *tg);     //无向图邻接表 
void creat_hway_graph(Mgraph *g);  //创建有向图邻接矩阵      * 
void adj_table_hway(LGraph *tg);   //有向图邻接表    *
void creat_nonet(Mgraph *g);  //创建无向网    * 
void adj_table_no_net(LGraph *tg);    //无向网邻接表 
void have_w_net(Mgraph *g);   //创建有向网     *
void  adj_table_h_net(LGraph *tg);   //有向网邻接表 
int locate_adj_vex(LGraph *tg,char v);   //邻接表的顶点定位 
void DFS(LGraph *tg,int i);  //深度优先遍历 
void LBFS(LGraph *tg);  //广度优先遍历 
int visited[MAX_NUM ];   //访问数组
int Ladjvex(LGraph *tg,int k);   //位置 


