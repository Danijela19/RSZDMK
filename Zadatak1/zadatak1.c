/**
 * @file main.c
 * @brief Aplikacija koja vrsi kapitalizaciju teksta
 * @author Danijela Topic
 * @data 15.5.2021.
 */

///Biblioteka standardna za arduino
#include <avr/io.h>
///Biblioteka standardna za C
#include <stdio.h>
///Pristup usart statickoj biblioteci
#include "../usart/usart.h"
///Biblioteka za pristup podacima u flash memoriji
#include <avr/pgmspace.h>
///Biblioteka koja omogucava koristenje funkcije kasnjenja _delay_ms()
#include <util/delay.h>
///Biblioteka koja sadrzi definicje standardnih oznacenih i neoznacenih tipova
#include <stdint.h>

/**
 * Kapitalizacija - Funkcija koja vrsi pretvaranje malih slovau velika slova teksta
 * @param tekst  - uint8_t je tip ulaza - tekst koji se unosi
 * @return - Nema povratnu vrednost
 */

void Kapitalizacija (uint8_t tekst[])
{
	uint16_t duzina;

	for(duzina = 0; tekst[duzina] != '\0'; duzina++)
	{
		for(uint8_t i = 0; i < duzina; i++)
		{

			if(tekst[i] >= 'a' && tekst[i] <= 'z')
			{
				tekst[i] += 'A' - 'a';
			}
		}
	}

	usartPutString_P(PSTR(" Kapitalizovan tekst je: "));
	usartPutString(tekst);
	usartPutString_P(PSTR("\r\n"));

}

/**
 * Main - glavna funkcija koja obavlja implementiranje osnovnih fukncija
 * @param Nema parametara
 * @return Nema povratne vrednosti
 */

int main()
{
	usartInit(9600);
	uint8_t tekst[64];

	while(1)
	{
		usartPutString_P(PSTR("Unesite tekst: \r\n"));
		while(!usartAvailable())
			;
		_delay_ms(70);

		usartGetString(tekst);

		Kapitalizacija(tekst);
	}
}




