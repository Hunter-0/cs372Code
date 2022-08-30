#include <iostream>
#include "C:\Users\Honk\cs372.elkins\include\bag.h"
using namespace std;
Bag <int> thing;
int main()
{
    thing.insert(3);
    thing.insert(11);
    thing.insert(2);
    thing.pop();
    cout<<"Size of bag: "<<thing.size()<<endl;
    cout<<"Bag count: "<<thing.count(1)<<endl;
    return 0;
}

