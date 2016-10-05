//
// proThreeProblemOne.cpp
// COMP241
// Fall 2015
// PA3 Problem 1
// 05 November, 2015
// Nate McCain
//

#include <iostream>
#include "UnsortedLinkedList.h"

using namespace std;



int main()
{
    UnsortedType list;
    list.PutItem(6);
    list.PutItem(84);
    list.PutItem(33);
    list.PutItem(12);
    list.PutItem(76);
    list.PutItem(14);
    list.PutItem(4);
    
    cout << "Printing in reverse." << endl;
    list.PrintReversed();
    list.Smaller();
    
    UnsortedType second;
    second.PutItem(4);
    second.PutItem(2);
    second.PutItem(66);
    second.PutItem(87);
    second.PutItem(1);
    second.PutItem(99);
    second.PutItem(0);
    second.PutItem(23);
    cout << "Printing in reverse." << endl;
    second.PrintReversed();
    second.Smaller();
    
    UnsortedType smallestList;
    smallestList.PutItem(99);
    smallestList.PutItem(199);
    smallestList.PutItem(9);
    smallestList.PutItem(999);
    smallestList.PutItem(990);
    cout << "Printing in reverse." << endl;
    smallestList.PrintReversed();
    smallestList.Smaller();
    
    return 0;
    
}


