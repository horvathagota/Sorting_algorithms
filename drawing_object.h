#ifndef DRAWING_OBJECT_H
#define DRAWING_OBJECT_H

class Drawing_Object{
    int height; /*az érték, ami alapján két ilyen objektumot össze lehet hasonlítani*/
    int coordinate_x, coordinate_y; /*a kirajzolandó téglalap bal alsó sarkának koordinátái*/
    bool animation; /*az animáció engedélyezését vagy letilását ezzel a változóval lehet beállítani*/
public:
    Drawing_Object(int height = 0, int coordinate_y = 0, int coordinate_x = 0);

    Drawing_Object(Drawing_Object &);

    Drawing_Object& operator = (Drawing_Object const &);

    ~Drawing_Object(){}

    int getHeight()const;

    int getCoordinateX()const;

    int getCoordinateY()const;

    bool getAnimation()const;

    void setAnimation(bool animation);

    void setPosition(int height, int coordinate_y, int coordinate_x);
};

bool operator < (Drawing_Object left, Drawing_Object right);

bool operator > (Drawing_Object left, Drawing_Object right);

bool operator <= (Drawing_Object left, Drawing_Object right);

#endif // DRAWING_OBJECT_H
