/*
 * Anschrift.cpp
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */

#include "Anschrift.h"

const char* def_strassenname[] = {"Aachener Stra�e", "Am Feldweg", "Am Waldrand", "Abbestra�e", "Am Festspielhaus", "Am Waldschl��chen", "Achtbeeteweg", "Am Fichtepark", "Am Wasserturm", "Ackermannstra�e", "Am Finkenschlag", "Am Wasserwerk", "Adalbert-Stifter-Weg", "Am Fl�ssertgraben", "Am Wehr", "Adlergasse", "Am Forsthaus", "Am Weinberg", "Adolfstra�e", "Am Friedenshang", "Am Wei�en Adler", "Agnes-Smedley-Stra�e", "Am Friedhof", "Am Wei�eritzm�hlgraben", "Agnesh�he", "Am Fuchsbau", "Am Wei�iger Bach", "Ahlbecker Stra�e", "Am Fuchsberg", "Am Werk", "Ahornstra�e", "Am G�nsefu�", "Am Wetterbusch", "Ahornweg", "Am G�rtchen", "Am Wiesenrand", "Akademiestra�e", "Am Galgenberg", "Am Wiesental", "Akazienweg", "Am Gassenberg", "Am Winkel", "Alaunplatz", "Am Geberbach", "Am Winkelsprung", "Alaunstra�e", "Am Ginsterbusch", "Am Zaukenfeld", "Albert-Fromme-Weg", "Am Goldenen Stiefel", "Am Ziegenberg", "Albert-Hensel-Stra�e", "Am Gorbitzbach", "Am Zollhaus", "Albert-Richter-Stra�e", "Am Graben", "Am Zschoner Berg", "Albert-Schweitzer-Stra�e", "Am Gr�nen Grund", "Am Zschonergrund", "Albert-Venus-Weg", "Am Gr�nen Zipfel", "Am Zuckerhut", "Albert-Wolf-Platz", "Am Gr�ng�rtel", "Am Zwingerteich", "Albertbr�cke", "Am Grund", "Amalie-Dietrich-Platz", "Albertplatz", "Am G�ckelsberg", "Amaryllenweg", "Albertstra�e", "Am Gutsberg", "Ammonstra�e", "Albrechtsh�he", "Am Hahnweg", "Amselgrund", "Alemannenstra�e", "Am Hang", "Amselsteg", "Alexander-Herzen-Stra�e", "Am Hauptbahnhof", "Amselweg", "Alexander-Puschkin-Platz", "Am Hausberg", "Amtsstra�e", "Alexanderstra�e", "Am Hegereiter", "An den Alten G�rtnereien", "Alfred-Althus-Stra�e", "Am Heidehof", "An den B�chen", "Alfred-Darre-Weg", "Am Heiderand", "An den Birken", "Alfred-Schmieder-Stra�e", "Am Helfenberger Park", "An den Bruchwiesen", "Alfred-Schrapel-Stra�e", "Am Hellerhof", "An den Ellerwiesen", "Alfred-Thiele-Stra�e", "Am Hellerrand", "An den G�rten", "Alnpeckstra�e", "Am Hermsberg", "An den Hufen", "Alojs-Andricki-Stra�e", "Am Hochwald", "An den Jagdwegen", "Alpenstra�e", "Am Hofefeld", "An den Kalk�fen", "Alsenstra�e", "Am Hofegarten", "An den Kiefern", "Alt-Leuteritzer Ring", "Am Hofgut", "An den Kuhbergen", "Altbriesnitz", "Am Hohen Stein", "An den Ruschewiesen", "Altburgst�dtel", "Am Hopfenfeld", "An den Teichen", "Altcosch�tz", "Am Hornsberg", "An den Teichwiesen", "Altcotta", "Am H�gel", "An den Winkelwiesen", "Altdobritz", "Am Hutberg", "An der Aue", "Altd�lzschen", "Am Ilschengraben", "An der Autobahn", "Alte Dorfstra�e", "Am J�gerpark", "An der Bartlake", "Alte Dresdner Stra�e", "Am Kaditzer T�nnicht", "An der Bergkuppe", "Alte Kirschplantage", "Am Kammerholz", "An der Berglehne", "Alte Landstra�e", "Am Keppschlo�", "An der B�schung", "Alte Mei�ner Landstra�e", "Am Kesselgrund", "An der Christuskirche", "Alte Moritzburger Stra�e", "Am Kirchberg", "An der Dreik�nigskirche", "Alte Poststra�e", "Am Kirschberg", "An der D�rren Heide", "Alte Stra�e", "Am Kirschfeld", "An der Eisenbahn", "Altenberger Platz", "Am Kirschplan", "An der Elbaue", "Altenberger Stra�e", "Am Klosterhof", "An der Flutrinne", "Altenzeller Stra�e", "Am Knie", "An der F�rsterei", "Alter Bahndamm", "Am Kohlenplatz", "An der Frauenkirche", "Alter Eichbuscher Weg", "Am Kr�henh�gel", "An der Heide", "Alter Jagdweg", "Am Kronenh�gel", "An der Heilandskirche", "Alter Postweg", "Am Kurhaus B�hlau", "An der Herzogin Garten", "Alter Rossendorfer Weg", "Am Lagerplatz", "An der H�he", "Altfrankener Dorfstra�e", "Am Landgraben", "An der Hufe", "Altfrankener H�he", "Am Landigt", "An der Huhle", "Altfrankener Stra�e", "Am Lehmberg", "An der Jungen Heide", "Altfriedersdorf", "Am Lehmhaus", "An der Kirschwiese", "Altgomlitz", "Am Lerchenberg", "An der Kreuzkirche", "Altgompitz", "Am Leutewitzer Park", "An der Kucksche", "Altgorbitz", "Am Lindenberg", "An der K�mmelschenke", "Altgorbitzer Ring", "Am Lockwitzbach", "An der Lehmkuhle", "Altgostritz", "Am Lucknerpark", "An der Linde", "Altgruna", "Am Lugaer Graben", "An der Mauer", "Altkaditz", "Am Marienbad", "An der Niederm�hle", "Altkaitz", "Am Martiniweg", "An der Niederung", "Altkleinzschachwitz", "Am Mieschenhang", "An der Nordsiedlung", "Altklotzsche", "Am Mittelt�nnicht", "An der Oberm�hle", "Altlaubegast", "Am Mittelwald", "An der Obstplantage", "Altleuben", "Am M�hlberg", "An der �lm�hle", "Altleubnitz", "Am Nilgenborn", "An der Pikardie", "Altleutewitz", "Am Nussbaum", "An der Post", "Altlockwitz", "Am Olter", "An der Prie�nitz", "Altl�btau", "Am Osterberg", "An der Prie�nitzaue", "Altmarkt", "Am Park", "An der Reitanlage", "Altmickten", "Am Pfaffenberg", "An der Rennbahn", "Altmobschatz", "Am Pfarrlehn", "An der Rysselkuppe", "Altmockritz", "Am Pfeiferberg", "An der Sch�ferei", "Altnau�litz", "Am Pfiff", "An der Schanze", "Altnickern", "Am Pillnitzberg", "An der Schleife", "Altnossener Stra�e", "Am Pilz", "An der Schleifscheibe", "Altomsewitz", "Am Plan", "An der Schlo�g�rtnerei", "Altonaer Stra�e", "Am Pre�grund", "An der Schmiede", "Altpestitz", "Am Promigberg", "An der Schule", "Altpieschen", "Am Putjatinpark", "An der Siedlung", "Altplauen", "Am Queckbrunnen", "An der Sonnenlehne", "Altpodemus", "Am Querfeld", "An der S�dlehne", "Altr�cknitz", "Am Querweg", "An der Telle", "Altreick", "Am Rainchen", "An der Wassersch�pfe", "Altrochwitz", "Am Rasen", "An der Winkelwiese", "Altro�thal", "Am Rathaus", "An der Wostra", "Altseidnitz", "Am Rausch", "Andersenstra�e", "Alts�brigen", "Am Rittergut", "Andreas-Hofer-Stra�e", "Altsporbitz", "Am Ro�thaler Bach", "Andreas-Schubert-Stra�e", "Altstetzsch", "Am S�gewerk", "Anemonenweg", "Altstrehlen", "Am Sand", "Angelikastra�e", "Altstriesen", "Am Sandberg", "Angelsteg", "Alttolkewitz", "Am Sch�nkenberg", "Ankerstra�e", "Alttorna", "Am Schie�haus", "Anna-Angermann-Stra�e", "Alttrachau", "Am Schillergarten", "Annaberger Stra�e", "Alt�bigau", "Am Schleiferberg", "Anne-Frank-Stra�e", "Altwachwitz", "Am Schlo�", "Annenstra�e", "Altweixdorf", "Am Schreiberbach", "Anton-Graff-Stra�e", "Altwilschdorf", "Am Sch�tzenfelde", "Anton-G�nther-Weg", "Altwilschdorfer Weg", "Am Schulfeld", "Anton-Weck-Stra�e", "Altw�lfnitz", "Am Schulholz", "Antonin-Dvorak-Stra�e", "Am Acker", "Am Schullwitzbach", "Antonsplatz", "Am Alten Bahndamm", "Am Schwarzen Tor", "Antonstra�e", "Am Alten Elbarm", "Am See", "Anzengruberweg", "Am Altfrankener Park", "Am Seegraben", "Archivstra�e", "Am Anfang", "Am Seeh�gel", "Arkonastra�e", "Am Anger", "Am Seifzerbach", "Arltstra�e", "Am Bahndamm", "Am Sonnenhang", "Arndtstra�e", "Am Bauernbusch", "Am Spitzberg", "Arno-Holz-Allee", "Am Berg", "Am Sportplatz", "Arno-Lade-Stra�e", "Am Bergblick", "Am Spritzenberg", "Arno-Schellenberg-Stra�e", "Am Beutlerpark", "Am Stadtrand", "Arnoldstra�e", "Am Biedersberg", "Am Staffelstein", "Arthur-Schlo�mann-Weg", "Am Birkenw�ldchen", "Am Stausee", "Arthur-Weineck-Stra�e", "Am Brauhaus", "Am Steinacker", "Aspichring", "Am Briesnitzer Hang", "Am Steinberg", "Asternweg", "Am Br�chigt", "Am Steinborn", "Auenstra�e", "Am Brunnen", "Am Steinbruch", "Auenweg", "Am Burgberg", "Am Steingarten", "Auf dem Eigen", "Am Burgwall", "Am Steinh�bel", "Auf dem Meisenberg", "Am Buscherberg", "Am Steinigt", "Auf dem Pl�ner", "Am Dachsberg", "Am Stieglitzgrund", "Auf dem Sand", "Am Dahlienheim", "Am T�lchen", "Auf der H�he", "Am D�lzschgraben", "Am Talkenberg", "Auf der Scheibe", "Am Dorfende", "Am Teich", "Auf der Scholle", "Am Dorffrieden", "Am Torbogen", "Augsburger Stra�e", "Am Dorfplatz", "Am Torfmoor", "August-Bebel-Stra�e", "Am Dorfteich", "Am Trachauer Bahnhof", "August-B�ckstiegel-Stra�e", "Am Dorngraben", "Am Triebenberg", "August-R�ckel-Stra�e", "Am Eigenheimweg", "Am Trobischberg", "August-Wagner-Stra�e", "Am Eiswurmlager", "Am Trutzsch", "Auguste-Lazar-Stra�e", "Am Elbblick", "Am Tummelsgrund", "Augustinstra�e", "Am Elbtalweg", "Am Urnenfeld", "Augustusbergstra�e", "Am Ende", "Am Viertelacker", "Augustusbr�cke", "Am Erlengrund", "Am Vorwerksfeld", "Augustusstra�e", "Am Erlichberg", "Am Wachwitzer H�henpark", "Augustusweg", "Am Erlicht", "Am W�ldchen", "Aussiger Stra�e", "Am F�hrhaus", "Am Wald", "Azaleenweg", "Am Feld", "Am Waldblick", "", "Am Feldgeh�lz", "Am Walde"};
const int anz_strassenname = sizeof(def_strassenname) / sizeof(def_strassenname[0]);

/**
 * Erzeugt eine zufaellige Anschrift
 */
Anschrift::Anschrift(){
	strasse = def_strassenname[liefere_ganze_zufallszahl(0,(anz_strassenname - 1))];
	hausnummer = liefere_ganze_zufallszahl(0,100);
}
/**
 * @return gibt eine Strasse zurueck
 */
string Anschrift::get_strasse(){
	return this->strasse;
}

/**
 * @return gibt eine Hausnummer zurueck
 */
int Anschrift::get_hausnummer(){
	return this->hausnummer;
}

/**
 * @return gibt einen Ort zurueck
 */
Ort Anschrift::get_ort(){
	return this->ort;
}

/**
 * Erfasst eine Strasse.
 */
void Anschrift::erfasse_strasse(){
	cout << "Bitte geben Sie die Strasse ein : ";
	cin.clear() ;
	fflush(stdin);
	getline(cin,strasse);
}
/**
 * Erfasst eine Hausnummer.
 */

void Anschrift::erfasse_hausnummer(){
	hausnummer = erfasse_int(1,9999,"Bitte geben Sie die Hausnummer ein : ");
}
/**
 * Erfasst eine komplette Anschrift.
 */
void Anschrift::erfasse_anschrift(){
	erfasse_strasse();
	erfasse_hausnummer();
	ort.erfasse_ort();
}
