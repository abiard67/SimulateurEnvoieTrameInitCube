#ifndef CHECKSUM_H
#define CHECKSUM_H

#include <stdio.h>
#include <string>
#include <chrono>
#include <thread>
#include <list>
#include <vector>
#include <iterator>

class Checksum {
public:
    Checksum();
    Checksum(const Checksum& orig);
    virtual ~Checksum();
    void calculerChecksum(char & PF, char & pf);
    char tableau[100];
private:

};

#endif /* CHECKSUM_H */

