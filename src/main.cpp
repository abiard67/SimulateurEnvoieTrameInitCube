#include <cstdlib>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>

#include <stdio.h>
#include <string>
#include <chrono>
#include <thread>
#include <list>
#include <iterator>

#include "../defs/serialib.h"

using namespace std;

int main(int argc, char** argv) {


    char tableau [100];
    vector<char> trame(0);
    //char PF;
    //char pf;



    //char trame2[128] = {'~','1',21,'S','T','A','T','U','S','-','B','O','R','D',' ','-','I','N','S','T'};
    trame.push_back(1);//1
    trame.push_back(6);
    trame.push_back('S');//2
    trame.push_back('T');//3
    trame.push_back('A');//4
    trame.push_back('T');//5
    trame.push_back('U');//6
    trame.push_back('S');//7

    //Calcul du checksum
    short chiki = 0;
    char leChecksum[2];

    for (int i = 1; i < trame[1] + 2; i++) {
        chiki = chiki^trame[i];
    }
    sprintf(leChecksum, "%2X", chiki);
    cout << chiki << endl;
    if (leChecksum[0] == 32) leChecksum[0] = '0';
    if (leChecksum[1] == 32) leChecksum[1] = '0';
    char PF = leChecksum[0];
    char pf = leChecksum[1];


    trame.push_back(PF);//8
    trame.push_back(pf);//9
    trame.push_back(255);//10


    serialib * monObjUSB = new serialib; //Déclaration de l'instance
    int test = monObjUSB->Open("/dev/ttyUSB0", 9600); //Ouverture

    cout << "Valeur de Retour de l'accès à la ressource :" << endl;
    cout << test << endl;

    int test2;
    //Ecriture (pour le test)
    cout << "La trame en écriture : " << endl;
    for (int i(0); i < trame.size(); ++i) {
        test2 = monObjUSB->WriteChar(trame[i]);
        cout << trame[i];
    }
    cout << endl;
    cout << "Valeur de Retour de l'écriture :" << endl;
    cout << test2 << endl;

	while (true) {
		int typeRetourEcoute = monObjUSB->ReadString(tableau, 255, 128, 0);
		if (typeRetourEcoute == 0) {
            cout << "Pas de commande." << endl;
		}
		else if (typeRetourEcoute > 1) {
            cout << "Reception de la Commande OK " << endl;

            cout << "Trame Lue : "<< endl;
            for (int i(0); i < typeRetourEcoute; i++) {
                cout << tableau[i];
            }
		}
        else cout << "Erreur " << endl;

	}

    return 0;
}
