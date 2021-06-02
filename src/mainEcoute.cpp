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
serialib * monObjUSB = new serialib; //Déclaration de l'instance
int test = monObjUSB->Open("/dev/ttyUSB0", 9600); //Ouverture

	while (true) {
		int typeRetourEcoute = monObjUSB->ReadString(tableau, 255, 128, 0);
		if (typeRetourEcoute == 0) {
            cout << "Pas de commande." << endl;
		}
		else if (typeRetourEcoute > 1) {
			if (tableau[3]='S'){
            cout << "Reception de la Commande OK " << endl;

            cout << "Trame Lue : "<< endl;
            for (int i(0); i < typeRetourEcoute; i++) {
                cout << tableau[i];
            }
					}
		}
        else cout << "Erreur " << endl;

	}

    return 0;
}
