#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <SDL_ttf.h>
#include "drawing_object.h"
#include "algorithms.h"

Drawing_Object::Drawing_Object(int height, int coordinate_y, int coordinate_x) : height{height}, coordinate_x{coordinate_x}, coordinate_y{coordinate_y}, animation{false}{
        boxColor(screen, coordinate_x, coordinate_y, coordinate_x + 2, coordinate_y - height * 3, /*0x00C957FF*//*0x228B22FF*/0xFF8C00FF);
}

Drawing_Object::Drawing_Object(Drawing_Object &other) : height{other.getHeight()}, coordinate_x{other.getCoordinateX()}, coordinate_y{other.getCoordinateY()}, animation{other.getAnimation()}{}

int Drawing_Object::getHeight()const{return height;}

int Drawing_Object::getCoordinateX()const{return coordinate_x;}

int Drawing_Object::getCoordinateY()const{return coordinate_y;}

bool Drawing_Object::getAnimation()const{return animation;}

void Drawing_Object::setAnimation(bool animation){
    this -> animation = animation;
}

void Drawing_Object::setPosition(int height, int coordinate_y, int coordinate_x){
    this -> height = height;
    this -> coordinate_x = coordinate_x;
    this -> coordinate_y = coordinate_y;
}

Drawing_Object& Drawing_Object::operator = (Drawing_Object const & other){
    boxColor(screen, coordinate_x, coordinate_y, coordinate_x + 3, coordinate_y - height * 3, 0x000000FF);
    height = other.getHeight();
    boxColor(screen, coordinate_x, coordinate_y, coordinate_x + 3, coordinate_y - height * 3, 0xFF8C00FF);
    if(animation){ /*csak akkor rajzolunk, ha nincs letiltva az animáció*/
        SDL_Delay(1);
        SDL_Flip(screen);
        SDL_PumpEvents();
    }
    return *this;
}

bool operator < (Drawing_Object left, Drawing_Object right){
    /*szövegek és értékek kiírása*/
    char comparisons[10];
    char swaps[10];
    sprintf(comparisons, "%d", comparison_value);
    sprintf(swaps, "%d", swap_value);
    title(comparisons, 500, 10, font, zold);
    boxColor(screen, 480, 10, 580, 50, 0X000000FF);
    title(comparisons, 500, 10, font, zold);
    title(swaps, 700, 10, font, zold);
    boxColor(screen,680,10,780,50, 0X000000FF);
    title(swaps, 700, 10, font, zold);

    if(left.getAnimation() && right.getAnimation()){ /*csak akkor rajzolunk, ha egyik objektumban sincs letiltva az animáció*/
        SDL_Delay(1);
        SDL_Flip(screen);
        SDL_PumpEvents();
    }

    ++comparison_value;

    /*tényleges összehasonlítás*/
    if(left.getHeight() < right.getHeight())
        return true;
    else
        return false;
}

bool operator > (Drawing_Object left, Drawing_Object right){
    /*szövegek és értékek kiírása*/
    char comparisons[10];
    char swaps[10];
    sprintf(comparisons, "%d", comparison_value);
    sprintf(swaps, "%d", swap_value);
    title(comparisons, 500, 10, font, zold);
    boxColor(screen, 480, 10, 580, 50, 0X000000FF);
    sprintf(comparisons, "%d", comparison_value);
    title(comparisons, 500, 10, font, zold);
    title(swaps, 700, 10, font, zold);
    boxColor(screen,680,10,780,50, 0X000000FF);
    title(swaps, 700, 10, font, zold);

    if(left.getAnimation() && right.getAnimation()){ /*csak akkor rajzolunk, ha egyik objektumban sincs letiltva az animáció*/
        SDL_Delay(1);
        SDL_Flip(screen);
        SDL_PumpEvents();
    }

    ++comparison_value;

    /*tényleges összehasonlítás*/
    if(left.getHeight() > right.getHeight())
        return true;
    else
        return false;
}

bool operator <= (Drawing_Object left, Drawing_Object right){
    /*szövegek és értékek kiírása*/
    char comparisons[10];
    char swaps[10];
    sprintf(comparisons, "%d", comparison_value);
    sprintf(swaps, "%d", swap_value);
    title(comparisons, 500, 10, font, zold);
    boxColor(screen, 480, 10, 580, 50, 0X000000FF);
    title(comparisons, 500, 10, font, zold);
    title(swaps, 700, 10, font, zold);
    boxColor(screen,680,10,780,50, 0X000000FF);
    title(swaps, 700, 10, font, zold);

    if(left.getAnimation() && right.getAnimation()){ /*csak akkor rajzolunk, ha egyik objektumban sincs letiltva az animáció*/
        SDL_Delay(1);
        SDL_Flip(screen);
        SDL_PumpEvents();
    }

    ++comparison_value;

    /*tényleges összehasonlítás*/
    if(left.getHeight() <= right.getHeight())
        return true;
    else
        return false;
}
