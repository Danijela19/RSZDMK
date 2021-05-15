/*
 *@file zad2.h
 *@brief H fajl koji sadrzi deklaracije funkcija
 *@date 15.05.2021.
 *@author Danijela Topic
 *@version 1.0
 */

#ifndef ZAD2_H_
#define ZAD2_H_

///Standardna biblioteka za arduino
#include <avr/io.h>
///Standardna biblioteka za C
#include <stdio.h>
///Pristup statickoj usart biblioteci
#include "../usart/usart.h"
///Biblioteka koja sadrzi definicije standardnih oznacenih i neoznacenih tipova
#include <stdint.h>
///Biblioteka koja omogucava koristenje funkcije kasnjenja _delay_ms()
#include <util/delay.h>
//Biblioteka koja omogucava pristup podacima u flash memoriji
#include <avr/pgmspace.h>

/**
 * CheckVowels - funkcija koja racuna broj samoglasnika u reci
 * @param ulazni tip je char - unos teksta
 * @return povratna vrednost je uint16_t
 */

uint16_t CheckVowels (char tekst[]);


#endif /* ZAD2_H_ */
