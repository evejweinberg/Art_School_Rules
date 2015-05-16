//
//  Mate.h
//  RuleNine
//
//  Created by Eve Weinberg on 5/13/15.
//
//

#ifndef __RuleNine__Mate__
#define __RuleNine__Mate__

#include <stdio.h>
#include "ofMain.h"


class Mate {
    
public:
    
    Mate () {
        Mateimg.loadImage("Mate.png");

    };
    
    void update(){
    };
    
    void draw() {
        
        ofPushMatrix();
        ofPushStyle();
        ofRectMode(OF_RECTMODE_CENTER);
        ofRotate(50*TWO_PI*ofGetElapsedTimef());
        Mateimg.draw(400,400,245/2,450/2);
        ofPopMatrix();
        ofPopStyle();
        
    };
    
    
        ofImage Mateimg;
      
};



#endif /* defined(__RuleNine__Mate__) */
