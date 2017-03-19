
#include "project.h"

void wdtInterruptHandler()
{
    while(1) WDTSignal1_Write(~WDTSignal1_Read());
}

int main(void)
{
  
    WDTSignal0_Write(1);
  
    if(CySysGetResetReason(CY_SYS_RESET_WDT) == CY_SYS_RESET_WDT )
    {
        CySysWdtDisable(CY_SYS_WDT_COUNTER0_MASK);
        red_Write(0); // turn on the red LED
        while(1);     // hang
    }
    
    isr_1_StartEx(wdtInterruptHandler);
    
    CySysWdtEnable(CY_SYS_WDT_COUNTER0);
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    for(;;)
    {
    }
}
