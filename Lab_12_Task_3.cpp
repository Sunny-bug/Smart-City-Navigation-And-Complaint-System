#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> table[11];  

    int numbers[] = {23, 45, 66, 68, 9};
    int n = 5;

    for(int i = 0; i < n; i++){
        int index = numbers[i] % 11;
        table[index].push_back(numbers[i]);
    }
    
    for(int i = 0; i < 11; i++){
        cout << "Index " << i << ": ";
        for(int num : table[i]){
            cout << num << " -> ";
        }
        cout << "NULL" << endl;  
    }

    return 0;
}
