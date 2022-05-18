#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "OrgChart.hpp"
using namespace std;

namespace ariel{
    OrgChart::OrgChart(){
        
    }
    OrgChart & OrgChart::add_root(string role){
        this->root._role=role;
        return *this;
    }

    OrgChart & OrgChart::add_sub(string father ,string son){
        bool f =findNode(father,son,this->root);
        if(f){
            return *this;
        }
        else{
                    ;
        }
        return *this;
    }

    bool OrgChart::findNode(string &target,string &subTarget,Org_node & currentNode){
        int key = target.compare(currentNode._role);
        if(key!=0){
            for( int i = 0 ; i < currentNode.son.size() ; i++ ){
               bool f = findNode(target,subTarget,currentNode.son.at((unsigned int )(i)));  
               if (f) {
                   return true;
                   }
            }                 
        }
        else{
            insertNode(subTarget,currentNode); 
            return true;
            }
        return false;
    }

    OrgChart & OrgChart::insertNode(string subTarget ,Org_node father){
        Org_node newSon;
        newSon._role=subTarget;
        father.son.push_back(newSon);
        return *this;
    }

    string*  OrgChart::begin_level_order(){
        string *s ;
         return s;
         }
    string*  OrgChart::begin_reverse_order(){
         string *s ;
         return s;
         }
    string* OrgChart::end_preorder(){
         string *s ;
         return s;
         }
    string*  OrgChart::end_level_order(){
         string *s ;
         return s;
         }
    string*  OrgChart::begin_preorder(){
         string *s ;
         return s;
         }
    string*  OrgChart::reverse_order(){
         string *s ;
         return s;
         }
    ostream &operator<< (ostream &out, const OrgChart &c){return out;}
    string* OrgChart::begin()
    {
        return begin_level_order();
    }
    string* OrgChart::end()
    {
        return end_level_order();
    }



}
