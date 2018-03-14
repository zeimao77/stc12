#include "button.h"

void Button1_click(){

}

void Button1_dbclick(){

}

void Button1_lclick(){

}

void Button1_enable(){
  unsigned int tim = 0;
  if(BUTTON1 == 0){
	  Delay1ms(20);
		while(~BUTTON1 & tim <= LONG_TIME){
		  Delay1ms(10);
		  tim++;
		}
		if(tim >= LONG_TIME){
		//长按操作
		Button1_lclick();		
		}else{
		  tim = 0;
		  while(BUTTON1 & tim <= INTERVAL_TIME){
			Delay1ms(20);
			tim++;
		    if(BUTTON1 == 0){
					//双击操作
					Button1_dbclick();
				  break;
				}
			}
		  if(tim > INTERVAL_TIME){
				//单击操作
			  Button1_click();
		  }
		  }
		  
		while(~BUTTON1);
	}

}