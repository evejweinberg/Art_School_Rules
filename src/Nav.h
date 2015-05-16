#pragma once

#include "ofMain.h"
#include "baseScene.h"

class Nav : public baseScene {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofColor colors[11];
    
    
    char eventString[255];  // when do i use these floats?
    char eventStringB[255];  // when do i use these floats?
    char timeString[255];   // whats a char?
    
    unsigned long last;
    int counter;
    int Myradius;
    
    
    string str = "icon";
    ofImage icon[3];
    ofPoint pos;
    
    float radius = 15;
    
    ofTrueTypeFont IntroBlack;
    
    int setActiveScene =0;
    int circlesTotal = 13;
    int ballclicked =12;
   
		
};
