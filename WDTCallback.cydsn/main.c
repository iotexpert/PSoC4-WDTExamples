
#include "project.h"

void wdtInterruptCallback()
{
    blue_Write(~blue_Read());   
}


int main(void)
{
    CyGlobalIntEnable; 
    
    if(CySysGetResetReason(CY_SYS_RESET_WDT) == CY_SYS_RESET_WDT )
    {
        CySysWdtDisable(CY_SYS_WDT_COUNTER0_MASK); // Disable the WDT
        red_Write(0); // Turn on the red LED
        while(1);     // Hang
    }
 
    CySysWdtSetInterruptCallback(CY_SYS_WDT_COUNTER0,wdtInterruptCallback);

    for(;;)
    {
        CySysPmDeepSleep(); // Put the chip into deep sleep.       
    }
}

