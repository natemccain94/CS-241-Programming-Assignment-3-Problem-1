//
//  UnsortedLinkedList.cpp
// COMP241
// Fall 2015
// PA3 Problem 1
// 05 November, 2015
// Nate McCain
//

#include "UnsortedLinkedList.h"
#include <iostream>

using namespace std;

// Constructor
UnsortedType::UnsortedType()
{
    length = 0;
    listData = NULL;
}


// Is Full
bool UnsortedType::IsFull() const
{
    NodeType *location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

// Reset List
void UnsortedType::ResetList()
{
    currentPos = NULL;
}

// Get Length
int UnsortedType::GetLength() const
{
    return length;
}

// Make Empty
void UnsortedType::MakeEmpty()
{
    NodeType *temp;
    while (listData != NULL)
    {
        temp = listData;
        listData = listData->next;
        delete temp;
    }
    length = 0;
}

// Get Next Item
int UnsortedType::GetNextItem()
{
    if (currentPos == NULL)
    {
        currentPos = listData;
    }
    else
    {
        currentPos = currentPos->next;
    }
    return (currentPos->info);
}

int UnsortedType::GetItem(int item, bool &found)
{
    bool moreToSearch;
    NodeType *location;
    
    location = listData;
    found = false;
    moreToSearch = (location != NULL);
    
    while (moreToSearch && !found)
    {
        switch (ComparedTo(item))
        {
            case -1:
            case 1: location = location->next;
                moreToSearch = (location != NULL);
                break;
            case 0: found = true;
                item = location->info;
                break;
        }
    }
    return item;
}


int UnsortedType::ComparedTo(int next)
{
    if (listData->info < next)
    {
        return 1;
    }
    else if (listData->info > next)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

// Put Item
void UnsortedType::PutItem(int item)
{
    NodeType *location;
    location = new NodeType;
    location->info = item;
    location->next = listData;
    listData = location;
    currentPos = listData;
    length++;
}

// Delete Item
void UnsortedType::DeleteItem(int item)
{
    NodeType *temp = new NodeType;
    if (item == listData->info)
    {
        temp = listData;
        listData = listData->next;
    }
    else
    {
        while (!(item == (listData->next)->info))
        {
            listData = listData->next;
        }
        
        temp = listData->next;
        listData->next = (listData->next)->next;
    }
    currentPos = listData;
    delete temp;
    length--;
}


// Smallest Item
int Smallest(NodeType *small, NodeType *check)
{
    if (check == NULL)
    {
        return small->info;
    }
    else
    {
        if (small->info < check->info)
        {
            return Smallest(small, check->next);
        }
        else
        {
            return Smallest(check, check->next);
        }
        
    }
}

void UnsortedType::Smaller()
{
    cout << "The smallest integer in the unsorted linked list is: " << Smallest(listData, listData->next) << endl;
}

void RevPrint(NodeType *listPtr)
{
    if (listPtr != NULL)
    {
        RevPrint(listPtr->next);
        cout << listPtr->info << endl;
    }
}

void UnsortedType::PrintReversed()
{
    RevPrint(listData);
}


