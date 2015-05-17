#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "Nav.h"
#include "Intro.h"
#include "RuleOne.h"
#include "RuleTwo.h"
#include "RuleThree.h"
#include "RuleFOur.h"
#include "RuleFive.h"
#include "RuleSix.h"
#include "RuleSeven.h"
#include "RuleEight.h"
#include "RuleNine.h"
#include "RuleTen.h"
#include "Extra.h"
#include "About.h"

class ofApp : public ofBaseApp{

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
     void enableScene(int index);
    
  
    
    baseScene  * scenes[13];
    int currentScene;
    
  
    int _scene;
    Nav nav;
		
};
