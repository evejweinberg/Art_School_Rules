
#include "Student.h"

Student::Student(){
}

void Student::setup(float _x, float _y, string fileName){
    
    varSpeedX = ofRandom(.97,.999);

    
        x = _x; //why do we do this?
        y = _y;
        
        speedX = ofRandom(-1,1); //look below for where we use this
        speedY = ofRandom(-1,1);
        rotation = ofRandom(-10,10);
        color.setHsb(ofRandom(255),ofRandom(100,110),ofRandom(200,220));
    
    img.loadImage(fileName);
    cout << fileName  << " " << img.width << endl;

   
    varDistance = ofRandom(300,900);
    

    }





void Student::moveTowards( float xTarget, float yTarget){
   
    

    x = varSpeedX * x + (1-varSpeedX) * stopPoint.x;
    y = varSpeedX * y + (1-varSpeedX) * stopPoint.y;

  
}








void Student::update(float _x, float _y, int _dim){
    

}

void Student::draw(){
    
    ofPushStyle();
    ofPushMatrix();
    
    ofSetColor(color);
    
img.draw(x,y,119,183);

    
    ofPopMatrix();
    ofPopStyle();

}

    
    

