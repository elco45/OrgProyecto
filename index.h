#ifndef INDEX_H
#define INDEX_H
#include <iostream>
using namespace std;

class Index{
    unsigned long llave;
	int rrn;
public:
    Index(unsigned long,int);
    unsigned long getLlave();
    int getRrn();
};

#endif