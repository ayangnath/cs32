//#include "newSet.h"
//   #include <iostream>
//   #include <cassert>
//   using namespace std;
//
//   int main()
//   {
//
//       Set a(1000);   // a can hold at most 1000 distinct items
//            Set b(5);      // b can hold at most 5 distinct items
//            Set c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
//            ItemType v[6] = { "hi1","hi2","hi3","hi4","hi5","hi6" };
//
//              // No failures inserting 5 distinct items into b
//            for (int k = 0; k < 5; k++)
//                assert(b.insert(v[k]));
//
//              // Failure if we try to insert a sixth distinct item into b
//            assert(!b.insert(v[5]));
//
//              // When two Sets' contents are swapped, their capacities are swapped
//              // as well:
//            a.swap(b);
//            assert(!a.insert(v[5])  &&  b.insert(v[5]));
//
//       Set pranav(0);
//
//       Set ss(100);
//       ss.insert("lavash");
//       ss.insert("roti");
//       ss.insert("chapati");
//       ss.insert("injera");
//       ss.insert("roti");
//       ss.insert("matzo");
//       ss.insert("injera");
//       assert(ss.size() == 5);  // duplicate "roti" and "injera" were not added
//       string x;
//       ss.get(0, x);
//       assert(x == "chapati");  // "chapati" is greater than exactly 0 items in ss
//       ss.get(4, x);
//       assert(x == "roti");  // "roti" is greater than exactly 4 items in ss
//       ss.get(2, x);
//           assert(x == "lavash");  // "lavash" is greater than exactly 2 items in ss
//
//       Set ss1(100);
//       ss1.insert("laobing");
//       Set ss2(200);
//       ss2.insert("matzo");
//       ss2.insert("pita");
//       ss1.swap(ss2);
//       assert(ss1.size() == 2  &&  ss1.contains("matzo")  &&  ss1.contains("pita")  &&
//                  ss2.size() == 1  &&  ss2.contains("laobing"));
//
//       Set ss3(300);
//           ss3.insert("dosa");
//           assert(!ss3.contains(""));
//           ss3.insert("tortilla");
//           ss3.insert("");
//           ss3.insert("focaccia");
//           assert(ss3.contains(""));
//           ss3.erase("dosa");
//           assert(ss3.size() == 3  &&  ss3.contains("focaccia")  &&  ss3.contains("tortilla")  &&
//                       ss3.contains(""));
//           string w;
//           assert(ss3.get(1, w)  &&  w == "focaccia");
//           assert(ss3.get(0, w)  &&  w == "");
//
//       Set ss4(100);
//           assert(ss4.insert("roti"));
//           assert(ss4.insert("pita"));
//           assert(ss4.size() == 2);
//           assert(ss4.contains("pita"));
//           ItemType z = "laobing";
//           assert(ss4.get(0, z)  &&  z == "pita");
//           assert(ss4.get(1, z)  &&  z == "roti");
//
//
//       Set s(100);
//       assert(s.empty());
//       ItemType y = "arepa";
//       assert( !s.get(42, y)  &&  y == "arepa"); // x unchanged by get failure
//       s.insert("chapati");
//       assert(s.size() == 1);
//       assert(s.get(0, y)  &&  y == "chapati");
//       cout << "Passed all tests" << endl;
//
//}
//
