#include<reg51.h>
void uart_start()
{
	TMOD=0X20;
	TH1=0XFD;
	SCON=0X50;
	TR1=1;
}

void transmit_data(char tx_data)
{
	SBUF=tx_data;
	while(TI==0);
	TI=0;
}

void String(char*str)
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		transmit_data(str[i]);
	}
}

void main()
{
	uart_start();
	String("Hello World");
	while(1);
}
	
	