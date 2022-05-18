#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "OrgChart.hpp"
using namespace ariel;
/*
 * @author Nadav Moyal
 * @since 2022-05
 */

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
      .add_sub("Aliza", "Maayan") 
      .add_sub("Maayan", "Ofri"));   
       CHECK_NOTHROW(organization.add_root("Haim"));
       CHECK_NOTHROW(organization.add_root("Kobi"));
       CHECK_NOTHROW(organization.add_root("Yossi"));
       CHECK_NOTHROW(organization.add_root("Ben"));
       CHECK_NOTHROW(organization.add_root("Amit"));
       CHECK_NOTHROW(organization.add_root("Segal"));
       CHECK_NOTHROW(organization.add_root("bye"));
 
    }
    SUBCASE("Bad input"){
      CHECK_THROWS(organization.add_sub("Bad", "Simcha")) ;        // Now the CTO is subordinate to the CEO
      CHECK_THROWS(organization.add_sub("input", "Aliza")) ;        // Now the CFO is subordinate to the CEO
      CHECK_THROWS(organization.add_sub("BIBI", "Benush"))  ;       // Now the COO is subordinate to the CEO
      CHECK_THROWS(organization.add_sub("netanyahu","Rotem"));
      CHECK_THROWS(organization.add_sub("Benet", "Benush"))  ;       // Now the COO is subordinate to the CEO
      CHECK_THROWS(organization.add_sub("israel", "Rotem"));
      CHECK_THROWS(organization.add_sub("shalom", "Simcha")) ;        // Now the CTO is subordinate to the CEO
      CHECK_THROWS(organization.add_sub("Yuval", "Aliza")) ;        // Now the CFO is subordinate to the CEO
      CHECK_THROWS(organization.add_sub("26", "Benush"))  ;       // Now the COO is subordinate to the CEO
      CHECK_THROWS(organization.add_sub( "73" ,"Rotem"));
      CHECK_THROWS(organization.add_sub("{1,2,3}", "Benush"))  ;       // Now the COO is subordinate to the CEO
      CHECK_THROWS(organization.add_sub("skazi", "Rotem"));

    }
}
TEST_CASE("iterators"){
    OrgChart organization;
    SUBCASE("level_order"){
        string org="";
        CHECK_NOTHROW(organization.add_root("David")
        .add_sub("David", "Simcha")
        .add_sub("David", "Aliza")
        .add_sub("Simcha", "Benush")
        .add_sub("Simcha", "Rotem")
        .add_sub("Simcha", "Nadav")
        .add_sub("Aliza", "Eli")
        .add_sub("Aliza", "Maayan") 
        .add_sub("Maayan", "Ofri"));
        for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
        {
            org = org + " \n";
            org += *it; 
        }
        int k = org.compare(" \nDavid \nSimcha \nAliza \nBenush \nRotem \nNadav \nEli \nMaayan \nOfri");
        CHECK_EQ(k,0);
}
    SUBCASE("reverse_order"){
        string org="";
        for  (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
        {
            org = org + " \n";
            org += *it; 
        }
        
        int k = org.compare(" \nOfri \nMaayan \nEli \nNadav \nRotem \nBenush \nAliza \nSimcha \nDavid");
        CHECK_EQ(k,0);
}
    SUBCASE("preorder"){
        string org="";
        for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it)
        {
            org = org + " \n";
            org += *it; 
        }
        
        int k = org.compare(" \nDavid \nSimcha \nBenush \nRotem \nNadav \nAliza \nEli \nMaayan \nOfri");
        CHECK_EQ(k,0);
}
}
 