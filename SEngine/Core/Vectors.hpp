//
//  Vectors.hpp
//  SEngine
//
//  Created by Sam cyx on 2021/9/5.
//

#ifndef Vectors_hpp
#define Vectors_hpp

#include <stdio.h>


struct Vector2 {
public:
    float x, y;

    Vector2(): x(), y(){}
    Vector2(float a, float b): x(a), y(b){}
};
struct Vector3 {
public:
    float x, y, z;

    Vector3(): x(), y(), z(){}
    Vector3(float a, float b, float c): x(a), y(b), z(c){}
};
//
//Vector2 operator +(Vector2 a, Vector2 b){
//    float tmpx = a.x + b.x;
//    float tmpy = a.y + b.y;
//    return Vector2(tmpx, tmpy);
//}

#endif /* Vectors_hpp */
