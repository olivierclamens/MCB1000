#include "LPC11xx.h"                    // Device header
#include "cmsis_os.h"                   // CMSIS RTOS header file

//Example for IT2R Extension Board | GPIO P3.0 and P3.1 tests 
//Warning : SysClk 48MHz
//OK 01/III/2019
void Th01 (void const *argument)  {              // thread function 'job1'
  while (1)  {
                                                 // execute some code
    LPC_GPIO3->DATA ^= 0x01;   
    osDelay (1000);                                // delay execution for 10 milliseconds
  }
}
// define job1 as thread function
osThreadDef(Th01, osPriorityAboveNormal, 1, 0);  // define job1 as thread function

int main (void) {                                // program execution starts here
  osKernelInitialize ();                         // initialize RTOS kernel
                                                 // setup and initialize peripherals
	//LPC_SYSCON->SYSAHBCLKCTRL |= 1 << 6;   /* Enable clock for GPIO (1 as Reset Value)      */
  LPC_GPIO3->DIR   = 0x000000FF;         /* PORT3 defined as Output  */
  LPC_GPIO3->DATA &= 0xFFFFFF00;   
	
  osThreadCreate (osThread(Th01),NULL);
	
  osKernelStart ();                              // start kernel with job2 execution
}
