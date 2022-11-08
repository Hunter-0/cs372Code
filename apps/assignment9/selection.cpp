#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include <utility>
#include <algorithm>
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


template <typename T>
void ourSwap(T& left, T& right) {
	T temp;
	temp = left;
	left = right;
	right = temp;
}

template<typename T>
void printArray(T theArray, int size) {
	for (int index = 0; index < size; ++index) {
		cout << theArray[index] << " ";
	}
	cout << endl;
}
template <typename T>
int Partition(T a, int start, int end) {
	int pivotValue, pivotIndex, mid;
	mid = (start + end) / 2;
	ourSwap(a[start], a[mid]);
	pivotIndex = start;
	pivotValue = a[start];
	for (int scan = start + 1; scan <= end; scan++) {
		if (a[scan] < pivotValue) {
			pivotIndex++;
			ourSwap(a[pivotIndex], a[scan]);
		}
	}
	ourSwap(a[start], a[pivotIndex]);
	return pivotIndex;
}

template<typename T>
void Quicksort(T a, int start, int end) {
	int pivotPosition;
	if (start < end) {
		pivotPosition = Partition(a, start, end);
		Quicksort(a, start, pivotPosition - 1);
		Quicksort(a, pivotPosition + 1, end);
	}
}

void selection_sort(std::vector<int>& to_sort) //https://codereview.stackexchange.com/questions/239122/my-c-sorting-algorithm-for-vector
{
    for (auto it = to_sort.begin(); it != to_sort.end(); ++it) {
        std::iter_swap(it, std::min_element(it, to_sort.end()));
    }
}

void display_vector(const std::vector<int>& to_display)
{
    if (to_display.empty()) {
       return;
    }
    std::copy(to_display.begin(), to_display.end() - 1,
              std::ostream_iterator<int>{std::cout, ", "});
    std::cout << to_display.back() << '\n';
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
    selection_sort(vec5);
    display_vector(vec5);

    selection_sort(vec10);
    display_vector(vec10);

    selection_sort(vec20);
    display_vector(vec20);

    selection_sort(vec50);
    display_vector(vec50);

    selection_sort(vec100);
    display_vector(vec100);

    selection_sort(vec1000);
    display_vector(vec1000);

    selection_sort(vec10000);
    display_vector(vec10000);

    selection_sort(vec50000);
    display_vector(vec50000);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    cout<< "Seconds elapsed: "<<elapsed_seconds.count()<<endl;
    start = std::chrono::steady_clock::now();
    Quicksort(vec5, 0, 5 - 1);
    printArray(vec5, 5);

    Quicksort(vec10, 0, 10 - 1);
    printArray(vec10, 10);

    Quicksort(vec20, 0, 20 - 1);
    printArray(vec20, 20);

    Quicksort(vec50, 0, 50 - 1);
    printArray(vec50, 50);

    Quicksort(vec100, 0, 100 - 1);
    printArray(vec100, 100);

    Quicksort(vec1000, 0, 1000 - 1);
    printArray(vec1000, 1000);

    Quicksort(vec10000, 0, 10000 - 1);
    printArray(vec10000, 10000);

    Quicksort(vec50000, 0, 50000 - 1);
    printArray(vec50000, 50000);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    cout<< "Seconds elapsed: "<<elapsed_seconds.count()<<endl;
    return 0;
}
