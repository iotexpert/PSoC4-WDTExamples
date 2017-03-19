
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    if(CySysGetResetReason(CY_SYS_RESET_WDT) == CY_SYS_RESET_WDT )
    {
        CySysWdtDisable(CY_SYS_WDT_COUNTER0_MASK);
        red_Write(0); // turn on the red LED
        while(1);     // hang
    }

    for(;;)
    {
        blue_Write(~blue_Read());
        // If dont feed the WDT it will cause a reset in ~3 seconds
        //CySysWatchdogFeed(CY_SYS_WDT_COUNTER0);
        CyDelay(100);
          
    }
}
