#pragma once

#include "ofMain.h"
#include "baseScene.h"

class RuleOne : public baseScene{

	public:
		void setup();
		void update();
		void draw();
    void reset();

        void enable();
        void disable();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofTrueTypeFont 	IntroBlack;
    char letterT[255];
    char letterR[255];
    char letterU[255];
    char letterS[255];
    char letterT2[255];
    ofImage RuleOneeverything, Zach, Inst;
    int moveup;
    
    ofColor salmon;
    ofColor tan;
    ofColor yellow;
    ofColor brown;
    ofColor green;
    ofColor royal;
    ofColor blue;
    ofColor pink;
    ofImage Nav;
    
    float intalpha, letterheight, moveZach;
		
};
