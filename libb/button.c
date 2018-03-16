#include "button.h"
	
void Button1_enable(){
  unsigned int tim = 0;
  if(~BUTTON1){
	  Delay1ms(20);
		if(~BUTTON1){
		  while(~BUTTON1 & tim <= LONG_TIME){
		    Delay1ms(10);
		    tim++;
		  }
		  if(tim >= LONG_TIME){
		  //长按操作
		  Button1_lclick();		
		  }else if(tim >= 5){
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

}