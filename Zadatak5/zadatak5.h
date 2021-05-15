/*
 * @file zadatak5.h
 * @brief H fajl koji sadrzi deklaracije funkcija
 * @date 15.05.2021.
 * @author Danijela Topic
 * @version 1.0
 */

#ifndef ZADATAK5_H_
#define ZADATAK5_H_

///Standardna biblioteka za arduino
#include <avr/io.h>
///Standardna biblioteka za C
#include <stdio.h>
///Pristup statickoj usart biblioteci
#include "../usart/usart.h"
///Biblioteka koja sadrzi definicije oznacenih i neoznacenih tipova
#include <stdint.h>
//Biblioteka koja omgucava koriscenje funkcije _delay_ms()
#include <util/delay.h>
//Bibliteka koja omogucava pristup podacima u flash memoriji
#include <avr/pgmspace.h>


/**
 * CheckPassword - Funkcija koja vrsi proveru unete lozinke sa defaultnom
 * @param lozinka - ulaz tipa uint8 - unesena lozinka
 * @return povratna vrednost je tipa uint16_t
 */

uint16_t CheckPassword (uint8_t lozinka[]);

/**
 * CheckName - Funkcija koja vrsi proveru unetog korisnickog imena
 * @param ime - ulaz tipa uint8_t - uneseno ime
 * @return Povratna vrednost je tipa uint16_t
 */

uint16_t CheckName (uint8_t ime[]);

/**
 * GeneralCheck - Funkcija koja vrsi provjeru zajednickog podudaranja lozinke i imena i vrsi odgovarajuci ispis
 * @param m - ulaz tipa int - pomocna promenljiva
 * @param p - ulaz tipa int - pomocna promenljiva
 * @param ime - ulaz tipa char - uneseno ime
 * @return Nema povratne vrednosti
 */
void GeneralCheck(uint16_t m, uint16_t p,uint8_t ime[]);


#endif /* ZADATAK5_H_ */
