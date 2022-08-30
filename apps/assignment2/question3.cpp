#include <iostream>
#include <vector>
using namespace std;

template <typename Thing>
class ReceiptBag {
    private:
        vector<Thing> bagContents;
        vector<int> bagReceipt;
        int receiptCounter = 0;
        int bagSize = 0;
        Thing foundThing;
    public:
        int insert(Thing aThing){
            bagContents.push_back(aThing);
            receiptCounter++;
            bagReceipt.push_back(receiptCounter);
            bagSize++;
            return receiptCounter;
        }

        Thing *pop(int receipt) {

            int removeIndex = -1;

            for (int i = 0; i < bagReceipt.size(); i++) {
                if(bagReceipt[i] == receipt) {
                    removeIndex = i;
                    break;
                }
            }

            if (removeIndex != -1) {
                foundThing = bagContents[removeIndex];
                bagContents.erase(bagContents.begin() + removeIndex);
                bagReceipt.erase(bagReceipt.begin() + removeIndex);
                bagSize--;
                return &foundThing;
            }
            else {
                return nullptr;
            }

        }

        int size() {
            return bagSize;
        }
        int count(Thing aThing) {
            int bagCount = 0;
            for (int i = 0 ; i < bagSize; i++) {
                if (bagContents[i] == aThing) {
                    bagCount++;
                }
            }
            return bagCount;
        }

};

int main(){
    ReceiptBag<int> Bag;
    int firstReceipt = Bag.insert(3);
    int secondReceipt = Bag.insert(7);
    int thirdReceipt = Bag.insert(1);
    cout<<"Receipt of 3: " << firstReceipt <<endl;
    cout<<"Using receipt, got item: " << *Bag.pop(firstReceipt) <<endl;
    cout<<"Receipt of 7: " << secondReceipt <<endl;
    cout<<"Using receipt, got item: " << *Bag.pop(secondReceipt) <<endl;
    cout<<"Receipt of 1: " << thirdReceipt <<endl;
    cout<<"Using receipt, got item: " << *Bag.pop(thirdReceipt) <<endl;

    return 0;
}