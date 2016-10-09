#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit dula=P2^6;
uchar t,key;
uchar code  table[]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5c,0x79};
void delay(uint z)
{
    uint x,y;
    for(x=z;x>0;x--)
        for(y=110;y>0;y--);
}
void display(uchar num)
{
     dula=1;
    P0=table[num];
    
    dula=0;

}
void keyscan()
{
    
    P3=0xFE;
    t=P3;
    t=t&0xf0;
    if(t!=0xf0)
    {
        delay(10);
        t=P3;
        t=t&0xf0;
        if(t!=0xf0)
        {
            switch(t)
            {
                case 0xee :
               { key=0;
                break;
				}
                case 0xde :
                {key=1;
                break;}
                case 0xbe :
                {key=2;
                break;}

                
            }
			while(t!=0xf0)
			{
				t=P3;
				t=t&0xf0;
			}
               display(key); 
                
                
        }
		 
    }
	 			    
}
void main()
{
    while(1)
	{
    keyscan();
	}
}