#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;
namespace ariel{
struct Org_node{
    vector<Org_node> son;
    string _role;
} ;
class OrgChart{
    Org_node root;
    public:
//  OrgChart buliding functions:
    OrgChart();    
    OrgChart &add_root(string role);
    OrgChart &add_sub(string father ,string s);
    
    //iterators:
    string* begin_level_order();
    string* begin_reverse_order();
    string* end_preorder();
    string* end_level_order();
    string* begin_preorder();
    string* reverse_order();
    string* begin();
    string* end();

// Auxiliary functions:
    bool findNode(string &target,string &subTarget,Org_node & currentNode);
    OrgChart & insertNode(string subTarget ,Org_node father);

// orperators:
    friend ostream & operator<< (ostream &out, const OrgChart &c);
};

};