#include<iostream>
#include<string>
using namespace std;


int initial = 0;
int increment = 0;
int goal = 0;
int n = 0;
int input = 0;


int bears(int bearsNum)
{ 
if (bearsNum == goal){
    return true;
}
else if (n <= 0){
    return false;
}
else if (bearsNum % 2 == 0){ 
    cout<<"You have an even number of "<<bearsNum<<", press 1 to increment or 2 to divide"<<endl;
    cin>>input;
    n--;
    if(input == 1){
        return bears((bearsNum + increment));
    }
    else{
    return bears((bearsNum / 2));
    }
}
else{
    n--;
    return bears((bearsNum + increment));
}

}

int main()
{
cout<<"Enter max number of steps"<<endl;
cin>>n;
cout<<endl<<"Enter increment of bears"<<endl;
cin>>increment;
cout<<endl<<"Enter initial number of bears"<<endl;
cin>>initial;
cout<<endl<<"Enter goal number of bears"<<endl;
cin>>goal;
cout<<endl;
bool result = false;
if (bears(initial) == true)
result = true;

if (result == true){
cout<<"You can reach the goal number of bears"<<endl;
}
else{
cout<<"You can not reach the goal number of bears"<<endl;
}

return 0;
}

