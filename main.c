//build-in LED are P0.0 to P0.3
#include "LPC17xx.h"                    // Device header
void delay(long int time);
int main () {
	int x =1;
	//initialize system
	SystemInit ();
//initialize clock
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL4 = 0x0000;
	LPC_GPIO2->FIODIR &= ~(1<<10);


	//configure P0.0 to P0.3 as GPIO
	LPC_PINCON->PINSEL0 = 0x00000000;
	//configure direction for P0.0 to P0.3 as output
	LPC_GPIO0->FIODIR |= 1<<3|1<<2|1<<1|1<<0;
	//configure P.12, P2.11, P2.2, P2.1
	LPC_PINCON->PINSEL4 = 0x000000000;
	//configure direction P.12, P2.11, P2.2, P2.1
	LPC_GPIO2->FIODIR |= 1<<12|1<<11|1<<1|1<<2;
	

		while (1) {
		//set our pins P0.0 to P0.3
		x =((LPC_GPIO2->FIOPIN>>10)&1);
		 if (x == 0) {
			LPC_GPIO0->FIOCLR |= 1<<3;
			delay (500000);
			LPC_GPIO0->FIOCLR |= 1<<2;
			delay (500000);
			LPC_GPIO0->FIOCLR |= 1<<1;
			delay (500000);
			LPC_GPIO0->FIOCLR|= 1<<0;
			delay (500000);
			//P2 separation
			LPC_GPIO2->FIOSET |= 1<<12;
			delay (500000);
			LPC_GPIO2->FIOSET |= 1<<11;
			delay (500000);
			LPC_GPIO2->FIOSET |= 1<<2;
			delay (500000);
			LPC_GPIO2->FIOSET |= 1<<1;
			delay (500000);
		 }
			//clearing all pins
			LPC_GPIO0->FIOSET |= 1<<3|1<<2|1<<1|1<<0;
			delay (500000);
			LPC_GPIO2->FIOCLR |= 1<<12|1<<11|1<<1|1<<2;
			delay (500000);
			
	
			}
		return 0;

}
		

void delay(long int time) {
	long int j,i=0;
	for (i = 0; i < time; i++);
	for (j = 0; j < time; j++);

}
