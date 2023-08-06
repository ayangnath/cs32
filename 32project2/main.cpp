#include "Set.h"
#include <iostream>
#include <cassert>
using namespace std;


void testInternalMethods() {

    //
    // TESTS for Set::insert(val), Set::get(pos, val) , Set::empty(), Set::size(), Set::contains()
    //

    //testing the methods on an empty Set
    Set test; //creating a Set called test
    assert(test.size() == 0); //validating empty Set size == 0
    assert(test.empty()); //validating empty method returns true on an empy Set
    assert(!test.contains("bear")); //tests contains and validates that the Set does not contain anything
    ItemType val = "";
    assert(test.insert("bear")); //testing insert on an empty list
    assert(test.get(0, val) && val == "bear"); //tests get and validates that "bear" was indeed inserted
    //Now, need to make sure that duplicates cannot be inserted!
    assert(!test.insert("bear")); // test insert and validates that inserting "bear" again will return false
    assert(test.size() == 1); //validates the size is still 1 and nothing was inserted
    assert(test.contains("bear")); //test contains and validates that bear is still in the Set
    assert(!test.get(-1, val) && val == "bear"); //make sure that negative position does not work

    //at this point, the only thing that should be in the Set is [bear]
    //Now, we can try to insert at the beginning of the list
    assert(test.insert("ant")); //inserting a new item at the beginning
    assert(test.get(0, val) && val == "ant"); //validates that "ant" was inserted in correct order
    assert(test.get(1, val) && val == "bear");//validates that "bear" remains in the list in the correct order
    assert(test.size() == 2); //validates size
    assert(test.contains("bear")); //test contains and validates that bear is still in the Set
    assert(test.contains("ant"));//test contains and validates that ant is still in the Set

    //What the set looks like at this point: [ant bear]
    //testing insert at end of list
    assert(test.insert("penguin")); //testing insert and adding "penguin" to end of the Set
    assert(test.get(2, val) && val == "penguin"); //testing get and make sures penguin is at the right index
    assert(!test.get(3, val) && val == "penguin");//also testing get and make sures penguin is at the right index
    assert(test.size() == 3); //testing size and validating that penguin was added to the Set
    assert(test.contains("ant")); //tests contains and makes sure ant is still in the Set
    assert(test.contains("bear")); //tests contains and makes sure bear is still in the Set
    assert(test.contains("penguin"));//test contains and makes sure penguin is still in the Set

    //What the set looks like at this point: [ant bear penguin]
    //testing to make sure insert works in the middle of the list
    assert(test.insert("monkey"));// tests insert and inserts "monkey"
    //What the set looks like at this point: [ant bear monkey penguin]
    assert(test.get(0, val) && val == "ant"); //testing to make sure insert and get worked after inserting in middle
    assert(test.get(1, val) && val == "bear"); //testing to make sure insert and get worked after inserting in middle
    assert(test.get(2, val) && val == "monkey"); //testing to make sure insert and get worked after inserting in middle
    assert(test.get(3, val) && val == "penguin"); //testing to make sure insert and get worked after inserting in middle
    assert(!test.get(4, val) && val == "penguin"); //testing to make sure insert and get worked after inserting in middle
    assert(test.size() == 4); //testing to make sure size worked after inserting in the middle

    //test contains to make sure all inserted ItempTypes are still in in the Set
    assert(test.contains("ant"));//tests contains and makes sure "ant" is still in the Set
    assert(test.contains("bear"));//tests contains and makes sure "bear" is still in the Set
    assert(test.contains("penguin"));//tests contains and makes sure "penguin" is still in the Set
    assert(test.contains("monkey"));//tests contains and makes sure "monkey" is still in the Set
    //at this point the test Set should be:[ant bear monkey penguin]

    //Test erasing
    assert(!test.erase("asdf")); //tests erase and makes sure it returns false when trying to erase "asdf" which is not in the Set
    assert(test.erase("penguin")); //tests erate by erasing penguin from the end
    assert(test.size() == 3);//make sure erase works by validating that the size has decreased
    assert(!test.contains("penguin")); //tests erase by making sure contains is no longer in the array

    //Now need to test if erase works from the middle
    assert(test.erase("bear")); //making sure erasing bear works
    //the Set should be: [ant monkey] after erasing bear
    assert(test.size() == 2); //testing size and validating that erase decreased the size
    assert(!test.contains("penguin"));//valtidating erase worked my making sure penguin is not in Set
    assert(!test.contains("bear"));//valtidating erase worked my making sure bear is not in Set

    //Now, need to test if erase works from beginning
    assert(test.erase("ant")); //testing erase at the first element of the Set
    assert(test.size() == 1); //validating that erasing "ant" decreased the size
    assert(!test.contains("ant")); //valtidating erase worked my making sure "ant" is not in Set
    assert(test.contains("monkey")); //validates that monkey is still in the set
    //testing erase when size ==1
    assert(test.erase("monkey")); //testing if erase works when size ==1
    assert(test.empty()); //validating that empty works after erasing
    assert(test.size() == 0);//validating that the last element was removed and size ==0
}

void testSwap() {
    Set first; Set second; //creating 2 sets that will eventually be swapped
    ItemType val = "";
    first.insert("ant"); //inserting items into first Set
    first.insert("bear"); //inserting items into first Set
    first.insert("monkey"); //inserting items into first Set
    first.insert("penguin"); //inserting items into first Set
    second.swap(first); //swap the sets
    //after swapping, now second = [ant bear monkey penguin] and first = []
    assert(first.size() == 0); //validating that swapping worked by checking if first.size()==0
    assert(first.empty()); //validating first is empty after swap
    assert(second.size() == 4); //validating second's size afer swapping
    assert(!second.empty()); //validating that second is NOT empty after swap
    //recall that second was empty when it was created and first had 4 elements inserted into it
    //the above methods tested to make sure that the following is the case:
    //after the swap function, first should be empty and second should have four elements
    //Now, the below statements will make sure that the actual elements themselves were swapping in the right order
    assert(second.get(0, val) && val == "ant"); //test "ant" is in second after swapping with first
    assert(second.get(1, val) && val == "bear"); //test "bear" is in second after swapping with first
    assert(second.get(2, val) && val == "monkey"); //test "monkey" is in second after swapping with first
    assert(second.get(3, val) && val == "penguin"); //test "penguin" is in second after swapping with first
}

void testAssignment() {
    Set original; //creating new Set
    original.insert("ant"); //inserting elements into original set
    original.insert("bear"); //inserting elements into original set
    original.insert("penguin"); //inserting elements into original set
    original.insert("monkey"); //inserting elements into original set
    Set assignment; //creating the Set we will use in the assignment operator
    assignment = original; //testing the assignment operator
    assert(assignment.erase("ant")); //this should only erase "ant" from assignment not original
    assert(original.size() == 4); //validating nothing was removed from original
    assert(original.contains("ant")); //validating "ant" was not removed from original
    assert(assignment.size() == 3); //validating that something was removed from assignment
    
    //NOW testing copy constructor
    Set copy=original; //creating a new Set called copy which is a copy of original
    assert(copy.erase("ant")); //erasing "ant" from the copy
    assert(copy.size() == 3); //erasing "ant" should decrease size from copy
    assert(original.size() == 4); //testing to make sure that original doesn't decrease in size
    assert(original.contains("ant"));//also testing that original still contains "ant"
    assert(!copy.contains("ant"));//testing that the removal of "ant" worked on copy
}

void testCopyConstructor() {
    Set s;
    s.insert("ant");
    s.insert("bear");
    s.insert("penguin");
    s.insert("monkey");
    Set t=s;

    assert(t.erase("ant"));
    assert(t.size() == 3);
    assert(s.size() == 4);
    assert(s.contains("ant"));
    assert(!t.contains("ant"));
    

}

void testUniteButNot() {

    //General case, when s1 and s2 and r are all different
    Set s1; //creating set 1
    Set s2; //creating set 2
    Set r; //creating result set
    ItemType val = "";
    assert(s1.insert("ant")); //inserting items into set1
    assert(s1.insert("bear")); //inserting items into set1
    assert(s2.insert("monkey")); //inserting items into set2
    assert(s2.insert("ant")); //inserting items into set2
    assert(s2.insert("penguin")); //inserting items into set2
    assert(r.insert("blueberries")); //inserting items into r
    //at this point s1 should be: [ant bear]
    //at this point s2 should be: [ant monkey penguin]
    //r = [blueberries]
    //NOW testing unite functuin
    unite(s1, s2, r); //testung unite
    //after testing unite here is what the following sets should contain:
    //s1: [ant bear]
    //s2: [ant monkey penguin]
    //r: [ant bear monkey penguin]
    assert(r.size() == 4); //validating that unite worked by testing the size
    assert(r.get(0, val) && val == "ant"); //validating that unite worked by checking the elements inside
    assert(r.get(1, val) && val == "bear"); //validating that unite worked by checking the elements inside
    assert(r.get(2, val) && val == "monkey"); //validating that unite worked by checking the elements inside
    assert(r.get(3, val) && val == "penguin"); //validating that unite worked by checking the elements inside
    //NOW testing butNot function
    butNot(s1, s2, r);
    //after this statement, this is what the following sets should contain:
    //s1: [ant bear]
    //s2: [ant monkey penguin]
    //r: [bear]
    assert(s1.size() == 2); //making sure there are no changes to s1
    assert(s1.get(0, val) && val == "ant"); //making sure there are no changes to s1
    assert(s1.get(1, val) && val == "bear"); //making sure there are no changes to s1
    assert(s2.size() == 3); //making sure there are no changes to s2
    assert(s2.get(0, val) && val == "ant"); //making sure there are no changes to s2
    assert(s2.get(1, val) && val == "monkey"); //making sure there are no changes to s2
    assert(s2.get(2, val) && val == "penguin"); //making sure there are no changes to s2
    assert(r.size() == 1); //via its size, tests r only has "bear" as it was in s1 but not s2
    assert(r.get(0, val) && val == "bear"); //tests r only has "bear" as it was in s1 but not s2
 

    //Case for when s1==s1
    unite(s1, s1, r); //testing unite
    //for reference, s1: [ant bear]
    //this function should result in r: [ant bear] as s1 and s2 parameters are the same
    assert(r.size() == 2); //validating that r is of size 2
    assert(r.get(0, val) && val == "ant"); //testing to confirm r has "ant"
    assert(r.get(1, val) && val == "bear"); //testing to confrim r has "bear"
    //NOW testing butNOt when s1 == s2
    butNot(s1, s1, r);
    //as a result of this, r = [] because s1 and s2 are the same.
    //thus there is nothing in s1 that isn't in the s2 paramter
    assert(r.size() == 0); //validating that r is indeed size 0;

    
    //Case when s1==result
    unite(s1, s2, s1);
    //as of now, s1 = [ant bear monkey penguin]
    //as of now, s2 = [ant monkey penguin]
    //after unite is called, r should be: []
    assert(s1.size() == 4); //validating size of s1
    assert(s1.get(0, val) && val == "ant"); //validating contents of s1 after unite
    assert(s1.get(1, val) && val == "bear"); //validating contents of s1 after unite
    assert(s1.get(2, val) && val == "monkey"); //validating contents of s1 after unite
    assert(s1.get(3, val) && val == "penguin"); //validating contents of s1 after unite
    assert(s2.size() == 3); //validating size of s2 after unite
    assert(s2.get(0, val) && val == "ant"); //validating contents of s2 after unite
    assert(s2.get(1, val) && val == "monkey"); //validating contents of s2 after unite
    assert(s2.get(2, val) && val == "penguin"); //validating contents of s2 after unite
    assert(r.size() == 0); //via size, makes sure r behaves properly if s1==result in unite
    //NOW testing butNot if s1==result
    butNot(s1, s2, s1);
    //now, s1 = [bear]
    //now, s2 = [ant monkey penguin]
    //now, r = []
    assert(s1.size() == 1); //validating size of s1 after butNot
    assert(s1.get(0, val) && val == "bear"); //validating contents of s1 after butNot
    assert(s2.size() == 3); //validating size of s2 after butNot
    assert(s2.get(0, val) && val == "ant"); //validating contents of s2 after butNot
    assert(s2.get(1, val) && val == "monkey"); //validating contents of s2 after butNot
    assert(s2.get(2, val) && val == "penguin"); //validating contents of s2 after butNot
    assert(r.size() == 0); //via size, makes sure r behaves properly if s1==result in butNot


    //Case for when s2 == result
    unite(s1, s2, s2);
    //now, s1 = [bear]
    //now, s2 = [ant bear monkey penguin]
    //now, r = []
    assert(s1.size() == 1); //validating size of s1 after unite
    assert(s1.get(0, val) && val == "bear"); //validating contents of s1 after unite
    assert(s2.get(0, val) && val == "ant"); //validating contents of s2 after unite
    assert(s2.get(1, val) && val == "bear"); //validating contents of s2 after unite
    assert(s2.get(2, val) && val == "monkey"); //validating contents of s2 after unite
    assert(s2.get(3, val) && val == "penguin"); //validating contents of s2 after unite
    assert(r.size() == 0); //via size, makes sure r behaves properly if s2==result in butNot
    //now testing butNot when s2==result
    butNot(s2, s1, s1);
    //now, s1 = [ant monkey penguin]
    //now, s2 = [ant bear monkey penguin]
    //now, r = []
    assert(s1.size() == 3); //validating size of s1 after butNot
    assert(s1.get(0, val) && val=="ant"); //validating contents of s1 after butNot
    assert(s1.get(1, val) && val == "monkey"); //validating contents of s1 after butNot
    assert(s1.get(2, val) && val == "penguin"); //validating contents of s1 after butNot
    assert(s2.size() == 4); //validating size of s2 after butNot
    assert(s2.get(0, val) && val=="ant"); //validating contents of s2 after butNot
    assert(s2.get(1, val) && val == "bear"); //validating contents of s2 after butNot
    assert(s2.get(2, val) && val == "monkey"); //validating contents of s2 after butNot
    assert(s2.get(3, val) && val == "penguin"); //validating contents of s2 after butNot
    assert(r.size() == 0);  //via size, makes sure r behaves properly if s2==result in butNot
}

//should not raise any seg faults
void testDestructor() {
    Set s;
    Set s1;
    Set s2;
    Set s3;
    s1.insert("ant");

    s2.insert("ant");
    s2.insert("bear");

    s3.insert("ant");
    s3.insert("bear");
    s3.insert("penguin");

}

int main() {

    testInternalMethods();
    testSwap();
    testAssignment();
    testCopyConstructor();
    testDestructor();

    testUniteButNot();

    //old tests from hw1
    Set ss;
    ss.insert("lavash");
    ss.insert("roti");
    ss.insert("chapati");
    ss.insert("injera");
    ss.insert("roti");
    ss.insert("matzo");
    ss.insert("injera");
    assert(ss.size() == 5);  // duplicate "roti" and "injera" were not added
    ItemType x;
    ss.get(0, x);
    assert(x == "chapati");  // "chapati" is greater than exactly 0 items in ss
    ss.get(4, x);
    assert(x == "roti");  // "roti" is greater than exactly 4 items in ss
    ss.get(2, x);
    assert(x == "lavash");  // "lavash" is greater than exactly 2 items in ss

    Set ss1;
    ss1.insert("laobing");
    Set ss2;
    ss2.insert("matzo");
    ss2.insert("pita");
    ss1.swap(ss2);
    assert(ss1.size() == 2  &&  ss1.contains("matzo")  &&  ss1.contains("pita")  &&
                ss2.size() == 1  &&  ss2.contains("laobing"));

    Set ss3;
    ss3.insert("dosa");
    assert(!ss3.contains(""));
    ss3.insert("tortilla");
    ss3.insert("");
    ss3.insert("focaccia");
    assert(ss3.contains(""));
    ss3.erase("dosa");
    assert(ss3.size() == 3  &&  ss3.contains("focaccia")  &&  ss3.contains("tortilla")  &&
                ss3.contains(""));
    ItemType v;
    assert(ss3.get(1, v)  &&  v == "focaccia");
    assert(ss3.get(0, v)  &&  v == "");

    cout << "You passed all tests! :)" << endl;

}
