/**
 *@file zad2.c
 *@brief c fajl koji implementira funkcije
 *@author Danijela Topic
 *@date 15.5.2021.
 *@version 1.0
 */

#include "zad2.h"

uint16_t CheckVowels(char tekst[])
{
	uint8_t vowels[] = "aeiou";
	uint16_t duzina;
	uint16_t samoglasnik = 0;

	for(duzina = 0; tekst[duzina] != '\0'; duzina ++)
		for(uint16_t i = 0; i < duzina; i++)
		{
			for(uint16_t j = 0; j < 5; j++)
			{
				if(tekst[i] == vowels[j])
				{
					samoglasnik++;

				}
			}
		}
	return samoglasnik;
}
