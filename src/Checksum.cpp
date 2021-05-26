#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "../defs/Checksum.h"

Checksum::Checksum() {
}

Checksum::Checksum(const Checksum& orig) {
}

Checksum::~Checksum() {
}

void Checksum::calculerChecksum(char & PF, char & pf) {
    short chiki = 0;
    char leChecksum[2];

    for (int i = 1; i < tableau[2] + 3; i++) {
        chiki = chiki^tableau[i];
    }
    sprintf(leChecksum, "%2X", chiki);
    if (leChecksum[0] == 32) leChecksum[0] = '0';
    if (leChecksum[1] == 32) leChecksum[1] = '0';
    PF = leChecksum[0];
    pf = leChecksum[1];

}

