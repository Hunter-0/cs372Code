#include <iostream>
#include <vector>
#include <chrono>
#include <C:\Users\Honk\cs372.elkins\include\newestVec.h>
using namespace std;

class vectorTest {
    public:
        vectorTest(){
            stl = vector<int>();
            vec = vectorFake<int>();
        }

        double stlTime(int startingCap, int newElements){
            fill(&stl, startingCap);
            auto start = std::chrono::steady_clock::now();
            for (int i = 0; i < newElements; i++){
                stl.push_back(i);
            }
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end-start; 
            return elapsed_seconds.count();
        }


        double vecTime(int startingCap, int newElements){
            fill(&vec, startingCap);
            auto start = std::chrono::steady_clock::now();
            for (int i = 0; i < newElements; i++){
                vec.push_back(i);
            }
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end-start; 
            return elapsed_seconds.count();  
        }

    private:
        template <typename T>
        void fill(T thing, int cap){
            for (int i = 0; i < cap; i++){
                thing->push_back(i);
            } 
        }
        vector<int> stl;
        vectorFake<int> vec;

};


int main(){
    vectorTest test;

    int startingCap = 10;
    int testNumber = 100;

    cout<< "Seconds elapsed for stl vector: "   <<test.stlTime(startingCap, testNumber)<<endl;
    cout<< "Seconds elapsed for custom vector: "<<test.vecTime(startingCap, testNumber)<<endl;

    return 0;
}