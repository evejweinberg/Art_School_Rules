

#ifndef __RuleFour__BallDrop__
#define __RuleFour__BallDrop__
#include "ofMain.h"
#include <stdio.h>



class BallDrop {
    
public:
    
    BallDrop() { //this is the setup basically
        hasbeenclicked = false;
        radius = 1;
    };

    void update() {
        if (pos.y > ofGetHeight()+radius){ //if ball goes off screen, redraw a ball
            pos.y = -radius;
            hasbeenclicked = false;
        }
        
        if(!hasbeenclicked) pos.y += 1; //if it has not been clicked add 1 every time
        
    };

    void draw() {
        ofPushStyle();
        
        if(hasbeenclicked) {
            ofSetColor(col);
            ofSetRectMode(OF_RECTMODE_CENTER);
            
            ofPushMatrix();
            ofTranslate(pos);
            ofScale(radius/2, radius/2);
            artwork->draw(0,0);
            ofPopMatrix();
            
        } else {
            
            ofSetColor(224,103,99); //salmon, but could change to ranodom ofSetColor(col);
            ofCircle(pos, 20*radius); // radius is really 'scale factor' radius at 1 os 20px
        }
        
        ofPopStyle();
    };
    
    // Check if click is within radius of ball, set hasbeenclicked and return true if it is
    bool mousePressed(int x, int y, int button) {
        if (pos.distance(ofPoint(x,y)) < 20*radius) return hasbeenclicked = true;
        return false;
    };
    
    //define variables, like in normal header files
    ofPoint pos;
    float radius;
    bool hasbeenclicked;
    
    
    ofImage * artwork; //a pointer to an image
    ofColor col;
};


#endif /* defined(__RuleFour__BallDrop__) */
