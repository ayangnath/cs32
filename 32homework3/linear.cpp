////
////  linear.cpp
////  32homework3
////
////  Created by Ayan Nath on 2/10/23.
////
//#include <iostream> //remove these after done
//
//bool somePredicate(double x)
//    {
//        return x < 0;
//    }
//
//// Return true if the somePredicate function returns true for at
//    // least one of the array elements; return false otherwise.
//  bool anyTrue(const double a[], int n)
//  {
//      if (n<=0)
//          return false;
//      if(somePredicate(*a))
//          return true;
//      
//      return anyTrue(a+1, n-1);
//  }
//
//    // Return the number of elements in the array for which the
//    // somePredicate function returns true.
//  int countTrue(const double a[], int n)
//  {
//      if (n<=0)
//          return 0;
//      
//      if (somePredicate(*a)==true)
//          return 1+ countTrue(a+1, n-1);
//      
//      else return countTrue(a+1, n-1);
//  }
//
//    // Return the subscript of the first element in the array for which
//    // the somePredicate function returns true.  If there is no such
//    // element, return -1.
//  int firstTrue(const double a[], int n)
//  {
//      if (n<=0)
//          return -1;
//      
//      int i = firstTrue(a+1, n-1);
//    
//      if (i == -1)
//      {
//          if (somePredicate(*a)==true)
//              return 0;
//          
//          else return -1;
//      }
//      
//      if (somePredicate(*a)==true)
//      {
//          return 0;
//      }
//      
//      else return 1 + i;
//  }
//
//    // Return the subscript of the smallest element in the array (i.e.,
//    // return the smallest subscript m such that a[m] <= a[k] for all
//    // k from 0 to n-1).  If the function is told that no doubles are to
//    // be considered in the array, return -1.
//  int indexOfMinimum(const double a[], int n)
//  {
//      if (n<= 0)
//          return -1;
//      
//      if (n ==1)
//          return 0;
//      
//      int middle = n/2;
//      int midOne = indexOfMinimum(a, middle);
//      int midTwo = indexOfMinimum(a + middle, n - middle) + middle;
//      
//      if (a[midOne] < a[midTwo])
//          return midOne;
//      
//      else return midTwo;
//  }
//
//    // If all n1 elements of a1 appear in the n2 element array a2, in
//    // the same order (though not necessarily consecutively), then
//    // return true; otherwise (i.e., if the array a1 is not a
//    // not-necessarily-contiguous subsequence of a2), return false.
//    // (Of course, if a1 is empty (i.e., n1 is 0), return true.)
//    // For example, if a2 is the 7 element array
//    //    10 50 40 20 50 40 30
//    // then the function should return true if a1 is
//    //    50 20 30
//    // or
//    //    50 40 40
//    // and it should return false if a1 is
//    //    50 30 20
//    // or
//    //    10 20 20
//  bool isIn(const double a1[], int n1, const double a2[], int n2)
//  {
//      if (n1 <= 0) //if a1 is empty
//          return true;
//      if (n1 > n2)
//          return false;
//      
//      if (n2<0)
//          return false;
//      
//      if (a1[0]==a2[0])
//          return isIn(a1+1, n1-1, a2+1, n2-1);
//      
//      return isIn(a1, n1, a2+1, n2-1);
//  }
//
//int main()
//{
//    double first[4] = {-1, 2, 3, -4};
//    double second[4] = {1, 2, 3, 4};
//
//    if (anyTrue(first, 4))
//        std::cout << "true" << std::endl;
//    else std::cout << "false" << std::endl;
//
//    if (anyTrue(second, 4))
//        std::cout << "true" << std::endl;
//    else std::cout << "false" << std::endl;
//
//    std::cout<< countTrue(first, 4) << std::endl;
//
//    std::cout << firstTrue(first, 4) << std::endl;
//
//    std::cout << indexOfMinimum(first, 4) << std::endl;
//    std::cout << indexOfMinimum(second, 4) << std::endl;
//
//    std::cout << isIn(first, 4, second, 4) << std::endl;
//
//
//    double a2[7] = {10, 50, 40, 20, 50, 40, 30,};
//    if (10>3)
//    {
//        double a1[0]= {};
//        std::cout << isIn(a1, 0, a2, 7) << std::endl; // should return true 1
//    }
//
//    if (10>3)
//    {
//        double a1[3]= {50, 20, 30};
//        std::cout << isIn(a1, 3, a2, 7) << std::endl; // should return true 1
//    }
//
//    if (10>3)
//    {
//        double a1[3]= {50, 30, 20};
//        std::cout << isIn(a1, 3, a2, 7) << std::endl; // should return false 0
//    }
//
//    if (10>3)
//    {
//        double a1[3]= {10, 20, 20};
//        std::cout << isIn(a1, 3, a2, 7) << std::endl; // should return false 0
//    }
//
//}
