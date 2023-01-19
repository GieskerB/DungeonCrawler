#ifndef BLOCK_HPP
#define BLOCK_HPP

//#include <algoviz/SVG.hpp>
#include "SVG.hpp"

class Block: public Image{
    private:
        bool isWalkable;
        int upperLeftCornerX, upperLeftCornerY;
    
    public:
        Block();

        Block(int x, int y, int size, bool isWalkable, string path, SVG *world);
    
        bool getIsWalkable();

        int getUpperLeftCornerX();

        int getUpperLeftCornerY();

        int getSize();

};


#endif 
