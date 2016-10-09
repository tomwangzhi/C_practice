C语言帝国C语言、C语言帝国、C语言学习网站、编程学习网站、C语言教程、C语言论坛、C语言基地

  SEARCH
订阅RSS
首页
C语言帝国QQ群
首页 > 编程资源分享区 > C/C++源代码共享 > C语言图书管理系统分析和源代码(下)
2006
09-28
C语言图书管理系统分析和源代码(下)
cboyC/C++源代码共享一条评论
/*********************************************************** *************************/
void look_for_name ()
   { struct booktype *head,*p;
    int i,n=1,e;
     do
     {char borrow_name[20];
      printf (“请输入您想要查找的书名,按回车结束.”);
      scanf (“%s”,borrow_name);
  p=head;
  if (!head)
           {do
     { if (0==strcmp (p->bookname,borrow_name))
      { i=1;
        printf (“该书的书号为:%d\n”,p->booknumber);
        printf (“该书的书名为:%s\n”,p->bookname[20]);
        printf (“该书出版单位为:%s\n”,p->press[50]);
        printf (“该书作者为:%s\n”,p->auther[20]);
        printf (“该书页数为:%d\n”,p->pagenumber);
        printf (“该书定价为：%d\n”,p->price);
                printf (“该书当前册数为:%d\n”,p->nownumber);
                    if (p->nownumber!=0)
      printf (“本书已被借出,借书者证号为:%d”,p->borrowernum);
             else printf (“本书未被借出.\n”);
      }
     p=p->next;
     }while(!p);
         }
         else printf (“对不起，库内没有图书!\n”);
         if (i!=1)
         printf (“对不起,没有您要查找的图书.\n”);
        printf(“是否继续进行查找操作？1、是,2、否\n”);
        scanf(“%d”,&e);
     }while(e==1);
   }
 void look_for_writer ()
   { struct booktype *head,*p;
     int e,i,n=1;
     char borrow_writer[16];
      do
      {printf (“请输入您想要查找的书的作者,按回车结束.\n”);
       scanf (“%s”,borrow_writer[16]);
   p=head;
   if (!head)
           {do
     {if(0==strcmp (p->auther[20],borrow_writer[16]))
       {i=1;
        printf (“该书的书号为:%d\n”,p->booknumber);
        printf (“该书的书名为:%s\n”,p->bookname[20]);
        printf (“该书出版单位为:%s\n”,p->press[50]);
        printf (“该书作者为:%s\n”,p->auther[20]);
        printf (“该书页数为:%d\n”,p->pagenumber);
        printf (“该书定价为：%d\n”,p->price);
           printf (“该书当前册数为:%d\n”,p->nownumber);
                    if (p->nownumber!=0)
      printf (“本书已被借出,借书者证号为:%d”,p->borrowernum);
     else printf (“本书未被借出.\n”);
      }
     p=p->next;
    }while(!p);
          }
         else printf (“对不起，库内没有图书!\n”);
         if (i!=1)
   printf (“对不起,没有您要查找的图书.\n”);
       printf(“是否继续进行查找操作？1、是,2、否\n”);
       scanf(“%d”,&e);
     }while(e==1);
   }
 void look_for_press()
 { int i=0,e;
   struct booktype *head, *p;
   char borrow_press[40];
   do
   {printf (“请输入您想要查找的书的出版单位,按回车结束.\n”);
       scanf (“%s”,borrow_press);
    p=head;
    if (!head)
    { do
     { if (0==strcmp (p->press,borrow_press))
        {i=1;
  printf (“该书的书号为:%d\n”,p->booknumber);
        printf (“该书的书名为:%s\n”,p->bookname[20]);
        printf (“该书出版单位为:%s\n”,p->press[50]);
        printf (“该书作者为:%s\n”,p->auther[20]);
        printf (“该书页数为:%d\n”,p->pagenumber);
        printf (“该书定价为：%d\n”,p->price);
           printf (“该书当前册数为:%d\n”,p->nownumber);
                    if (p->nownumber!=0)
      printf (“本书已被借出,借书者证号为:%d”,p->borrowernum);
     else printf (“本书未被借出.\n”);
  }
    p=p->next;
    }while(!p);
          }
          else printf (“对不起，库内没有图书!\n”);
       if (i!=1)
  printf (“对不起,没有您要查找的图书.\n”);
       printf(“是否继续进行查找操作？1、是,2、否\n”);
        scanf(“%d”,&e);
     }while(e==1);
 }
void look_for_number()
     { int i,e;
       struct booktype *head,*p;
       int borrow_nomber;
       do
       {printf (“请输入您要查找的书的书号,按回车结束.\n”);
        scanf (“%d”,&borrow_nomber);
    p=head;
    if (!head)
    {do
     { if (p->booknumber==borrow_nomber)
       { i=1;
        printf (“该书的书号为:%d\n”,p->booknumber);
        printf (“该书的书名为:%s\n”,p->bookname[20]);
        printf (“该书出版单位为:%s\n”,p->press[50]);
        printf (“该书作者为:%s\n”,p->auther[20]);
        printf (“该书页数为:%d\n”,p->pagenumber);
        printf (“该书定价为：%d\n”,p->price);
                printf (“该书当前册数为:%d\n”,p->nownumber);
                    if (p->nownumber!=0)
      printf (“本书已被借出,借书者证号为:%d”,p->borrowernum);
     else printf (“本书未被借出.\n”);
       }
       p=p->next;
     }while(!p);
    }
           else printf (“对不起，库内没有图书!\n”);
   if (i!=1)
     printf (“对不起,没有您要查找的图书.\n”);
         printf(“是否继续进行查找操作？1、是,2、否\n”);
        scanf(“%d”,&e);
       }while(e==1);
     }
   void look_for_borrower ()
 {void look_card_num ();
  void look_card_name ();
   char borrower_name[20];
   int n,d,e;
          do
   {printf (“请您选择您要查找的方式:1,按借书者的卡号\n;2按借书者的名字;\n;3：退出\n”);
           scanf (“%d”,&n);
           if (n==1)
      look_card_num ();
              else if (n==2)
      look_card_name ();
                     else if (n==3)
                           exit (0);
          printf(“是否继续进行查找操作？1、是,2、否\n”);
          scanf(“%d”,&e);
         }while(e==1);
 }
       void look_card_num ()
  { struct booktype *head, *p;
    struct borrowertype *card,*hed;
    int m,e;
           do
           {printf (“请输入您要查找的卡的卡号.\n”);
     scanf (“%d”,&m);
  card=hed;
  if (!hed)
  {do
   { if (card->cardnumber==m)
    { printf (“此卡卡号为:%d\n”,card->cardnumber);
     printf (“此卡持有者的姓名为:%s\n”,card->name[20]);
                    printf (“此卡持有者的性别为:%s\n”,card->sex[10]);
                    printf (“此卡持有者的联系电话为:%d\n”,card->tel[10]);
                    printf (“此卡持有者的工作单位为:%d\n”,card->unit[80]);
                    p=head;
             if (!head)
     {do
       { if (card->cardnumber==p->borrowernum)
        {printf (“此卡已经借阅了图书\n”);
         printf (“该书的书号为:%d\n”,p->booknumber);
                 printf (“该书的书名为:%s\n”,p->bookname[20]);
                 printf (“该书出版单位为:%s\n”,p->press[50]);
                 printf (“该书作者为:%s\n”,p->auther[20]);
                 printf (“该书页数为:%d\n”,p->pagenumber);
                 printf (“该书定价为：%d\n”,p->price);
                         printf (“该书当前册数为:%d\n”,p->nownumber);
        }
       p=p->next;
      }while(!p);
     }
                     printf (“此卡不存在.”);
    card=card->new;}
  else printf (“此卡号不存在.\n”);
                  }while(!card);
       printf(“是否继续进行查找操作？1、是,2、否\n”);
               scanf(“%d”,&e);
              }
             }while(e==1);
         }
  void look_card_name ()
  {int e;
   struct booktype *p,*head;
          struct borrowertype *card,*had;
   char borrower_name[16];
          do
          {printf (“请输入您要查找的卡的所有者的姓名.\n”);
    scanf (“%s”,borrower_name[16]);
        card=had;
        if (!had)
  {do
   { if (0==strcmp (card->name,borrower_name[16]))
    { printf (“此卡卡号为:%d\n”,card->cardnumber);
      printf (“此卡持有者的姓名为:%s\n”,card->name[20]);
                     printf (“此卡持有者的性别为:%s\n”,card->sex[10]);
                     printf (“此卡持有者的联系电话为:%d\n”,card->tel[10]);
                     printf (“此卡持有者的工作单位为:%d\n”,card->unit[80]);
                     p=head;
      if (!head)
       {do
        {if (card->cardnumber==p->borrowernum)
         {printf (“此卡已经借阅了图书\n”);
          printf (“该书的书号为:%d\n”,p->booknumber);
                  printf (“该书的书名为:%s\n”,p->bookname[20]);
                  printf (“该书出版单位为:%s\n”,p->press[50]);
                  printf (“该书作者为:%s\n”,p->auther[20]);
                  printf (“该书页数为:%d\n”,p->pagenumber);
                  printf (“该书定价为：%d\n”,p->price);
                          printf (“该书当前册数为:%d\n”,p->nownumber);
         }
                p=p->next;
       }while(!p);
      }
     }
  card=card->new;
        }while(!card);
  }
 printf(“是否继续进行查找操作？1、是,2、否\n”);
 scanf(“%d”,&e);
      }while(e==1);
  }
void look_for_word()
  { int a,j,m,i,n=1,e;
    struct booktype *p;
    struct booktype *head;
    char word[20];
           do
           {printf (“请输入书名关键字,按回车结束.\n”);
             scanf (“%s”,word[20]);
      a=0;
              do
              { a=a+1;
      }
      while (!word[a]);
      p=head;
      if (!head)
      do
       {for (j=1;!p->bookname[j];j++)
  {if (p->bookname[j]==word[1])
                    m=1;
                   do
                    { m++;
                    }
    while (m<=a && p->bookname[j+m]==word[1+m]);
                   i=1;
        printf (“该书的书号为:%d\n”,p->booknumber);
        printf (“该书的书名为:%s\n”,p->bookname[20]);
        printf (“该书出版单位为:%s\n”,p->press[50]);
        printf (“该书作者为:%s\n”,p->auther[20]);
        printf (“该书页数为:%d\n”,p->pagenumber);
        printf (“该书定价为：%d\n”,p->price);
                printf (“该书当前册数为:%d\n”,p->nownumber);
                    if (p->nownumber!=0)
      printf (“本书已被借出,借书者证号为:%d”,p->borrowernum);
      else printf (“本书未被借出.\n”);
  }
       p=p->next;
      }while (!p);
       printf (“对不起,没有您要查找的图书.”);
      printf(“是否继续进行查找操作？1、是,2、否\n”);
        scanf(“%d”,&e);
       }while(e==1);}
search()
{ int b,j;
 do
 { printf (“请选择你要查找的方式:\n 1,按书名查找;\n 2,按作者查找;\n 3,按出版单位查找;\n 4,按借阅者查找;\n 5,自定意查找.\n 6,退出\n”);
   scanf(“%d”,&j);
    if (j==1)
       look_for_name ();
       else if (j==2)
             look_for_writer ();
      else if (j==3)
                  look_for_press ();
                  else if (j==4)
                        look_for_borrower ();
        else if (j==5)
                             look_for_word ();
                             else if (j==6)
          end:;
  printf(“是否继续进行查找操作？1、是,2、否\n”);
  scanf(“%d”,&b);
 }while(b==1);
}
/*********************************************************** *************************/
lendbook()
{int i;
 int number;
 char ch;
 struct borrowertype *br_node,borrower;        /*指向借书者的指针*/
 struct booktype *bo_node,book;        /*指向图书的指针*/
 br_node=g_borrower_list;
 do{
   printf(“请输入借书证号”);
   scanf(“%d”,number);
   if(0!=strcmp(br_node->cardnumber,number))
    /*return br_node;*/
    br_node=br_node->next;
   /*br_node=find_borrowernode(number);*/
   if(!br_node)
   {
    puts(“系统中不存在该借书者”);
    goto lab_failed;
    }
  if(br_node->lendnumber>=1)
   {
    printf(“该借书者已借有图书”);
    goto lab_failed;
   }
  printf(“请输入要借图书书号”);
  scanf(“%d”,&number);
  /*bo_node=find_booknode(number);*/
  if(!bo_node)                 /*指针已指向书库末尾*/
   {
    puts(“系统中不存在该图书”);
    goto lab_failed;
   }
  if(bo_node->nownumber==0)
   {
   printf(“该书已被借给%s\n”,bo_node->borrowernum);
   goto lab_failed;
   }
 strcpy(br_node->booknumber,br_node->booknumber);
 strcpy(bo_node->borrowernum,br_node->cardnumber) ;
 br_node->lendnumber++;
 bo_node->nownumber–;
 bo_node->borrowtime=time(NULL);
 puts(“出借图书成功！”);
 lab_failed:
  puts(“\n出借图书失败”);
 puts(“是否继续借书操作? (1.是//2.否)”);
 scanf(“%d”,&i);


 } while(i==1);
if(1==2)
  exit(0);
}                               /*借书函数结束*/
/*********************************************************** *************************/
returnbook()               /*归还图书函数*/
/* {    */
{int number;
  char ch;
  int i=0,j=0;
  struct borrowertype *br_node;
  struct booktype   *bo_node;
 do
 {printf(“请输入还书者借书证号：”);
  scanf(“%d”,&number);


 if(0!=strcmp(br_node->cardnumber,number))
/*return br_node;*/
    br_node=br_node->next;
/*br_node=find_borrowernode(cardnumber);*/
  if(!br_node)
   {
    puts(“该借书证号不存在！”);
    goto lab_failed;
   }
  if(br_node->lendnumber==0)
    {
     puts(“该人未借书”);
     goto lab_failed;
    }
 printf(“请输入要还图书的书号：”);
 gets(number);
/* bo_node=find_booknode(number);  */
 if(!bo_node)
 {
 puts(“系统中并不存在该图书”);
 goto lab_failed;
 }
 if(bo_node->nownumber!=0)
   {
    puts(“该图书并未出借”);
    goto lab_failed;
   }
/* if(0==strcmp(br_node->booknumber,number))
   break;*/
 if(br_node->lendnumber==1)
   {
    printf(“该图书并不是被%s所借，而是被%s所借！”,br_node->cardnumber,bo_node->borrowernum);
    goto lab_failed;
   }
bo_node->returntime=time(NULL);
if(((int)difftime(bo_node->returntime,bo_node->borrowt ime)/3600/24)>7)
   {
    printf(“对不起,您超时了,请交纳5元罚款”);
   }
br_node->lendnumber–;
br_node->booknumber=0;
bo_node->borrowernum=’\0′;
puts(“\n归还图书成功！”);
lab_failed:
  puts(“归还图书失败！”);
printf(“是否继续进行还书操作? (1.是//2.否)”);
scanf(“%d”,&j);
}while(j==1);
if(1==2)
  exit(0);
  }                                 /*还书操作结束*/
/*********************************************************** *************************/
int create_borrower ()
{
   struct borrowertype * p =alloc_borrowernode( );
   char ch;
   puts(“\n\t《注策借书者》\n”);
   printf(“输入姓名：”);
   gets(p ->name);
   if(find_borrowernode(p ->name))
   {
/*是否有同名的存在 */
puts(“系统中有同名的借书者存在”);
goto lab_failed;
   }
printf(“输入性别：”);
gets(p->sex);
printf(“输入工作单位:”);
gets(p->unit);
printf(“确定注册该借书者吗？（Y/N）”);
ch=getch();
if(ch==’n'||ch==’N')
  goto lab_failed;
if(g_borrower_list)
{
  g_borrower_list->prev->next=p;
  p->prev= g_borrower_list->prev;
  g_borrower_list->prev=p;
}
else
{
g_borrower_list=p;
g_borrower_list->prev=g_borrower_list;
}
puts(“\n注册借书者成功！”);
getch();
return 0;
lab_failed:
        free_borrowertype(p);
    puts(“注册借书者失败！”);
    getch();
    return-1;
}
int remove_borrow()
{
   char name[20];
  char ch;
  struct borrowertype *p;
  puts(“\n\t<注销借书者>\n”);
  printf(“输入姓名：”);
  gets(name);
  p=find_borrownode(name);
if(!p)
{
  puts(“系统中不存在借书者”);
  goto lab_failed;
}
  printf(“确定该借书者吗？（Y/N）”);
  ch=getch();
  if(ch==’n'||ch==’N')
goto lab_failed;
  if(g_borrower_list==p)
{
  g_borrower_list=g_borrower_list->next;
  if(g_borrower_list)
g_borrower_list->prev=p->prev;
}
else
{
 p->prev->next=p->next;
   if(p->next)
       p->next->prev=p->prev;
}
free_borrownode(p);
puts(“\n注销该借书者成功！”);
getch();
return 0;
lab_failed:
   puts(“\n注销该借书者成功！”);
   getch();
   return-1;
}
/*********************************************************** *************************/
main()
{static struct booktype *g_book_list;                              /*定义图书链表*/
 static struct borrowertype *g_borrower_list;                          /*定义借书者链表*/
 int num;
 do
 {
 num=face();
 start();
   if(num==1){lendbook();}
     else if(num==2) {returnbook();}
     else if(num==3)
       {search();}
      else if(num==4)
       { kucaozuo();}
 }while(num!=0);
}


 


/*界面设计——Geoffrey.C*/
#include   <time.h>
#include   <process.h>
#include   <stdlib.h>
#include   <stdio.h>
#include   <dos.h>
#include   <conio.h>
#include   <graphics.h>
/*#define   Key_DOWN   80
  #define   Key_UP     72
  #define   Key_ESC    1
  #define   Key_ALT_X  45
  #define   Key_ENTER  28  */
/*获取键盘扫描码*/
int  getkey()
{
 union  REGS  rg;
 rg.h.ah=0;
 int86(0×16,&rg,&rg);
 return   rg.h.ah;
}
/*choosing函数实现了选中与未选中的字符颜色的改变*/
/*参数说明：this为当前选中的菜单条序号；last为刚刚离开的菜单条的序号*/
void choosing(int this,int last);
/*rect函数实现了画框的功能*/
/*x1、y1、x2、y2是所画框的左上角和右下角的坐标，以象素为单位，bordersize为框的宽度，color1，color2分别是所填充的颜色和线条的颜色，status是表示框凸起或是凹下的参数*/
void rect(int x1,int y1,int x2,int y2,int bordersize,int color1,int color2,int status);
char *m1[]={“   Borrow Book”,”   Return Book”,”   Search Book”,”  Manage of Book”,”Manage of Borrower”,”      Exit”};
/*本模块主函数*/
int face()
{time_t lt;
 int i,gdrive=DETECT,gmode;
 int current=1,past=0,key0,key1,m;
 char ch;
 initgraph(&gdrive,&gmode,”");
 setcolor(BLACK);                                    
setbkcolor(LIGHTGRAY);
 rect(1,1,638,60,1,LIGHTGRAY,LIGHTGRAY,1);
 settextstyle(3,0,5);
 setcolor(BLUE);
 outtextxy(15,5,”Library Manage System”);
 settextstyle(1,0,9);
 setcolor(YELLOW);
 outtextxy(200,100,”Welcome!”);
 setcolor(RED);    
 settextstyle(0,0,1);
 outtextxy(370,400,”Press KEY_UP KEY_DOWN to choose”);
 outtextxy(370,415,”Press ESC or ALT_X to exit system”);
 setcolor(5);
 settextstyle(3,0,1);
 outtextxy(350,220,”System make by : JetLee”);
 outtextxy(522,245,”Geoffrey.Z”);
 outtextxy(522,270,”Sakura.G”);
 outtextxy(522,295,”Angelo.S”);
 outtextxy(522,320,”John.H”);              
 settextstyle(0,0,1);
 for(i=0;i<=5;i++)               /*按顺序写入菜单条的文字*/
  {
   rect(10,80+i*60,170,120+i*60,1,7,7,1);
   outtextxy(20,95+i*60,m1);
  }
 rect(1,430,638,460,1,BLUE,7,1);
 setcolor(15);
 lt=time(NULL);                            /*获取进入系统的当地时间*/
 outtextxy(25,440,”You enter the system at:”);
 outtextxy(250,440,asctime(localtime(&lt)));
 while(1)
 {
  key0=0;
  key0=getkey();
  choosing(current,past);
  while(key0!=45&&key0!=28)    /*当获取的字符不是ALT_X和回车的时候进行循环*/
   {
    key1=getkey();
    if (key1==72||key1==80)
    {
     if(key1==45){return(0);}
     past=current;
     if(key1==72) current=(current==1)?6:current-1;     /*如果选中的菜单已经是第一个，但是还是输入了KEY_UP，就将选中的菜单变为最后一个*/
     if(key1==80) current=(current==6)?1:current+1;     /*如果选中的菜单已经是最后一个，但是还是输入了KEY_DOWN，就将选中的菜单变为第一个*/
     if(key1==45) {return(0);}
     choosing(current,past);
    }
    else {/*根据选项所选中的菜单，返回相应的值*/
   if((key1==1)||(key1==45)||((current==6)&&key1==28)) return(0);    /*本程序共提供了三种退出方式：按ESC键、按ALT_X键和选中EXIT项，然后回车*/
   if((current==1)&&key1==28) {return(1);}
   if((current==2)&&key1==28) {return(2);}
   if((current==3)&&key1==28) {return(3);}
          if((current==4)&&key1==28) {return(4);}
   if((current==5)&&key1==28) {return(5);}
          }
  }


 }
 closegraph();                /*关闭图形界面*/
}
void rect(int x1,int y1,int x2,int y2,int bordersize,int color1,int color2,int status)
{
 int i;
 setcolor(DARKGRAY);
 rectangle(x1,y1,x2,y2);
 setfillstyle(SOLID_FILL,color1);
 floodfill(x1+bordersize+1,y1+bordersize+1,DARKGRAY);
 rectangle(x1+bordersize,y1+bordersize,x2-bordersize,y2 -bordersize);
 setfillstyle(SOLID_FILL,color2);
 floodfill(x1+1,y1+1,8);
 setcolor(WHITE);
 if (status==0)
   {
    line(x2-bordersize,y1+bordersize,x2-bordersize,y2-bordersize );
    line(x1+bordersize,y1+bordersize,x2-bordersize,y2-bordersize );
   }
 else
   {
    line(x1+bordersize,y1+bordersize,x2-bordersize,y1+bordersize );
    line(x1+bordersize,y1+bordersize,x1+bordersize,y2-bordersize );
   }
}
void choosing(int this,int last)
{
 setcolor(WHITE);
 outtextxy(20,95+(last-1)*60,m1[last-1]);
 setcolor(LIGHTBLUE);
 outtextxy(20,95+(this-1)*60,m1[this-1]);
}
/*start函数实现的是初始化文本界面的功能*/
void start()
{
 int gmode,num,gdrive=DETECT;
 registerbgidriver(DETECT);
 initgraph(&gdrive,&gmode,”");
 setbkcolor(BLUE);
 cleardevice();
 setbkcolor(1);
}


