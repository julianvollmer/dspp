#ifndef _AUSGABE_H
#define	_AUSGABE_H
#include <cstdlib>
#ifdef __unix__
   #define clrscr() system("clear")
#elif __BORLANDC__ && __MSDOS__
   #include <conio.h>
#elif __WIN32__ || _MSC_VER
   #include <stdlib.h>
   #define clrscr() system("cls")
#else
   #define clrscr() printf("clrscr() - Fehler!\n")
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

void loesche_bildschirm();
void loesche_bildschirm_mit_header();
void header();
typedef ios_base::fmtflags Formattyp;
void setze_schalter(ios_base::fmtflags format);

void schreibe_zahl(long zahl,ios_base::fmtflags format[], int anzahl_formate);
void schreibe_zahl(long zahl, ios_base::fmtflags format);
void schreibe_zahl(long zahl, streamsize feldbreite, ios_base::fmtflags format[], int anzahl_formate);
void schreibe_zahl(long zahl, streamsize feldbreite,  ios_base::fmtflags format);
void schreibe_zahl(long zahl, streamsize feldbreite, char fuellzeichen, ios_base::fmtflags format[],  int anzahl_formate);
void schreibe_zahl(long zahl, streamsize feldbreite, char fuellzeichen, ios_base::fmtflags format);

void schreibe_zahl(long double zahl, ios_base::fmtflags format[],  int anzahl_formate);
void schreibe_zahl(long double zahl, ios_base::fmtflags format);
void schreibe_zahl(long double zahl, streamsize feldbreite, ios_base::fmtflags format);
void schreibe_zahl(long double zahl, streamsize feldbreite,char fuellzeichen,ios_base::fmtflags format[], int anzahl_formate);
void schreibe_zahl(long double zahl, streamsize feldbreite,char fuellzeichen,ios_base::fmtflags format[], int anzahl_formate, streamsize praezision);
void schreibe_zahl(long double zahl, streamsize feldbreite, char fuellzeichen,ios_base::fmtflags format);

void zeige_zahl_von_bis(long double von, long double bis, long double abstand, streamsize praezision);
void zeige_zahl(double wert, streamsize praezision);

void spaltenvorschub (streamsize feldbreite);
void schreibe_text(string text, ios_base::fmtflags format[], int anzahl_formate);
void schreibe_text(string text, streamsize feldbreite, char fuellzeichen, ios_base::fmtflags format);
void schreibe_text(string text, streamsize feldbreite, char fuellzeichen, ios_base::fmtflags format[], int anzahl_formate);
void schreibe_text(string text, streamsize feldbreite, ios_base::fmtflags format[], int anzahl_formate);
void schreibe_text(string text, streamsize feldbreite, char fuellzeichen);
void schreibe_text(string text, streamsize feldbreite);

void schreibe_zahl(double zahl, streamsize feldbreite, char fuellzeichen, ios_base::fmtflags format[], int anzahl_formate);
void schreibe_zahl(int zahl, streamsize feldbreite, char fuellzeichen, ios_base::fmtflags format[], int anzahl_formate);
void wait();
#endif
