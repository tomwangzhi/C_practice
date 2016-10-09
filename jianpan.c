#include<reg52.h>
#define uchar unsigned char
uchar code  table[]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5c,0x79};
sbit key1=P3^4;
sbit key2=P3^5;
sbit key3=P3^6;
sbit key4=P3^7;
sbit wei=P2^7;
sbit duan=P2^6;

uchar temp,num;
sbit led1=P1^0;
sbit led2=P1^1;
sbit led3=P1^2;
sbit led4=P1^3;
int main(void)
{
    wei=1;
    P0=0xfe;
    wei=0;
    P3=0xff;
    while(1)
    {
        if(key1==0)
           {
            led1=0;
            num++;
            duan=1;
            P0=table[num];
            duan=0;
            if(num==10)
            num=0;
           }
            else
            led1=1;
           
        if(key2==0)
            led2=0;
             else
            led2=1;
             if(key3==0)
            led3=0;
             else
            led3=1;
            if(key4==0)
            led4=0;
             else
            led4=1;


    }



    return 0;
}