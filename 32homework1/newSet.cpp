//
//  Set.cpp
//  32homework1
//
//  Created by Ayan Nath on 1/19/23.
//

#include <iostream>
#include "newSet.h"
#include <utility>
using namespace std;

Set::Set(int n)
{
    if (n < 0)
    {
        cout<< "'n' must be greater than or equal to 0!" << endl;
        exit(1);
    }
    
    set_size = 0;
    max_size = n;
    myArray = new ItemType[max_size];
}

Set::Set(const Set &other)
{
    set_size= other.set_size;
    max_size= other.max_size;
    myArray = new ItemType[max_size];
    
    for (int i = 0; i < set_size; i++)
    {
        myArray[i] = other.myArray[i];
    }
}

Set&Set::operator=(const Set &other)
{
    if (&other==this)
        return *this;
    
    delete [] myArray;
    set_size = other.set_size;
    max_size = other.max_size;
    myArray = new ItemType[max_size];
    
    for (int i = 0; i < set_size; i ++)
    {
        myArray[i]=other.myArray[i];
    }
    
    return *this;
}

Set::~Set()
{
    delete [] myArray;
}

bool Set::empty() const
{
    if (set_size==0)
        return true;

    return false;
}

int Set::size() const
{
    return set_size;
}

bool Set::insert(const ItemType &value)
{
    if (contains(value) || set_size>=max_size)
    {
        return false;
    }

    for (int i = 0; i < size(); i++)
    {
        if (value < myArray[i])
        {
            set_size++;
            for (int j = size()-1; j>i; j--)
            {
                myArray[j]=myArray[j-1];
            }
            myArray[i]= value;
            return true;
        }
    }

    set_size++;
    myArray[size()-1]=value;
    return true;
}

bool Set::erase(const ItemType &value)
{
    if (contains(value)==false)
        return false;

    int position = 0;

    for (int i = 0; i < size(); i++)
    {
        if (myArray[i]==value)
        {
            position = i;
        }
    }

    for (int j = position; j < size()-1; j++)
    {
        myArray[j]=myArray[j+1];
    }

    set_size--;
    return true;
}

bool Set::contains(const ItemType &value) const
{
    for (int i = 0; i < set_size; i++)
    {
        if (myArray[i]==value)
        {
            return true;
        }
    }

    return false;
}

bool Set::get(int i, ItemType &value) const
{
    if (i <0 || i > set_size)
        return false;

    value = myArray[i];
    return true;
}

void Set::swap(Set &other)
{
    std::swap(other.myArray, myArray);

    int temp = set_size;
    set_size=other.set_size;
    other.set_size=temp;
    
    int temp2 = max_size;
    max_size=other.max_size;
    other.max_size=temp2;

//    ItemType temp[DEFAULT_MAX_ITEMS];
//
//    int tempsize = size();
//
//    for (int i = 0; i < tempsize; i++)
//    {
//        temp[i]=myArray[i];
//    }
//
//    set_size=other.size();
//    for (int i = 0; i <set_size; i++)
//    {
//        myArray[i]=other.myArray[i];
//    }
//
//    other.set_size=tempsize;
//    for (int i =0; i < other.size(); i++)
//    {
//        other.myArray[i]=temp[i];
//    }

}


