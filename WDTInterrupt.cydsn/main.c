

#include "project.h"

void wdtInterruptHandler()
{
    blue_Write(~blue_Read());
    CySysWdtClearInterrupt(CY_SYS_WDT_COUNTER0_INT);
    
}


int main(void)
{
    
    if(CySysGetResetReason(CY_SYS_RESET_WDT) == CY_SYS_RESET_WDT )
    {
        red_Write(0); // turn on the red LED
        while(1);     // hang
    }
    
    CyGlobalIntEnable; /* Enable global interrupts. */
  
    
    isr_1_StartEx(wdtInterruptHandler);
    
    CySysWdtEnable(CY_SYS_WDT_COUNTER0);
   
    for(;;)
    {
        CySysPmDeepSleep();
          
    }
}
