#ifndef BLOCK_CPP
#define BLOCK_CPP

#include "../includes/Block.hpp"


Block::Block(){
    this->isWalkable = false;
    this->upperLeftCornerX = 0;
    this->upperLeftCornerY = 0;
}

Block::Block(int x, int y, int size, bool isWalkable, string path, SVG *world) : Image(path, x + (size/2), y + (size/2), size, size, world) {
    this->isWalkable = isWalkable;
    this->upperLeftCornerX = x;
    this->upperLeftCornerY = y;
}
    
bool Block::getIsWalkable(){
    return this->isWalkable;
}

int Block::getUpperLeftCornerX(){
    return this->upperLeftCornerX;
}

int Block::getUpperLeftCornerY(){
    return this->upperLeftCornerY;
}

int Block::getSize(){
    return this->w;
}



#endif 
