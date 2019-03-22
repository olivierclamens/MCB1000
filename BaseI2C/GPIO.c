// Librairie des fonctions permettant l'utilisation de la carte d'extension avec MCB11C4 (KEIL)
// IUT de Cachan - 15/11/2018

#include "LPC11xx.h"                          

// Initialisation des différentes entrées/sorties GPIO
// ---------------------------------------------------
void Initialise_GPIO(void) {

  LPC_SYSCON->SYSAHBCLKCTRL |= (1UL <<  6);     /* enable clock for GPIO      */

  /* configure GPIO2 en sortie */
  LPC_GPIO2->DIR  |=  0xFF;			
  LPC_GPIO2->DATA = 0x00;		// on éteint tout
	
	/* configure P1.4 et P1.5 en entrées */
  LPC_GPIO1->DIR  &=  0xCF;
}

// Lecture BP carte principale
// ---------------------------
char Valeur_BP4(void) {				// renvoie 1 si BP enfonce
	if ( (LPC_GPIO1->DATA & 0x10) == 0x10) return 0;
	else return 1;
}

char Valeur_BP5(void) {				// renvoie 1 si BP enfonce
	if ( (LPC_GPIO1->DATA & 0x20) == 0x20) return 0;
	else return 1;
}

// Allumage d'une LED
//-------------------
void Allumer_1LED(char Num_LED)		// pour allumer 1 LED
{
	switch (Num_LED)
		{
			case 0: LPC_GPIO2->DATA = LPC_GPIO2->DATA | 0x01;
							break;
			case 1: LPC_GPIO2->DATA = LPC_GPIO2->DATA | 0x02;
							break;
			case 2: LPC_GPIO2->DATA = LPC_GPIO2->DATA | 0x04;
							break;
			case 3: LPC_GPIO2->DATA = LPC_GPIO2->DATA | 0x08;
							break;
			case 4: LPC_GPIO2->DATA = LPC_GPIO2->DATA | 0x10;
							break;
			case 5: LPC_GPIO2->DATA = LPC_GPIO2->DATA | 0x20;
							break;
			case 6: LPC_GPIO2->DATA = LPC_GPIO2->DATA | 0x40;
							break;
			case 7: LPC_GPIO2->DATA = LPC_GPIO2->DATA | 0x80;
							break;							
		}
}

// Extinction d'une LED
//---------------------
void Eteindre_1LED(char Num_LED)		// pour eteindre 1 LED
{
	switch (Num_LED)
		{
			case 0: LPC_GPIO2->DATA = LPC_GPIO2->DATA & 0xFE;
							break;
			case 1: LPC_GPIO2->DATA = LPC_GPIO2->DATA & 0xFD;
							break;
			case 2: LPC_GPIO2->DATA = LPC_GPIO2->DATA & 0xFB;
							break;
			case 3: LPC_GPIO2->DATA = LPC_GPIO2->DATA & 0xF7;
							break;
			case 4: LPC_GPIO2->DATA = LPC_GPIO2->DATA & 0xEF;
							break;
			case 5: LPC_GPIO2->DATA = LPC_GPIO2->DATA & 0xDF;
							break;
			case 6: LPC_GPIO2->DATA = LPC_GPIO2->DATA & 0xBF;
							break;
			case 7: LPC_GPIO2->DATA = LPC_GPIO2->DATA & 0x7F;
							break;							
		}
}

// Ecriture d'une valeur sur les sorties GPIO (LEDs)
// -------------------------------------------------
void Ecriture_GPIO(unsigned char Valeur)
{
	LPC_GPIO2->DATA = Valeur;
}
