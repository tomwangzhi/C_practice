/******************��������*********************************/
typedef  int  vextype;
typedef vextype mgraph[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
mgraph G1;
Mgraph g,g1;   //����һ���ڽӾ����ͼ 
LGraph tg;   // �����ڽӱ� 
int n,e;      //����ȫ�ֱ��� 
void disp(LGraph *tg);
void BFSTraverse(LGraph *tg);  
void initQueue(Queue &Q);   //������� 
int QueueFull(Queue &Q);   //�����п� 
void EnQueue(Queue &Q,int e);  //��� 
void DeQueue(Queue &Q,int *e);   //���� 
int creat_Graph(Mgraph *mg,LGraph *lg);   //�����ڽӾ�����ڽӱ��ͼ   * 
int locatevex(Mgraph *mg,char v);   //�ҳ�ͼ��ĳ������λ��    * 
void creat_mygraph1(Mgraph *g);   //��������ͼ�ڽӾ���       * 
void adj_table_noway(LGraph *tg);     //����ͼ�ڽӱ� 
void creat_hway_graph(Mgraph *g);  //��������ͼ�ڽӾ���      * 
void adj_table_hway(LGraph *tg);   //����ͼ�ڽӱ�    *
void creat_nonet(Mgraph *g);  //����������    * 
void adj_table_no_net(LGraph *tg);    //�������ڽӱ� 
void have_w_net(Mgraph *g);   //����������     *
void  adj_table_h_net(LGraph *tg);   //�������ڽӱ� 
int locate_adj_vex(LGraph *tg,char v);   //�ڽӱ�Ķ��㶨λ 
void DFS(LGraph *tg,int i);  //������ȱ��� 
void LBFS(LGraph *tg);  //������ȱ��� 
int visited[MAX_NUM ];   //��������
int Ladjvex(LGraph *tg,int k);   //λ�� 


