//
//  Unsorted Linked List.h
// COMP241
// Fall 2015
// PA3 Problem 1
// 05 November, 2015
// Nate McCain
//

#ifndef UnsortedLinkedList_h
#define UnsortedLinkedList_h

#include <stdio.h>

struct NodeType;

class UnsortedType
{
public:
    UnsortedType();
    void MakeEmpty();
    bool IsFull() const;
    int GetLength() const;
    int GetItem(int item, bool &found);
    void PutItem(int item);
    void DeleteItem(int item);
    void ResetList();
    int GetNextItem();
    int ComparedTo(int next);
    void PrintReversed();
    void Smaller();
    
private:
    NodeType *listData;
    int length;
    NodeType *currentPos;
    
};


struct NodeType
{
    int info;
    NodeType *next;
    void RevPrint(NodeType *listPtr);
    int Smallest(NodeType *small, NodeType *check);
};

















#endif /* UnsortedLinkedList_h */
