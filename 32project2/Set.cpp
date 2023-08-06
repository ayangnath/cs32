//
//  Set.cpp
//  32project2
//
//  Created by Ayan Nath on 1/27/23.
//

#include "Set.h"
#include <iostream>
using namespace std;

//Constructor for the Set class
//Sets the size to 0 and the head and tail to null pointer
Set::Set()
{
    head = nullptr;
    tail = nullptr;
    m_size = 0;
}

//Copy constructor for the set class
//if the size is 0, sets the head and tail to null pointer
//if the size is 1, creates only one Node and sets the previous and next for that Node to null pointers
//if the size it 1, it also sets the head and tail to the only Node.
//if the size is greater than 1, it creates a single node, then goes through a for loop and keeps creating nodes size-1 times.
//after all notes are created, adjusts the previous and next pointers accordingly as well as copying the values of each nodes.
Set::Set(const Set &other) //COPY CONSTRUCTOR
{
    m_size = other.m_size; //copy the size

    //case for when size is 0
    if (m_size==0)
    {
        head = nullptr;
        tail = nullptr;
    }

    //case for when size is 1 and creates only one node
    else if (m_size == 1)
    {
        Node*ptr = new Node;
        ptr->next=nullptr;
        ptr->prev=nullptr;
        head = ptr;
        tail = ptr;
        ptr->value = other.head->value;
    }
    
    //case for when size is greater than 1 and has to create/copy multiple nodes
    else
    {
        Node* ptr = head = new Node;
        Node* ptrOther = other.head;
        ptr->value = other.head->value;
        ptr->prev = nullptr;
        for (int i = 0; i < m_size - 1; i++)
        {
            ptr->next = new Node;
            ptr->next->prev = ptr;
            ptr->next->value = ptrOther->next->value;
            ptr = ptr->next;
            ptrOther = ptrOther->next;
        }
        ptr->next = nullptr;
        tail = ptr;
    }
}

//Assignment operator for the Set class
//if the parameter 'other' has the same reference as the current object, return the current object
//Otherwise, create a temporary set and use the copy constructor to make the temp set a copy of other.
//Then, use the swap function to swap the temp set (which is a copy of the parameter other) with the current Set and return the current Set.
Set& Set::operator=(const Set &other) //ASSIGNMENT OPERATOR
{
    //if the parameter 'other' has the same reference as the current object, returns the current object
    if (&other ==this)
        return *this;
    
    //creating temporary Set and swapping
    Set temp = other;
    swap(temp);
    return *this;
}

//Destructor for the Set class
//if the size is 1 deletes the head
//if size is 0, do nothing
//all other cases, loop throigh the Set while deleting the previous Node as you are looping
//in all cases, delete the tail pointer
Set::~Set()
{
    //case 1 where it deletes the head since size ==1
    if (m_size==1)
    {
        delete head;
        return;
    }
    
    //case 2 where it does nothing since the size is 0
    if (m_size==0)
        return;
    
    //all other cases; loops through the Set and deletes the previous Node as the loop goes along
    Node* ptr = head;
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
        delete ptr -> prev;
    }
    delete tail;
}

//Return true if the set is empty, otherwise false.
bool Set::empty() const
{
    if (head==nullptr && tail ==nullptr)
        return true;
    
    else return false;
}

//Return the number of items in the set.
int Set::size() const
{
    return m_size;
}

//Inserts value into the set if it is not already present.
//My implementation for this method inserts it into the set in sorted order.
//For example, if the set is empty it adds a new node, if it is less than the head's value it inserts it before the head.
//If the inserted value is greater than the tail it adds to the end.
//If the inserted value is greater than the head and less than the tail, it loops through the Set until it gets placed at a location
//where the prev points to a value less than the inserted value and the next points to a value greater than the inserted value
bool Set::insert(const ItemType &value)
{
    //returns false if the Set already contains the value desired to be inserted
    if (contains(value))
        return false;
    
    //Case if the size is 0 and the first Node is being added
    if (m_size == 0)
    {
        Node* inserted = new Node;
        head = inserted;
        tail = inserted;

        inserted->value = value;
        inserted->next = nullptr;
        inserted->prev = nullptr;
    }
    
    //case for when it has to insert at the beginning
    else if (value < head->value)
    {
        Node* inserted = new Node;
        inserted->value = value;
        head->prev = inserted;
        inserted->next = head;
        inserted->prev = nullptr;
        head = inserted;
    }
    
    //Case for when inserting at the end
    else if (value > tail->value)
    {
        Node* inserted = new Node;
        inserted->value = value;
        tail->next = inserted;
        inserted->prev = tail;
        tail = inserted;
        tail->next = nullptr;
    }
    
    //Case for when inserting in the middle
    else
    {
        //looping through the Set
        for (Node*ptr = head; ptr!=nullptr; ptr = ptr->next)
        {
            if (ptr->value >value)
            {
                Node* inserted = new Node;
                inserted->value = value;
                inserted->next = ptr;
                inserted->prev = ptr->prev;
                ptr->prev->next = inserted;
                ptr->prev=inserted;
                break;
            }
        }
    }
    
    //incrementing size
    m_size++;
    return true;
}

//Removes the value from the set if the set is present.
//If the size is 0, returns false as there is nothing to erase.
//If the size is 1, and the value of the only Node is the desired value to erase, erase the singular value.
//Otherwise, loop through the Set and remove the value if it is found in the Set. While doing this, I had to make sure
//all the prev and next pointed pointed to the right things before I deleted the Node.
//return false if value is not present in the Set and leave the Set unchanged.
bool Set::erase(const ItemType& value) {
    
    // case when the size is 0
    if (m_size == 0)
        return false;
    
    // case when the size is 1
    if (m_size == 1 && value == head->value)
    {
        delete head;
        m_size = 0;
        head = nullptr;
        tail = nullptr;
        return true;
    }
    
    //case when the size is 1 but the value desired to be erased is not present in the Set
    else if (m_size == 1)
    {
        return false;
    }
    
    // All other cases, when size is more than one
    for (Node* ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        if (value == ptr->value)
        {
            Node* ptrOther = ptr;
            
            if (ptrOther == head)
            {
                head = head->next;
                head->prev = nullptr;
            }
            
            else if (ptrOther == tail)
            {
                tail = tail->prev;
                tail->next = nullptr;
            }
            else
            {
                ptrOther->next->prev = ptrOther->prev;
                ptrOther->prev->next = ptrOther->next;
            }
            
            // delete node
            delete ptrOther;
            m_size--;
            return true;
        }
    }
    return false;
}

//if the size is 0 return false.
//If the size is greater than, loop through the Set until the value is found.
//If the value is found, return true otherwise return false.
bool Set::contains(const ItemType &value) const
{
    //case when size is 0
    if (m_size==0)
        return false;
    
    //initial pointer to the head
    Node *ptr = head;
    
    //looping through the LinkedList using a while loop
    while (ptr!=nullptr)
    {
        //checking to see if value is found in the Set
        if (ptr->value == value)
            return true;
        
        ptr = ptr->next;
    }
    
    //returns false if value is not found in the Set.
    return false;
}

//If 0 <= i < size(), copy into value of (sorted from least to greatest) the item in the set
//Since I sorted the values in the Set in the insert function,
//this function just need to loop through the set 'pos' times and assign that value to the parameter.
//if position is less than 0 or greater than equal to size, return false; otherwise return true;
bool Set::get(int pos, ItemType &value) const
{
    //return false when the position is out of bounds of the Set
    if (pos < 0 || pos >=m_size)
        return false;

    Node*ptr = head;
    
    //Decrementing pos to find the right value
    while (pos!=0)
    {
        ptr = ptr->next;
        pos--;
    }
    value = ptr->value;
    return true;

}

//Exchanges the content of the parameter Set with the current Set
//first I swap the sizes, then I swap the heads, then I swap the tails
void Set::swap(Set &other)
{
    //swapping the sizes
    int temp_size = m_size;
    m_size = other.m_size;
    other.m_size= temp_size;
    
    //swapping the head pointers
    Node* temp_head;
    temp_head = head;
    head = other.head;
    other.head = temp_head;
    
    //swapping the tail pointers
    Node* temp_tail;
    temp_tail = tail;
    tail = other.tail;
    other.tail = temp_tail;
}

//Combines the values between two Sets but does not include overlapping values.
//Places the combined values in a set called result.
//if there are older values in result, do not include them after inserting the values from Set 1 and 2
//I looped through each s1 and s2 independently and inserted the vallues of each of them into a temp set.
//since insert wont insert any duplicates, the temp set should be the intended result
//assign temp to result upon completion of looping through s1 and s2.
void unite(const Set& s1, const Set& s2, Set& result)
{
    //creating temp Set and an ItempType val since get needs an ItemType in order to do its desired function
    Set temp;
    ItemType val;
    
    //loop through s1 and add val to the temp Set.
    for (int i = 0; i<s1.size(); i++)
    {
        s1.get(i, val);
        temp.insert(val);
    }
    //loop through s2 and add val to the temp Set.
    for (int i = 0; i<s2.size(); i++)
    {
        s2.get(i, val);
        temp.insert(val);
    }
    
    //assign temp to result
    result = temp;
}

//places values that are in s1 but not in s2 in result while removing any values that were in result before the function is called
//Loop through s1 and check if each value is in s2 or not.
//If the value in s1 is not in s2, add to the temp set.
//To get rid of all previosu values in result; assign temp to result before finishing the function.
void butNot(const Set& s1, const Set& s2, Set& result)
{
    //creating temp Set and an ItempType val since get needs an ItemType in order to do its desired function
    Set temp;
    ItemType val;
    
    //loop through s1 and add to temp is the value is not in s2
    for (int i = 0; i <s1.size(); i++)
    {
        s1.get(i, val);
        
        if (!s2.contains(val))
            temp.insert(val);
    }
    //assign temp to result
    result = temp;
}
