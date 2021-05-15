/**
 * @file zadatak5.c
 * @brief C fajl koji sadrzi definicije funkcija
 * @author Danijela Topic
 * @date 15.5.2021.
 * @version 1.0
 */

#include "zadatak5.h"

/***************************************************************************/
uint16_t CheckPassword (uint8_t lozinka[])
{
	uint8_t password[] = "P@ssw0rd";
	uint16_t duzina1;
	uint16_t pom1 = 0;
	uint16_t m;

	for(duzina1 = 0; lozinka[duzina1] != '\0'; duzina1++)
		for(uint8_t i = 0; i < duzina1; i++)
		{
			if(lozinka[i] == password[i])
			{
				pom1++;

			}
		}
	if(pom1 == duzina1)
	{
		m=1;
	}
	return m;
}

/****************************************************************************/
uint16_t CheckName (uint8_t  ime[])
{
	uint8_t name[] = "MyName";
	uint16_t duzina2;
	uint16_t pom2 = 0;
	uint16_t p;

	for(duzina2 = 0; ime[duzina2] != '\0'; duzina2++)
		for(uint8_t i = 0; i < duzina2; i++)
		{
			if(ime[i] == name[i])
			{
				pom2++;
			}


		}
	if(pom2 == duzina2)
	{
		p = 1;
	}
	return p;

}
/**************************************************************************/
void GeneralCheck(uint16_t m, uint16_t p,uint8_t ime[])

{
	if(m == 1 && p == 1)
	{
		  usartPutString_P(PSTR("Dobrodosla, "));
		  usartPutString(ime);
		  usartPutString_P(PSTR("\r\n"));

	}
	else
	{
		  usartPutString_P(PSTR("Pogresno ime/lozinka!"));
		  usartPutString_P(PSTR("\r\n"));
	}

	}

