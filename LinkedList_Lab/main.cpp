#include <iostream>
#include "ll.h"

using namespace std;

int main() {
    LinkedList list;

    for (bool done = false; !done; ) {
    unsigned int i;
    int option;

    cout << "Choose an operation:\n"
         << "1. Insert\t2. Remove\t3. Print\t4. Exit\n";

    cin >> option;

    switch (option)
    {
        case 1:
            cout << "Enter a number: \n";
            cin >> i;
            list.insert(i);
            break;
        case 2:
            if (list.remove(i))
                cout << "Removed: " << i << '\n';
            else
                cout << "There are no numbers.\n";
                break;
        case 3:
            cout << "Current List of Numbers: " << list << "\n";
            break;
        case 4:
            done = true;
            break;
    }
    }
    return 0;
} 
