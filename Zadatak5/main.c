/**
 * @file	main.c
 * @brief	Provera imena i lozinke
 * @author	Milica Panic
 * @date    05-12-2021
 */

#include "zadatak5.h"


/**
 * Funkcija koja implementira glavnu operaciju
 * @param Nema parametara
 * @return Nema povratnu vrednost
 */
int main()
{
    //ulazi
	uint8_t lozinka[128];
	uint8_t ime[128];
    //pomocne promenljive
	uint16_t p,m;
    //inicijalizacija
	usartInit(9600);

	//glavna petlja
	while(1)
	{

        //PSTR() makro koji smjesta niz karakera u programsku memoriji (stednja)
		usartPutString_P(PSTR("Unesite username: \r\n"));
		while(!usartAvailable())
	    ;
		_delay_ms(50);//kasnjenje

		usartGetString(ime); //prijem imena
		p=CheckName(ime); //provera imena


		usartPutString_P(PSTR("Unesite lozinku: \r\n"));
		while(!usartAvailable())
		;
		_delay_ms(50);//kasnjenje

		usartGetString(lozinka);//prijem lozinke
        m=CheckPassword(lozinka);//provera lozinke

        GeneralCheck(p,m,ime);//provera da li se lozinka i ime `matchuju`


	}//kraj


	return 0;
}

