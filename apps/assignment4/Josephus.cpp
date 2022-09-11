#include <iostream>
#include <list>
using namespace std;


int main(){
    list<int> people;
    int n = 1;
    int m = 0;

    cout<<"Enter number of people"<<endl;
    cin>>n;

    cout<<"Enter number of passes until elimiation"<<endl;
    cin>>m;

    for (int i = 1; i <= n; i++)
    people.push_back(i);
    
    int finished = 0;
    for (int index = 0; finished == 0;)
    {
        for(int i = 1; i < m; i++){
            index++;
            if(index == people.size())
            index = 0;
        }

        list<int>::iterator erase = people.begin();//https://www.geeksforgeeks.org/delete-elements-c-stl-list/
        advance(erase,index);
        people.erase(erase);

        if (index == people.size())
        index = 0;

        if (people.size()<2)
        finished = 1;
    }

    cout<<"Last one left is person "<<people.front()<<endl;

    return 0;
}
