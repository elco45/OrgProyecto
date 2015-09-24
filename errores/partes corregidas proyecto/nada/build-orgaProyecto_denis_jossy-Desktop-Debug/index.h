#ifndef INDEX_H
#define INDEX_H
#include <iostream>
using namespace std;

class Index{
    long llave;
	int rrn;
public:
	Index();
	Index(long);
    Index(long,int);
    ~Index();
    long getLlave();
    int getRrn();
};

#endif