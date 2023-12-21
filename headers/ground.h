#ifndef GROUND_H_INCLUDED
#define GROUND_H_INCLUDED
#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <algorithm>
#include "groundElement.h"
#include "istream"
#include <iostream>
#include <istream>
class monster;
class amulet;
class smartMonster;
class blindMonster;
class wall;
class position;
class adventurer;
class character;
class viewManager;



using std::string;


// TERRAIN DE JEU

class ground
{
    public:
        ground(); 
        ground(int nbl,int nbc); 
        void buildGround();
        void importGround(std::istream &ist);

        char typeOf(int indice) const; 


       
        int getNbColumns() const; 
        int getNbLines() const;   
        int getNbTotalElmts() const; 

        void addElementToGround(std::unique_ptr<groundElement> element); 
        void removeElement(int indice); 
        
        //test ok
        void setSize(int length,int width);  

    private:
        int d_nbLines; 
        int d_nbColumns; 

      std::vector<std::unique_ptr<groundElement>> d_groundElementsTab;

};




#endif //GROUND_H_INCLUDED