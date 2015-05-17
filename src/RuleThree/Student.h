

#ifndef __RuleThree__Student__
#define __RuleThree__Student__

#include "ofMain.h"

#include <stdio.h>


class Student{
    
    
    public :
    void setup(float _x, float _y, string fileName);
    void update(float _x, float _y, int _dim);
    void draw();
//  void draw(float _x, float _y, int _dim);
    void moveTowards( float xTarget, float yTarget);

    
    
    float quadrant;
    float image;
    float rotation;
    float x;
    float y;
    float u;
    float v;
    float speedY; // speed and direction, do I need this?
    float speedX;
    int dim;      // size
    float startpt;
    float endpt;
    float varDistance;
    float varSpeedX;
    
    ofPoint stopPoint;
    
    ofColor color; // I make this a HSB spectrum in student.cpp
    
    ofImage studentA, studentB, studentC, studentD, studentE, studentF, img;


    
    
    Student(); // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
    
private: 

};



#endif 

