
#include <avr/io.h>

#include <avr/signal.h>
#include <avr/interrupt.h>



#include "avrx.h"               // AvrX System calls/data structures

#include "config.h"

#include "reader.h"
#include "panel.h"

//AVRX_GCC_TASK(Monitor, 20, 0);          // External Task: Debug Monitor

#include "hd44780.h"

AVRX_SIGINT(SIG_OVERFLOW0)
{
    IntProlog();                // Save interrupted context, switch stacks
    TCNT0 = TCNT0_INIT;			// Reload the timer counter
	AvrXTimerHandler();         // Process Timer queue
    Epilog();                   // Restore context of next running task
};


int main(void)
{
    AvrXSetKernelStack(0);

    //MCUCR = 1<<SE;      	// Enable "sleep" mode (low power when idle)
    TCNT0 = TCNT0_INIT;		// Load overflow counter of timer0
    TCCR0 = TMC8_CK256;		// Set Timer0 to CPUCLK/256
    TIMSK = 1<<TOIE0;		// Enable interrupt flag
	
    //InitSerialIO(UBRR_INIT);    // Initialize USART baud rate generator

	//AvrXRunTask(TCB(Monitor));
	AvrXRunTask(TCB(reader));
	AvrXRunTask(TCB(panel));
	
    /* Needed for EEPROM access in monitor */
	AvrXSetSemaphore(&EEPromMutex);
	
 	hd44780_init();
	hd44780_clear_line(0);
			
	hd44780_print("Muh");
	
	
    Epilog();                   // Switch from AvrX Stack to first task
    while(1);
};
