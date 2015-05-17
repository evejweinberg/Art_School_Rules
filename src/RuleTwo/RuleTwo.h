#pragma once
#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "particleRuleTwo.h"
#include "springRuleTwo.h"
#include "baseScene.h"

class RuleTwo : public baseScene{

	public:
		void setup();
		void update();
		void draw();
    void reset();

    void disable();
    void enable();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofImage Head;
    ofImage Ring;
    ofImage GeneralDuties;
    ofImage PullEverything, Inst;

  

    ofColor colors[7];
    ofPoint CirclePos[7];
     ofImage Nav;
    
    ofImage Art[7];
    string str = "Art";
    ofImage myImg;
    float opactity[7];
  
    
    
    
    // let's make a vector of the particleRuleTwos
    vector <particleRuleTwo> particleRuleTwos;
    vector <springRuleTwo> springRuleTwos;
    
    
		
};

#endif