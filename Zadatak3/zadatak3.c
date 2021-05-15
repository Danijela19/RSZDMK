/**
 * @file	main.c
 * @brief	Aplikacija koja vrsi racunanje izraza
 * @author	Milica Panic
 * @date    05-12-2021
 * @version 1.0
 */
///Standardna arduino biblioteka
#include <avr/io.h>
///Biblioteka koja omogucava koriscenje funkcije kasnjenja _delay_ms()
#include <util/delay.h>
///Bibliteka koj aomogucava pristup podacima u flash memoriji
#include <avr/pgmspace.h>
///Biblioteka koja sadrzi definicije standardnih oznacenih i neoznacenih tipova
#include <stdint.h>
///Standardna C biblioteka
#include <stdio.h>
///Pristup usart statickoj biblioteci
#include "../usart/usart.h"



/**
 * Operacija - Funkcija koja na osnovu unesenog operatora odredjuje i vrsi operaciju
 * @param op - ulaz tipa uint8_t - operator
 * @param num1 - ulaz tipa uin16_t - prvi ceo broj izraza
 * @param num2 - ulaz tipa uin16_t - drugi ceo broj izraza
 * @return - Povratna vrijednost je tipa uin16_t - rezultat operacije
 */
uint16_t Operacija(uint8_t op, uint16_t num1, uint16_t num2)
{

	uint16_t res = 0;

	switch(op)
	{
	case '-':
		res = num1 - num2;
		break;
	case '+':
		res = num1 + num2;
		break;
	case '*':
		res = num1 * num2;
		break;
	case '/':
		res = num1 / num2;
		break;
	default:
		res = -1;
	}
	return res;
}

/**
 * main - Funkcija koja implementira glavnu operaciju
 * @param Nema parametara
 * @return Nema povratnu vrijednost
 */

int main()

{
	//inicijalizacija
	usartInit(9600);

	//ulaz
	uint8_t tekst[64];

	uint16_t num1,num2;
	uint16_t op;
	uint8_t str[64];


	//glavna petlja
	while(1)
	{
		usartPutString_P(PSTR("Unesite izraz: \r\n"));
		while(!usartAvailable())
		;
		_delay_ms(50);

		num1 = usartParseInt();//prijem prvog celog broja
		op = usartGetChar();//prijem operatora
		num2 = usartParseInt();//prijem drugog celog broja

		sprintf(str, "%d\0", Operacija(op, num1 ,num2));
		usartPutString(str);
		usartPutString_P(PSTR("\r\n"));


	}
	return 0;

}
