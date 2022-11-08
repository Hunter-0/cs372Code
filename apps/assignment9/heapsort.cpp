#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <time.h>
#include <utility>
#include <iterator>
#include <chrono>
using namespace std;

vector<int> vec5;
vector<int> vec10;
vector<int> vec20;
vector<int> vec50;
vector<int> vec100;
vector<int> vec1000;
vector<int> vec10000;
vector<int> vec50000;

void generateVecs(int size, vector <int> vec){
for(int i = 0; i < size; i++){
    srand(time(0));
    vec[i] = (rand() % 100000);
}
}

void sort(vector <int> vec){

        make_heap(vec.begin(), vec.end()); //https://www.geeksforgeeks.org/heap-using-stl-c/
      
    cout << "The heap elements are : ";
    for (int &x : vec) 
       cout << x << " ";
    cout << endl;
      

    sort_heap(vec.begin(), vec.end());
      
     cout << "The heap elements after sorting are : ";
    for (int &x : vec) 
    cout << x << " ";
    
  
}

int main(){
    generateVecs(5, vec5);
    generateVecs(10, vec10);
    generateVecs(20, vec20);
    generateVecs(50, vec50);
    generateVecs(100, vec100);
    generateVecs(1000, vec1000);
    generateVecs(10000, vec10000);
    generateVecs(50000, vec50000);
    auto start = std::chrono::steady_clock::now();
    sort(vec5);
    sort(vec10);
    sort(vec20);
    sort(vec50);
    sort(vec100);
    sort(vec1000);
    sort(vec10000);
    sort(vec50000);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    cout<< "Seconds elapsed: "<<elapsed_seconds.count()<<endl;
    return 0;
}
