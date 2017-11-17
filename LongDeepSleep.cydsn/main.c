/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

void wdtCallback()
{
    RED_Write(~RED_Read());
    
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    CySysWdtSetInterruptCallback(CY_SYS_WDT_COUNTER1,wdtCallback);
    CySysWdtSetCascade(CY_SYS_WDT_CASCADE_01);
    
    CySysWdtSetMatch(0,512);
    CySysWdtSetMatch(1,64);
    // Total divide = 512*64 = 32768 
    
    for(;;)
    {
        CySysPmDeepSleep();
    }
}

/* [] END OF FILE */
