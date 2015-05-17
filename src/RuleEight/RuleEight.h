#pragma once

#include "ofMain.h"
#include "baseScene.h"


class RuleEight : public baseScene{

	public:
		void setup();
		void update();
		void draw();

    void reset();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void drawAnalyze(float xPos, float yPos, float scale);
    
    ofImage atthesametimebrown;
    ofImage DontTrybrown;
    ofImage RuleEightAnalyze;
    ofImage theyareblue;
    ofImage theyaretan;
    ofTrueTypeFont 	IntroBlack;
    char RuleEightCreate[255];
    
    ofColor salmon;
    ofColor tan;
    ofColor brown;
    
    float RuleEightLeftVertex, RuleEightRightVertex, fromcenterdistance, leftYTarget, rightYTarget;

    
		
};
