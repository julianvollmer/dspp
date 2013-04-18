/*
 * main.cpp
 *
 *  Created on: 11.06.2010
 *      Author: jule
 */

#include "main.h"

int main(int argc, char **argv) {
	argc = argc;
	argv = argv;
	vector<Person *> pvec;
	int eingabe = 0;
	do{
		eingabe = menu();
		pvec = verarbeite_eingabe(eingabe, pvec );
	}while (eingabe);
}



vector<Person *> erzeuge_personen(){
	vector <Person *> personenvector;
		for(int i = 0; i < 100; i++){
			int auswahl = liefere_ganze_zufallszahl(0,4);
			Person *p = 0;
			if(auswahl == 0)
				p = new Student;
			else if (auswahl == 1)
				p = new Mitarbeiter;
			else if (auswahl == 2)
				p = new Professor;
			else
				p = new Person;
			personenvector.push_back(p);
		}
		return personenvector;
}



int menu(){
	string menuepunkte[] = {"Eine bestimmte Anzahl von gemischten Studenten, Beschaeftigte und Professoren erzeugen (1 <= n <= 200)",
							"Personen Alphabetisch unsortiert ausgeben",
							"Personen Alphabetisch sortiert ausgeben(Nachname, Vorname, Geburtsdatum)",
							"Personen nach  Geburtsdatum sortiert ausgeben(Geburtsdatum, Nachname, Vorname)",
							"Personen nach  Geburtsjahr sortiert ausgeben(Geburtsjahr, Nachname, Vorname)",
							"Eine bestimmte Anzahl von  Studenten erzeugen (1 <= n <= 200)",
							"Studenten sortiert ausgeben nach der Matrikelnummer",
							"Studenten sortiert ausgeben nach dem Fachbereich (Matrikelnummer)",
							"Studenten sortiert ausgeben nach dem Fachbereich (Nachname, Vorname)",
							"Eine neue zufaellige List erzeugen",
							"Person erfassen"};
	int anz_punkte = sizeof(menuepunkte) / sizeof(menuepunkte[0]);

	int weiter;
		loesche_bildschirm_mit_header();
		cout << " Wie moechten Sie fortfahren" << endl << endl;
		for(int i = 0; i < anz_punkte; i++)
			cout <<"(" << i+1 << ")" << menuepunkte[i] << endl;
		cout << "Druecken Sie 0 zum Beeneden" << endl;
		cin >> weiter;
	return weiter;
}

vector<Person *> verarbeite_eingabe(int weiter, vector<Person *> pvec){
	int auswahl = 0;
	switch(weiter)
	{
		case 1:
			cout << "Bitte geben sie die Anzahl von zu erzeugenden Personen an." << endl;
			cin>>auswahl;
			pvec = erzeuge_personen_gemischt(auswahl, pvec);
		break;
		case 2:
			zeige_gemischte_personen(pvec,0);
		break;
		case 3:
			zeige_gemischte_personen(pvec,cmp_person_nachname_vorname_geb);
		break;
		case 4:
			zeige_gemischte_personen(pvec,cmp_person_geb_nachname_vorname);
		break;
		case 5:
			zeige_gemischte_personen(pvec,cmp_person_gebjahr_nachname_vorname);
	    break;
		case 6:
			cout << "Bitte geben sie die Anzahl von zu erzeugenden Personen an." << endl;
			cin>>auswahl;
			pvec = erzeuge_studies(auswahl,pvec);
	    break;
		case 7:
			zeige_studenten(pvec,vergleiche_student_matrikelnr);
	    break;
		case 8:
			zeige_studenten(pvec,vergleiche_student_fb_matrikelnummer);
	    break;
	    case 9:
	    	zeige_studenten(pvec,vergleiche_student_fb_nachname_vorname);
	    break;
	    case 10:
	    	pvec.erase(pvec.begin(),pvec.end());
	    	pvec = erzeuge_personen_gemischt(liefere_ganze_zufallszahl(1,5), pvec);
	    break;
	    case 11:
	    	cout << "Person erfassen" << endl;
	    	cout << "(1) Person erfassen" << endl;
	    	cout << "(2) Student erfassen" << endl;
	    	cout << "(3) Mitarbeiter erfassen" << endl;
	    	cout << "(4) Professor erfassen" << endl;
	    	cin >> auswahl;
	    	pvec.push_back(erzeuge_person(auswahl));
	    break;
		default: cout << "noch nicht realisiert" << endl;
	}
	return pvec;
}

Person * erzeuge_person(int auswahl){
	Person *p = 0;
	switch(auswahl)
	{
		case 1:
			p = new Person;
			p->erfasse_person();
		break;
		case 2:
			p = new Student;
			p->erfasse_person();
		break;
		case 3:
			p = new Mitarbeiter;
			p->erfasse_person();
		break;
		case 4:
			p = new Professor;
			p->erfasse_person();
		break;
		default: cout << "noch nicht realisiert" << endl;
	}
	return p;
}

void zeige_personen(vector<Person *> p){
	for(unsigned int i = 0; i < p.size(); i++){
		p[i]->zeige_person();
	}
}
vector <Person *> erzeuge_studies(int anz, vector <Person *> pvec){
		for(int i = 0; i < anz; i++){
			Person *p = 0;
			p = new Student();
			pvec.push_back(p);
		}
		return pvec;
}

vector<Person *> erzeuge_personen_gemischt(int anz, vector<Person *> pvec){
		for(int i = 0; i < anz; i++){
			int auswahl = liefere_ganze_zufallszahl(0,3);
			Person *p = 0;
			if(auswahl == 0)
				p = new Student;
			else if (auswahl == 1)
				p = new Mitarbeiter;
			else if (auswahl == 2)
				p = new Professor;
			else
				p = new Person;
			pvec.push_back(p);
		}
		return pvec;
}
void zeige_gemischte_personen(vector <Person *> &vect, bool (*cmp)(Person *p1, Person *p2)) {
     if (cmp != 0) {
          sort(vect.begin(), vect.end(), cmp);
     }
     for (unsigned int i = 0; i < vect.size(); i++) {
          vect[i]->zeige_person();
          cout<< endl << endl;
     }
}
void zeige_studenten(vector <Person *> &vect, bool (*cmp)(Student *p1, Student *p2)) {
    vector<Student *> svec;
    svec = is_student(vect);

	if (cmp != 0) {
          sort(svec.begin(), svec.end(), cmp);
     }
     for (unsigned int i = 0; i < svec.size(); i++) {
    	 svec[i]->zeige_person();
          cout<< endl << endl;
     }
}
vector<Student *> is_student(vector<Person *> pvec){
	vector<Student *> svec;
  for (unsigned int i = 0; i < pvec.size(); i++)
  {
    if (typeid(*pvec[i]) == typeid(Student)){
    	svec.push_back(reinterpret_cast<Student *> (pvec[i]));
    }
  }
  return svec;
}
