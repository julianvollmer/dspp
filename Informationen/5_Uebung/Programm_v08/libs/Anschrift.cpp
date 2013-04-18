/*
 * Anschrift.cpp
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */

#include "Anschrift.h"

const char* def_strassenname[] = {"Aachener Straße", "Am Feldweg", "Am Waldrand", "Abbestraße", "Am Festspielhaus", "Am Waldschlößchen", "Achtbeeteweg", "Am Fichtepark", "Am Wasserturm", "Ackermannstraße", "Am Finkenschlag", "Am Wasserwerk", "Adalbert-Stifter-Weg", "Am Flössertgraben", "Am Wehr", "Adlergasse", "Am Forsthaus", "Am Weinberg", "Adolfstraße", "Am Friedenshang", "Am Weißen Adler", "Agnes-Smedley-Straße", "Am Friedhof", "Am Weißeritzmühlgraben", "Agneshöhe", "Am Fuchsbau", "Am Weißiger Bach", "Ahlbecker Straße", "Am Fuchsberg", "Am Werk", "Ahornstraße", "Am Gänsefuß", "Am Wetterbusch", "Ahornweg", "Am Gärtchen", "Am Wiesenrand", "Akademiestraße", "Am Galgenberg", "Am Wiesental", "Akazienweg", "Am Gassenberg", "Am Winkel", "Alaunplatz", "Am Geberbach", "Am Winkelsprung", "Alaunstraße", "Am Ginsterbusch", "Am Zaukenfeld", "Albert-Fromme-Weg", "Am Goldenen Stiefel", "Am Ziegenberg", "Albert-Hensel-Straße", "Am Gorbitzbach", "Am Zollhaus", "Albert-Richter-Straße", "Am Graben", "Am Zschoner Berg", "Albert-Schweitzer-Straße", "Am Grünen Grund", "Am Zschonergrund", "Albert-Venus-Weg", "Am Grünen Zipfel", "Am Zuckerhut", "Albert-Wolf-Platz", "Am Grüngürtel", "Am Zwingerteich", "Albertbrücke", "Am Grund", "Amalie-Dietrich-Platz", "Albertplatz", "Am Gückelsberg", "Amaryllenweg", "Albertstraße", "Am Gutsberg", "Ammonstraße", "Albrechtshöhe", "Am Hahnweg", "Amselgrund", "Alemannenstraße", "Am Hang", "Amselsteg", "Alexander-Herzen-Straße", "Am Hauptbahnhof", "Amselweg", "Alexander-Puschkin-Platz", "Am Hausberg", "Amtsstraße", "Alexanderstraße", "Am Hegereiter", "An den Alten Gärtnereien", "Alfred-Althus-Straße", "Am Heidehof", "An den Bächen", "Alfred-Darre-Weg", "Am Heiderand", "An den Birken", "Alfred-Schmieder-Straße", "Am Helfenberger Park", "An den Bruchwiesen", "Alfred-Schrapel-Straße", "Am Hellerhof", "An den Ellerwiesen", "Alfred-Thiele-Straße", "Am Hellerrand", "An den Gärten", "Alnpeckstraße", "Am Hermsberg", "An den Hufen", "Alojs-Andricki-Straße", "Am Hochwald", "An den Jagdwegen", "Alpenstraße", "Am Hofefeld", "An den Kalköfen", "Alsenstraße", "Am Hofegarten", "An den Kiefern", "Alt-Leuteritzer Ring", "Am Hofgut", "An den Kuhbergen", "Altbriesnitz", "Am Hohen Stein", "An den Ruschewiesen", "Altburgstädtel", "Am Hopfenfeld", "An den Teichen", "Altcoschütz", "Am Hornsberg", "An den Teichwiesen", "Altcotta", "Am Hügel", "An den Winkelwiesen", "Altdobritz", "Am Hutberg", "An der Aue", "Altdölzschen", "Am Ilschengraben", "An der Autobahn", "Alte Dorfstraße", "Am Jägerpark", "An der Bartlake", "Alte Dresdner Straße", "Am Kaditzer Tännicht", "An der Bergkuppe", "Alte Kirschplantage", "Am Kammerholz", "An der Berglehne", "Alte Landstraße", "Am Keppschloß", "An der Böschung", "Alte Meißner Landstraße", "Am Kesselgrund", "An der Christuskirche", "Alte Moritzburger Straße", "Am Kirchberg", "An der Dreikönigskirche", "Alte Poststraße", "Am Kirschberg", "An der Dürren Heide", "Alte Straße", "Am Kirschfeld", "An der Eisenbahn", "Altenberger Platz", "Am Kirschplan", "An der Elbaue", "Altenberger Straße", "Am Klosterhof", "An der Flutrinne", "Altenzeller Straße", "Am Knie", "An der Försterei", "Alter Bahndamm", "Am Kohlenplatz", "An der Frauenkirche", "Alter Eichbuscher Weg", "Am Krähenhügel", "An der Heide", "Alter Jagdweg", "Am Kronenhügel", "An der Heilandskirche", "Alter Postweg", "Am Kurhaus Bühlau", "An der Herzogin Garten", "Alter Rossendorfer Weg", "Am Lagerplatz", "An der Höhe", "Altfrankener Dorfstraße", "Am Landgraben", "An der Hufe", "Altfrankener Höhe", "Am Landigt", "An der Huhle", "Altfrankener Straße", "Am Lehmberg", "An der Jungen Heide", "Altfriedersdorf", "Am Lehmhaus", "An der Kirschwiese", "Altgomlitz", "Am Lerchenberg", "An der Kreuzkirche", "Altgompitz", "Am Leutewitzer Park", "An der Kucksche", "Altgorbitz", "Am Lindenberg", "An der Kümmelschenke", "Altgorbitzer Ring", "Am Lockwitzbach", "An der Lehmkuhle", "Altgostritz", "Am Lucknerpark", "An der Linde", "Altgruna", "Am Lugaer Graben", "An der Mauer", "Altkaditz", "Am Marienbad", "An der Niedermühle", "Altkaitz", "Am Martiniweg", "An der Niederung", "Altkleinzschachwitz", "Am Mieschenhang", "An der Nordsiedlung", "Altklotzsche", "Am Mitteltännicht", "An der Obermühle", "Altlaubegast", "Am Mittelwald", "An der Obstplantage", "Altleuben", "Am Mühlberg", "An der Ölmühle", "Altleubnitz", "Am Nilgenborn", "An der Pikardie", "Altleutewitz", "Am Nussbaum", "An der Post", "Altlockwitz", "Am Olter", "An der Prießnitz", "Altlöbtau", "Am Osterberg", "An der Prießnitzaue", "Altmarkt", "Am Park", "An der Reitanlage", "Altmickten", "Am Pfaffenberg", "An der Rennbahn", "Altmobschatz", "Am Pfarrlehn", "An der Rysselkuppe", "Altmockritz", "Am Pfeiferberg", "An der Schäferei", "Altnaußlitz", "Am Pfiff", "An der Schanze", "Altnickern", "Am Pillnitzberg", "An der Schleife", "Altnossener Straße", "Am Pilz", "An der Schleifscheibe", "Altomsewitz", "Am Plan", "An der Schloßgärtnerei", "Altonaer Straße", "Am Preßgrund", "An der Schmiede", "Altpestitz", "Am Promigberg", "An der Schule", "Altpieschen", "Am Putjatinpark", "An der Siedlung", "Altplauen", "Am Queckbrunnen", "An der Sonnenlehne", "Altpodemus", "Am Querfeld", "An der Südlehne", "Alträcknitz", "Am Querweg", "An der Telle", "Altreick", "Am Rainchen", "An der Wasserschöpfe", "Altrochwitz", "Am Rasen", "An der Winkelwiese", "Altroßthal", "Am Rathaus", "An der Wostra", "Altseidnitz", "Am Rausch", "Andersenstraße", "Altsöbrigen", "Am Rittergut", "Andreas-Hofer-Straße", "Altsporbitz", "Am Roßthaler Bach", "Andreas-Schubert-Straße", "Altstetzsch", "Am Sägewerk", "Anemonenweg", "Altstrehlen", "Am Sand", "Angelikastraße", "Altstriesen", "Am Sandberg", "Angelsteg", "Alttolkewitz", "Am Schänkenberg", "Ankerstraße", "Alttorna", "Am Schießhaus", "Anna-Angermann-Straße", "Alttrachau", "Am Schillergarten", "Annaberger Straße", "Altübigau", "Am Schleiferberg", "Anne-Frank-Straße", "Altwachwitz", "Am Schloß", "Annenstraße", "Altweixdorf", "Am Schreiberbach", "Anton-Graff-Straße", "Altwilschdorf", "Am Schützenfelde", "Anton-Günther-Weg", "Altwilschdorfer Weg", "Am Schulfeld", "Anton-Weck-Straße", "Altwölfnitz", "Am Schulholz", "Antonin-Dvorak-Straße", "Am Acker", "Am Schullwitzbach", "Antonsplatz", "Am Alten Bahndamm", "Am Schwarzen Tor", "Antonstraße", "Am Alten Elbarm", "Am See", "Anzengruberweg", "Am Altfrankener Park", "Am Seegraben", "Archivstraße", "Am Anfang", "Am Seehügel", "Arkonastraße", "Am Anger", "Am Seifzerbach", "Arltstraße", "Am Bahndamm", "Am Sonnenhang", "Arndtstraße", "Am Bauernbusch", "Am Spitzberg", "Arno-Holz-Allee", "Am Berg", "Am Sportplatz", "Arno-Lade-Straße", "Am Bergblick", "Am Spritzenberg", "Arno-Schellenberg-Straße", "Am Beutlerpark", "Am Stadtrand", "Arnoldstraße", "Am Biedersberg", "Am Staffelstein", "Arthur-Schloßmann-Weg", "Am Birkenwäldchen", "Am Stausee", "Arthur-Weineck-Straße", "Am Brauhaus", "Am Steinacker", "Aspichring", "Am Briesnitzer Hang", "Am Steinberg", "Asternweg", "Am Brüchigt", "Am Steinborn", "Auenstraße", "Am Brunnen", "Am Steinbruch", "Auenweg", "Am Burgberg", "Am Steingarten", "Auf dem Eigen", "Am Burgwall", "Am Steinhübel", "Auf dem Meisenberg", "Am Buscherberg", "Am Steinigt", "Auf dem Pläner", "Am Dachsberg", "Am Stieglitzgrund", "Auf dem Sand", "Am Dahlienheim", "Am Tälchen", "Auf der Höhe", "Am Dölzschgraben", "Am Talkenberg", "Auf der Scheibe", "Am Dorfende", "Am Teich", "Auf der Scholle", "Am Dorffrieden", "Am Torbogen", "Augsburger Straße", "Am Dorfplatz", "Am Torfmoor", "August-Bebel-Straße", "Am Dorfteich", "Am Trachauer Bahnhof", "August-Böckstiegel-Straße", "Am Dorngraben", "Am Triebenberg", "August-Röckel-Straße", "Am Eigenheimweg", "Am Trobischberg", "August-Wagner-Straße", "Am Eiswurmlager", "Am Trutzsch", "Auguste-Lazar-Straße", "Am Elbblick", "Am Tummelsgrund", "Augustinstraße", "Am Elbtalweg", "Am Urnenfeld", "Augustusbergstraße", "Am Ende", "Am Viertelacker", "Augustusbrücke", "Am Erlengrund", "Am Vorwerksfeld", "Augustusstraße", "Am Erlichberg", "Am Wachwitzer Höhenpark", "Augustusweg", "Am Erlicht", "Am Wäldchen", "Aussiger Straße", "Am Fährhaus", "Am Wald", "Azaleenweg", "Am Feld", "Am Waldblick", "", "Am Feldgehölz", "Am Walde"};
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
