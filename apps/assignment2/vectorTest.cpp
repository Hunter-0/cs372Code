#include <iostream>
#include <C:\Users\Honk\cs372.elkins\include\vector.h>
using namespace std;
vector <const char*> t;
int main()
{
    t.put("t", 2);
    t.put("d", 4);
    t.push_back("t");
    t.push_back("d");
    cout<<"Size: "<<t.size()<<endl;
    cout<<"Capacity: "<<t.capacity()<<endl;
    t.traverse();
    return 0;
}
