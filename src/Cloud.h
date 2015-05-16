//
//  Cloud.h
//  RuleNine
//
//  Created by Eve Weinberg on 5/13/15.
//
//

#ifndef __RuleNine__Cloud__
#define __RuleNine__Cloud__

#include <stdio.h>
#include "ofMain.h"


class Cloud {
    
public:
    
    Cloud () {
        cloud.loadImage("cloud.png");
    };
    
    void update(){
        pos.x +=1.5;
        if (pos.x > ofGetWidth()+(ofGetWidth()/3)){ //trying to say that if it goes off screen, write a new one
            pos.x -= (ofGetWidth()+(ofGetWidth()/3)+400);
        }
    };
    
    
    void draw() {
        ofSetColor(192,223,228);
        cloud.draw(pos,190,68); //allocate x and y for later use
   };
    
    ofImage cloud; //allocate space for an image
     ofPoint pos; //define an ofPoint
    
    };
#endif /* defined(__RuleNine__Cloud__) */
