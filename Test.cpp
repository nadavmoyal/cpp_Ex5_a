#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/OrgChart.hpp"
using namespace ariel;

TEST_CASE("add_root & add_sub"){
    OrgChart organization;
    SUBCASE("Good input"){
      CHECK_NOTHROW(organization.add_root("David")
      .add_sub("David", "Simcha")
      .add_sub("David", "Aliza")
      .add_sub("Simcha", "Benush")
      .add_sub("Simcha", "Rotem")
      .add_sub("Simcha", "Nadav")
      .add_sub("Aliza", "Eli")
      .add_sub("Aliza", "Maayan") // Now the VP Software is subordinate to the CTO
      .add_sub("Maayan", "Ofri"));     // Now the VP_BI is subordinate to the COO
      CHECK_NOTHROW(organization.add_root("Moshe"));
    }
    SUBCASE("Bad input"){
      CHECK_THROWS(organization.add_sub("Bad", "Simcha")) ;        // Now the CTO is subordinate to the CEO
      CHECK_THROWS(organization.add_sub("input", "Aliza")) ;        // Now the CFO is subordinate to the CEO
      CHECK_THROWS(organization.add_sub("BIBI", "Benush"))  ;       // Now the COO is subordinate to the CEO
      CHECK_THROWS(organization.add_sub("netanyahu","Rotem"));
      CHECK_THROWS(organization.add_sub("Benet", "Benush"))  ;       // Now the COO is subordinate to the CEO
      CHECK_THROWS(organization.add_sub("israel", "Rotem"));
    }
    
//   cout << organization << endl; /* Prints the org chart in a reasonable format. For example:
    //    CEO
    //    |--------|--------|
    //    CTO      CFO      COO
    //    |                 |
    //    VP_SW             VP_BI
 
//         }
//   for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//   {
//     cout << (*it) << " " ;
//   } // prints: CEO CTO CFO COO VP_SW VP_BI
//   for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
//   {
//     cout << (*it) << " " ;
//   } // prints: VP_SW VP_BI CTO CFO COO CEO
//   for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
//     cout << (*it) << " " ;
//   }  // prints: CEO CTO VP_SW CFO COO VP_BI

//   for (auto element : organization)
//   { // this should work like level order
//     cout << element << " " ;
//   } // prints: CEO CTO CFO COO VP_SW VP_BI

//   // demonstrate the arrow operator:
//   for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//   {
//     cout << it->size() << " " ;
//   } // prints: 3 3 3 3 5 5
}
