/****************************************************************************
 *   $Id:: ssptest.c 9380 2012-04-19 23:03:05Z nxp41306                     $
 *   Project: NXP LPC11xx SSP example
 *
 *   Description:
 *     This file contains SSP test modules, main entry, to test SSP APIs.
 *
 ****************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
****************************************************************************/
#include "LPC11xx.h"                        /* LPC11xx definitions */
#include "gpio.h"
#include "ssp.h"
#if SSP_DEBUG
#include "uart.h"
#endif

#define SSP_NUM			0

uint8_t src_addr[SSP_BUFSIZE]; 
uint8_t dest_addr[SSP_BUFSIZE];

/******************************************************************************
**   Main Function  main()
******************************************************************************/
int main (void)
{
  uint32_t i;

SystemCoreClockUpdate();
  SSP_IOConfig( SSP_NUM );	/* initialize SSP port, share pins with SPI1
						on port2(p2.0-3). */
  SSP_Init( SSP_NUM );			
	
	src_addr[0]=0x96;
	
	while(1)
	{
		SSP_Send( SSP_NUM, (uint8_t *)src_addr, 1);
		for ( i = 0; i < 0x20000; i++ );	/* Delay after write WARNING: careful with 0x20000 value */

	}
  return 0;
}

/******************************************************************************
**                            End Of File
******************************************************************************/

