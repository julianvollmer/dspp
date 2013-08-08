#include "random.h"

int initialize_zufall = 0;

/**
 * Initialisert den Zufallsgenerator.
 **/
void initialisiere_zufallsgenerator(void) {
	if (initialize_zufall == 0) {
		initialize_zufall = 1;
		srand((unsigned)time(NULL));
	}
}

/**
 * Liefert eine zufällig gewählte ganze Zahl aus dem Bereich von 0 bis (max - 1) zurück.
 * @param max 		Legt den Bereich fest, aus dem die ganze Zahl gewählt wird.
 * @return			Eine zufällig gewählte ganze Zahl aus dem Bereich 0 bis (max - 1).
 *					Achtung: Wenn max <= 0 oder max > RAND_MAX ist, wird -1 geliefert.
 **/
int zufallszahl_int(int max) {
	initialisiere_zufallsgenerator();
	bool input_ok = (0 < max) && (max <= RAND_MAX);
	return input_ok ? rand() % max : -1;
}

/**
 * Liefert eine zufällig gewählte ganze Zahl aus dem Bereich
 * von min bis max (einschliesslich) zurück.
 * @param min 		Legt die untere Grenze fest, aus dem die ganze Zahl gewählt wird.
 * @param max 		Legt die obere Grenze fest, aus dem die ganze Zahl gewählt wird.
 * @return			Eine zufällig gewählte ganze Zahl aus dem Bereich min bis max.
 **/
int liefere_ganze_zufallszahl(int min, int max) {
	if (min > max) {
		int ablage = min;
		min = max;
		max = ablage;
	}
	return zufallszahl_int(max - min + 1) + min;
}
/**
 * Gibt eine Zufallszahl im als double Wert zurueck.
 * @return Zufallszahl
 */
double zufallszahl_dbl() {
	initialisiere_zufallsgenerator();
	return rand() / (double(RAND_MAX)+1);
}

/**
 * Gibt eine Zufallszahl im als double Wert zurueck, die groeßer ist als der übergebene Wert.
 * @param  max minimale Zufallszahl
 * @return     Zufallszahl
 */
double zufallszahl_dbl_max(double max) {
    return zufallszahl_dbl() * max;
}
/**
 * Gibt eine Zufallszahl aus dem Bereich min bis max.
 * @return Zufallszahl aus dem Bereich min bis max
 */
double zufallszahl_dbl_min_max(double min, double max) {
    if (min > max) {
        return zufallszahl_dbl() * (min - max) + max;
    } else {
        return zufallszahl_dbl() * (max - min) + min;
    }
}
