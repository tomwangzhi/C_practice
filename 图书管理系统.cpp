C���Ե۹�C���ԡ�C���Ե۹���C����ѧϰ��վ�����ѧϰ��վ��C���Խ̡̳�C������̳��C���Ի���

  SEARCH
����RSS
��ҳ
C���Ե۹�QQȺ
��ҳ > �����Դ������ > C/C++Դ���빲�� > C����ͼ�����ϵͳ������Դ����(��)
2006
09-28
C����ͼ�����ϵͳ������Դ����(��)
cboyC/C++Դ���빲��һ������
/*********************************************************** *************************/
void look_for_name ()
   { struct booktype *head,*p;
    int i,n=1,e;
     do
     {char borrow_name[20];
      printf (������������Ҫ���ҵ�����,���س�����.��);
      scanf (��%s��,borrow_name);
  p=head;
  if (!head)
           {do
     { if (0==strcmp (p->bookname,borrow_name))
      { i=1;
        printf (����������Ϊ:%d\n��,p->booknumber);
        printf (�����������Ϊ:%s\n��,p->bookname[20]);
        printf (��������浥λΪ:%s\n��,p->press[50]);
        printf (����������Ϊ:%s\n��,p->auther[20]);
        printf (������ҳ��Ϊ:%d\n��,p->pagenumber);
        printf (�����鶨��Ϊ��%d\n��,p->price);
                printf (�����鵱ǰ����Ϊ:%d\n��,p->nownumber);
                    if (p->nownumber!=0)
      printf (�������ѱ����,������֤��Ϊ:%d��,p->borrowernum);
             else printf (������δ�����.\n��);
      }
     p=p->next;
     }while(!p);
         }
         else printf (���Բ��𣬿���û��ͼ��!\n��);
         if (i!=1)
         printf (���Բ���,û����Ҫ���ҵ�ͼ��.\n��);
        printf(���Ƿ�������в��Ҳ�����1����,2����\n��);
        scanf(��%d��,&e);
     }while(e==1);
   }
 void look_for_writer ()
   { struct booktype *head,*p;
     int e,i,n=1;
     char borrow_writer[16];
      do
      {printf (������������Ҫ���ҵ��������,���س�����.\n��);
       scanf (��%s��,borrow_writer[16]);
   p=head;
   if (!head)
           {do
     {if(0==strcmp (p->auther[20],borrow_writer[16]))
       {i=1;
        printf (����������Ϊ:%d\n��,p->booknumber);
        printf (�����������Ϊ:%s\n��,p->bookname[20]);
        printf (��������浥λΪ:%s\n��,p->press[50]);
        printf (����������Ϊ:%s\n��,p->auther[20]);
        printf (������ҳ��Ϊ:%d\n��,p->pagenumber);
        printf (�����鶨��Ϊ��%d\n��,p->price);
           printf (�����鵱ǰ����Ϊ:%d\n��,p->nownumber);
                    if (p->nownumber!=0)
      printf (�������ѱ����,������֤��Ϊ:%d��,p->borrowernum);
     else printf (������δ�����.\n��);
      }
     p=p->next;
    }while(!p);
          }
         else printf (���Բ��𣬿���û��ͼ��!\n��);
         if (i!=1)
   printf (���Բ���,û����Ҫ���ҵ�ͼ��.\n��);
       printf(���Ƿ�������в��Ҳ�����1����,2����\n��);
       scanf(��%d��,&e);
     }while(e==1);
   }
 void look_for_press()
 { int i=0,e;
   struct booktype *head, *p;
   char borrow_press[40];
   do
   {printf (������������Ҫ���ҵ���ĳ��浥λ,���س�����.\n��);
       scanf (��%s��,borrow_press);
    p=head;
    if (!head)
    { do
     { if (0==strcmp (p->press,borrow_press))
        {i=1;
  printf (����������Ϊ:%d\n��,p->booknumber);
        printf (�����������Ϊ:%s\n��,p->bookname[20]);
        printf (��������浥λΪ:%s\n��,p->press[50]);
        printf (����������Ϊ:%s\n��,p->auther[20]);
        printf (������ҳ��Ϊ:%d\n��,p->pagenumber);
        printf (�����鶨��Ϊ��%d\n��,p->price);
           printf (�����鵱ǰ����Ϊ:%d\n��,p->nownumber);
                    if (p->nownumber!=0)
      printf (�������ѱ����,������֤��Ϊ:%d��,p->borrowernum);
     else printf (������δ�����.\n��);
  }
    p=p->next;
    }while(!p);
          }
          else printf (���Բ��𣬿���û��ͼ��!\n��);
       if (i!=1)
  printf (���Բ���,û����Ҫ���ҵ�ͼ��.\n��);
       printf(���Ƿ�������в��Ҳ�����1����,2����\n��);
        scanf(��%d��,&e);
     }while(e==1);
 }
void look_for_number()
     { int i,e;
       struct booktype *head,*p;
       int borrow_nomber;
       do
       {printf (����������Ҫ���ҵ�������,���س�����.\n��);
        scanf (��%d��,&borrow_nomber);
    p=head;
    if (!head)
    {do
     { if (p->booknumber==borrow_nomber)
       { i=1;
        printf (����������Ϊ:%d\n��,p->booknumber);
        printf (�����������Ϊ:%s\n��,p->bookname[20]);
        printf (��������浥λΪ:%s\n��,p->press[50]);
        printf (����������Ϊ:%s\n��,p->auther[20]);
        printf (������ҳ��Ϊ:%d\n��,p->pagenumber);
        printf (�����鶨��Ϊ��%d\n��,p->price);
                printf (�����鵱ǰ����Ϊ:%d\n��,p->nownumber);
                    if (p->nownumber!=0)
      printf (�������ѱ����,������֤��Ϊ:%d��,p->borrowernum);
     else printf (������δ�����.\n��);
       }
       p=p->next;
     }while(!p);
    }
           else printf (���Բ��𣬿���û��ͼ��!\n��);
   if (i!=1)
     printf (���Բ���,û����Ҫ���ҵ�ͼ��.\n��);
         printf(���Ƿ�������в��Ҳ�����1����,2����\n��);
        scanf(��%d��,&e);
       }while(e==1);
     }
   void look_for_borrower ()
 {void look_card_num ();
  void look_card_name ();
   char borrower_name[20];
   int n,d,e;
          do
   {printf (������ѡ����Ҫ���ҵķ�ʽ:1,�������ߵĿ���\n;2�������ߵ�����;\n;3���˳�\n��);
           scanf (��%d��,&n);
           if (n==1)
      look_card_num ();
              else if (n==2)
      look_card_name ();
                     else if (n==3)
                           exit (0);
          printf(���Ƿ�������в��Ҳ�����1����,2����\n��);
          scanf(��%d��,&e);
         }while(e==1);
 }
       void look_card_num ()
  { struct booktype *head, *p;
    struct borrowertype *card,*hed;
    int m,e;
           do
           {printf (����������Ҫ���ҵĿ��Ŀ���.\n��);
     scanf (��%d��,&m);
  card=hed;
  if (!hed)
  {do
   { if (card->cardnumber==m)
    { printf (���˿�����Ϊ:%d\n��,card->cardnumber);
     printf (���˿������ߵ�����Ϊ:%s\n��,card->name[20]);
                    printf (���˿������ߵ��Ա�Ϊ:%s\n��,card->sex[10]);
                    printf (���˿������ߵ���ϵ�绰Ϊ:%d\n��,card->tel[10]);
                    printf (���˿������ߵĹ�����λΪ:%d\n��,card->unit[80]);
                    p=head;
             if (!head)
     {do
       { if (card->cardnumber==p->borrowernum)
        {printf (���˿��Ѿ�������ͼ��\n��);
         printf (����������Ϊ:%d\n��,p->booknumber);
                 printf (�����������Ϊ:%s\n��,p->bookname[20]);
                 printf (��������浥λΪ:%s\n��,p->press[50]);
                 printf (����������Ϊ:%s\n��,p->auther[20]);
                 printf (������ҳ��Ϊ:%d\n��,p->pagenumber);
                 printf (�����鶨��Ϊ��%d\n��,p->price);
                         printf (�����鵱ǰ����Ϊ:%d\n��,p->nownumber);
        }
       p=p->next;
      }while(!p);
     }
                     printf (���˿�������.��);
    card=card->new;}
  else printf (���˿��Ų�����.\n��);
                  }while(!card);
       printf(���Ƿ�������в��Ҳ�����1����,2����\n��);
               scanf(��%d��,&e);
              }
             }while(e==1);
         }
  void look_card_name ()
  {int e;
   struct booktype *p,*head;
          struct borrowertype *card,*had;
   char borrower_name[16];
          do
          {printf (����������Ҫ���ҵĿ��������ߵ�����.\n��);
    scanf (��%s��,borrower_name[16]);
        card=had;
        if (!had)
  {do
   { if (0==strcmp (card->name,borrower_name[16]))
    { printf (���˿�����Ϊ:%d\n��,card->cardnumber);
      printf (���˿������ߵ�����Ϊ:%s\n��,card->name[20]);
                     printf (���˿������ߵ��Ա�Ϊ:%s\n��,card->sex[10]);
                     printf (���˿������ߵ���ϵ�绰Ϊ:%d\n��,card->tel[10]);
                     printf (���˿������ߵĹ�����λΪ:%d\n��,card->unit[80]);
                     p=head;
      if (!head)
       {do
        {if (card->cardnumber==p->borrowernum)
         {printf (���˿��Ѿ�������ͼ��\n��);
          printf (����������Ϊ:%d\n��,p->booknumber);
                  printf (�����������Ϊ:%s\n��,p->bookname[20]);
                  printf (��������浥λΪ:%s\n��,p->press[50]);
                  printf (����������Ϊ:%s\n��,p->auther[20]);
                  printf (������ҳ��Ϊ:%d\n��,p->pagenumber);
                  printf (�����鶨��Ϊ��%d\n��,p->price);
                          printf (�����鵱ǰ����Ϊ:%d\n��,p->nownumber);
         }
                p=p->next;
       }while(!p);
      }
     }
  card=card->new;
        }while(!card);
  }
 printf(���Ƿ�������в��Ҳ�����1����,2����\n��);
 scanf(��%d��,&e);
      }while(e==1);
  }
void look_for_word()
  { int a,j,m,i,n=1,e;
    struct booktype *p;
    struct booktype *head;
    char word[20];
           do
           {printf (�������������ؼ���,���س�����.\n��);
             scanf (��%s��,word[20]);
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
        printf (����������Ϊ:%d\n��,p->booknumber);
        printf (�����������Ϊ:%s\n��,p->bookname[20]);
        printf (��������浥λΪ:%s\n��,p->press[50]);
        printf (����������Ϊ:%s\n��,p->auther[20]);
        printf (������ҳ��Ϊ:%d\n��,p->pagenumber);
        printf (�����鶨��Ϊ��%d\n��,p->price);
                printf (�����鵱ǰ����Ϊ:%d\n��,p->nownumber);
                    if (p->nownumber!=0)
      printf (�������ѱ����,������֤��Ϊ:%d��,p->borrowernum);
      else printf (������δ�����.\n��);
  }
       p=p->next;
      }while (!p);
       printf (���Բ���,û����Ҫ���ҵ�ͼ��.��);
      printf(���Ƿ�������в��Ҳ�����1����,2����\n��);
        scanf(��%d��,&e);
       }while(e==1);}
search()
{ int b,j;
 do
 { printf (����ѡ����Ҫ���ҵķ�ʽ:\n 1,����������;\n 2,�����߲���;\n 3,�����浥λ����;\n 4,�������߲���;\n 5,�Զ������.\n 6,�˳�\n��);
   scanf(��%d��,&j);
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
  printf(���Ƿ�������в��Ҳ�����1����,2����\n��);
  scanf(��%d��,&b);
 }while(b==1);
}
/*********************************************************** *************************/
lendbook()
{int i;
 int number;
 char ch;
 struct borrowertype *br_node,borrower;        /*ָ������ߵ�ָ��*/
 struct booktype *bo_node,book;        /*ָ��ͼ���ָ��*/
 br_node=g_borrower_list;
 do{
   printf(�����������֤�š�);
   scanf(��%d��,number);
   if(0!=strcmp(br_node->cardnumber,number))
    /*return br_node;*/
    br_node=br_node->next;
   /*br_node=find_borrowernode(number);*/
   if(!br_node)
   {
    puts(��ϵͳ�в����ڸý����ߡ�);
    goto lab_failed;
    }
  if(br_node->lendnumber>=1)
   {
    printf(���ý������ѽ���ͼ�顱);
    goto lab_failed;
   }
  printf(��������Ҫ��ͼ����š�);
  scanf(��%d��,&number);
  /*bo_node=find_booknode(number);*/
  if(!bo_node)                 /*ָ����ָ�����ĩβ*/
   {
    puts(��ϵͳ�в����ڸ�ͼ�顱);
    goto lab_failed;
   }
  if(bo_node->nownumber==0)
   {
   printf(�������ѱ����%s\n��,bo_node->borrowernum);
   goto lab_failed;
   }
 strcpy(br_node->booknumber,br_node->booknumber);
 strcpy(bo_node->borrowernum,br_node->cardnumber) ;
 br_node->lendnumber++;
 bo_node->nownumber�C;
 bo_node->borrowtime=time(NULL);
 puts(������ͼ��ɹ�����);
 lab_failed:
  puts(��\n����ͼ��ʧ�ܡ�);
 puts(���Ƿ�����������? (1.��//2.��)��);
 scanf(��%d��,&i);


 } while(i==1);
if(1==2)
  exit(0);
}                               /*���麯������*/
/*********************************************************** *************************/
returnbook()               /*�黹ͼ�麯��*/
/* {    */
{int number;
  char ch;
  int i=0,j=0;
  struct borrowertype *br_node;
  struct booktype   *bo_node;
 do
 {printf(�������뻹���߽���֤�ţ���);
  scanf(��%d��,&number);


 if(0!=strcmp(br_node->cardnumber,number))
/*return br_node;*/
    br_node=br_node->next;
/*br_node=find_borrowernode(cardnumber);*/
  if(!br_node)
   {
    puts(���ý���֤�Ų����ڣ���);
    goto lab_failed;
   }
  if(br_node->lendnumber==0)
    {
     puts(������δ���顱);
     goto lab_failed;
    }
 printf(��������Ҫ��ͼ�����ţ���);
 gets(number);
/* bo_node=find_booknode(number);  */
 if(!bo_node)
 {
 puts(��ϵͳ�в������ڸ�ͼ�顱);
 goto lab_failed;
 }
 if(bo_node->nownumber!=0)
   {
    puts(����ͼ�鲢δ���衱);
    goto lab_failed;
   }
/* if(0==strcmp(br_node->booknumber,number))
   break;*/
 if(br_node->lendnumber==1)
   {
    printf(����ͼ�鲢���Ǳ�%s���裬���Ǳ�%s���裡��,br_node->cardnumber,bo_node->borrowernum);
    goto lab_failed;
   }
bo_node->returntime=time(NULL);
if(((int)difftime(bo_node->returntime,bo_node->borrowt ime)/3600/24)>7)
   {
    printf(���Բ���,����ʱ��,�뽻��5Ԫ���);
   }
br_node->lendnumber�C;
br_node->booknumber=0;
bo_node->borrowernum=��\0��;
puts(��\n�黹ͼ��ɹ�����);
lab_failed:
  puts(���黹ͼ��ʧ�ܣ���);
printf(���Ƿ�������л������? (1.��//2.��)��);
scanf(��%d��,&j);
}while(j==1);
if(1==2)
  exit(0);
  }                                 /*�����������*/
/*********************************************************** *************************/
int create_borrower ()
{
   struct borrowertype * p =alloc_borrowernode( );
   char ch;
   puts(��\n\t��ע�߽����ߡ�\n��);
   printf(��������������);
   gets(p ->name);
   if(find_borrowernode(p ->name))
   {
/*�Ƿ���ͬ���Ĵ��� */
puts(��ϵͳ����ͬ���Ľ����ߴ��ڡ�);
goto lab_failed;
   }
printf(�������Ա𣺡�);
gets(p->sex);
printf(�����빤����λ:��);
gets(p->unit);
printf(��ȷ��ע��ý������𣿣�Y/N����);
ch=getch();
if(ch==��n'||ch==��N')
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
puts(��\nע������߳ɹ�����);
getch();
return 0;
lab_failed:
        free_borrowertype(p);
    puts(��ע�������ʧ�ܣ���);
    getch();
    return-1;
}
int remove_borrow()
{
   char name[20];
  char ch;
  struct borrowertype *p;
  puts(��\n\t<ע��������>\n��);
  printf(��������������);
  gets(name);
  p=find_borrownode(name);
if(!p)
{
  puts(��ϵͳ�в����ڽ����ߡ�);
  goto lab_failed;
}
  printf(��ȷ���ý������𣿣�Y/N����);
  ch=getch();
  if(ch==��n'||ch==��N')
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
puts(��\nע���ý����߳ɹ�����);
getch();
return 0;
lab_failed:
   puts(��\nע���ý����߳ɹ�����);
   getch();
   return-1;
}
/*********************************************************** *************************/
main()
{static struct booktype *g_book_list;                              /*����ͼ������*/
 static struct borrowertype *g_borrower_list;                          /*�������������*/
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


 


/*������ơ���Geoffrey.C*/
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
/*��ȡ����ɨ����*/
int  getkey()
{
 union  REGS  rg;
 rg.h.ah=0;
 int86(0��16,&rg,&rg);
 return   rg.h.ah;
}
/*choosing����ʵ����ѡ����δѡ�е��ַ���ɫ�ĸı�*/
/*����˵����thisΪ��ǰѡ�еĲ˵�����ţ�lastΪ�ո��뿪�Ĳ˵��������*/
void choosing(int this,int last);
/*rect����ʵ���˻���Ĺ���*/
/*x1��y1��x2��y2������������ϽǺ����½ǵ����꣬������Ϊ��λ��bordersizeΪ��Ŀ�ȣ�color1��color2�ֱ�����������ɫ����������ɫ��status�Ǳ�ʾ��͹����ǰ��µĲ���*/
void rect(int x1,int y1,int x2,int y2,int bordersize,int color1,int color2,int status);
char *m1[]={��   Borrow Book��,��   Return Book��,��   Search Book��,��  Manage of Book��,��Manage of Borrower��,��      Exit��};
/*��ģ��������*/
int face()
{time_t lt;
 int i,gdrive=DETECT,gmode;
 int current=1,past=0,key0,key1,m;
 char ch;
 initgraph(&gdrive,&gmode,��");
 setcolor(BLACK);                                    
setbkcolor(LIGHTGRAY);
 rect(1,1,638,60,1,LIGHTGRAY,LIGHTGRAY,1);
 settextstyle(3,0,5);
 setcolor(BLUE);
 outtextxy(15,5,��Library Manage System��);
 settextstyle(1,0,9);
 setcolor(YELLOW);
 outtextxy(200,100,��Welcome!��);
 setcolor(RED);    
 settextstyle(0,0,1);
 outtextxy(370,400,��Press KEY_UP KEY_DOWN to choose��);
 outtextxy(370,415,��Press ESC or ALT_X to exit system��);
 setcolor(5);
 settextstyle(3,0,1);
 outtextxy(350,220,��System make by : JetLee��);
 outtextxy(522,245,��Geoffrey.Z��);
 outtextxy(522,270,��Sakura.G��);
 outtextxy(522,295,��Angelo.S��);
 outtextxy(522,320,��John.H��);              
 settextstyle(0,0,1);
 for(i=0;i<=5;i++)               /*��˳��д��˵���������*/
  {
   rect(10,80+i*60,170,120+i*60,1,7,7,1);
   outtextxy(20,95+i*60,m1);
  }
 rect(1,430,638,460,1,BLUE,7,1);
 setcolor(15);
 lt=time(NULL);                            /*��ȡ����ϵͳ�ĵ���ʱ��*/
 outtextxy(25,440,��You enter the system at:��);
 outtextxy(250,440,asctime(localtime(&lt)));
 while(1)
 {
  key0=0;
  key0=getkey();
  choosing(current,past);
  while(key0!=45&&key0!=28)    /*����ȡ���ַ�����ALT_X�ͻس���ʱ�����ѭ��*/
   {
    key1=getkey();
    if (key1==72||key1==80)
    {
     if(key1==45){return(0);}
     past=current;
     if(key1==72) current=(current==1)?6:current-1;     /*���ѡ�еĲ˵��Ѿ��ǵ�һ�������ǻ���������KEY_UP���ͽ�ѡ�еĲ˵���Ϊ���һ��*/
     if(key1==80) current=(current==6)?1:current+1;     /*���ѡ�еĲ˵��Ѿ������һ�������ǻ���������KEY_DOWN���ͽ�ѡ�еĲ˵���Ϊ��һ��*/
     if(key1==45) {return(0);}
     choosing(current,past);
    }
    else {/*����ѡ����ѡ�еĲ˵���������Ӧ��ֵ*/
   if((key1==1)||(key1==45)||((current==6)&&key1==28)) return(0);    /*�������ṩ�������˳���ʽ����ESC������ALT_X����ѡ��EXIT�Ȼ��س�*/
   if((current==1)&&key1==28) {return(1);}
   if((current==2)&&key1==28) {return(2);}
   if((current==3)&&key1==28) {return(3);}
          if((current==4)&&key1==28) {return(4);}
   if((current==5)&&key1==28) {return(5);}
          }
  }


 }
 closegraph();                /*�ر�ͼ�ν���*/
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
/*start����ʵ�ֵ��ǳ�ʼ���ı�����Ĺ���*/
void start()
{
 int gmode,num,gdrive=DETECT;
 registerbgidriver(DETECT);
 initgraph(&gdrive,&gmode,��");
 setbkcolor(BLUE);
 cleardevice();
 setbkcolor(1);
}


