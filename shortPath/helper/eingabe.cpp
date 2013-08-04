#include "eingabe.h"

/**
 * Erfasst die Enter-Taste.
 **/
void erfasse_enter() {
   std::cout << "Press ENTER to continue... " << flush;
   std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
}

/**
 * Erfasst eine Gleitkommazahl und prueft ob sie gueltig ist.
 * @param min minmaler Wert der eingegeben werden darf
 * @param max maximaler Wert der eingegeben werden darf
 **/
double erfasse_double(double min, double max) {

     //if (max < min)
    	 //vertausche_double(min, max);
     double eingabe = 0.0;
     bool eingabe_ok = false;
     cin.clear();
     cin.unsetf(cin.skipws);
     do {
          cin >> eingabe;
          eingabe_ok = cin.good() && min <= eingabe && eingabe <= max;
          cin.clear();
          cin.ignore(static_cast<streamsize>(LONG_MAX), '\n');
          if (!eingabe_ok) {
               cout << "Bitte eine ganze Zahl eingeben [" << min << " - " << max << "]:  ";
          }
     } while (!eingabe_ok);
     cin.setf(cin.skipws);
     return eingabe;
}


/**
 * Erfasst eine Gleitkommazahl.
 * @return Gibt die eingegebene Gleitkommazahl zurueck.
 */
double erfasse_double() {
	return static_cast<double> (erfasse_double(numeric_limits<double>::min(), std::numeric_limits<double>::max()));
}
/**
 * Erfasst eine Gleitkommazahl und gibt einen Text aus.
 * @param text der uebergeben wurde
 * @return Gibt die eingegebene Gleitkommazahl zurueck.
 */
double erfasse_double(string text) {
	cout << text;
	return erfasse_double();
}

/**
 * Erfasst eine Gleitkommazahl aus dem Bereich min bis max und gibt einen Text aus.
 * @param text Text der ausgegeben werden soll.
 * @param min Minimaler Wert des Bereiches
 * @param max Maximaler Wert des Bereiches
 */
double erfasse_double(string text, double min, double max) {
	cout << text;
	return erfasse_double(min, max);
}

/**
 * Erfasst eine Zahl und prueft ob sie gueltig ist.
 * @param min minmaler Wert der eingegeben werden darf
 * @param max maximaler Wert der eingegeben werden darf
 * @return erfasste Zahl.
 **/
long erfasse_long(long min, long max) {
	//if (max < min)
	//cout<<"vertauschen";
	//vertausche(max, min);
	long eingabe = 0;
	bool eingabe_ok = false;
	cin.clear();
	cin.unsetf(cin.skipws);
	do {
		cin >> eingabe;
		eingabe_ok = cin.good() && min <= eingabe && eingabe <= max;
		cin.clear();
		cin.ignore(static_cast<streamsize> (LONG_MAX), '\n');
		if (!eingabe_ok) {
			cout << "Bitte geben sie eine ganze Zahl ein ";
			cout << "[" << min << " - " << max << " ]";
		}
	} while (!eingabe_ok);
	cin.setf(cin.skipws);
	return eingabe;
}


/**
 * Erfasst eine Zahl aus dem Bereich min und max.
 * @param min Minimaler Wert der eingeben werden darf.
 * @param max Maximaler Wert der eingeben werden darf.
 * @param text Text der mit ausgegeben werden soll.
 * @return Wert der eingeben wurde.
 */
long erfasse_long(long min, long max, string text) {
	cout << text;
	return erfasse_long(min, max);
}

/**
 * Erfasst eine Zahl aus dem Bereich min und max.
 * @param min Minimaler Wert der eingeben werden darf.
 * @param max Maximaler Wert der eingeben werden darf.
 * @return Wert der eingeben wurde.
 */
int erfasse_int(int min, int max) {
	return static_cast<int> (erfasse_long(min, max));
}

/**
 * Erfasst eine Zahl aus dem Bereich min und max und gibt einen Text aus.
 * @param min Minimaler Wert der eingeben werden darf.
 * @param max Maximaler Wert der eingeben werden darf.
 * @param text Text der ausgegeben werden soll.
 * @return Wert der eingeben wurde.
 */
int erfasse_int(int min, int max, string text) {
	cout << text << " [ " << min << " - " << max << " ] :\t";
	return static_cast<int> (erfasse_long(min, max));
}
/**
 * Erfasst eine Zahl.
 * @return Wert der eingeben wurde.
 */
int erfasse_int() {
	return static_cast<int> (erfasse_long(INT_MIN, INT_MAX));
}
/**
 * Erfasst eine Zahl.
 * @param text Text der mit ausgegeben werden soll.
 * @return Wert der eingeben wurde.
 */
int erfasse_int(string text) {
	cout << text;
	return erfasse_int();
}
/**
 * Erfasst eine Zahl aus dem Bereich min und max.
 * @param min Minimaler Wert der eingeben werden darf.
 * @param max Maximaler Wert der eingeben werden darf.
 * @param text Text der mit ausgegeben werden soll.
 * @return Wert der eingeben wurde.
 */
int erfasse_int(string text, int min, int max) {
	cout << text;
	return erfasse_int(min, max);
}
/**
 * Prueft ob ein String eine Zahl ist.
 * @param str String der zu pruefen ist.
 * @return laenge der Zahl.
 */
int is_numeric(char* str)
{
    int len = strlen(str);
    int i = 0;
    int ret = 1;
    int deccnt = 0;
    while(i < len && ret != 0)
    {
        if(str[i] == '.')
        {
            deccnt++;
            if(deccnt > 1)
                ret = 0;
        }
        else
            ret = isdigit(str[i]);
        i++;
    }
    return ret;
}

/**
 * Prueft den Bereich auf Gueltigkeit.
 * @param wert Wert der geprueft werden soll.
 * @param min Minimaler Wert der eingeben werden darf.
 * @param max Maximaler Wert der eingeben werden darf.
 * @return Wert aus dem Bereich.
 */
int pruefe_bereich_int(int wert, int min, int max){
	while(wert < min || wert > max ){
		wert = erfasse_int(min, max, "Der Wert ist ausserhalb des gueltigen Bereichs");
	}
	return wert;
}
