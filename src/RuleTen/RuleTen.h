#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "baseScene.h"


class RuleTen : public baseScene{
    
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
    void enable();
    void disable();
    
    
    ofxPanel panels[8];
    ofParameter <int> peaks[8];
    ofParameter <float> amplitude[8];
    ofParameter <float> radius[8];
    ofParameter <float> noiseModFactor[8];
    ofParameter <float> velocity[8];
    ofParameter <float> LineWeight[8];
    
    
    
    
    ofTrueTypeFont 	IntroBlack;
    ofTrueTypeFont 	IntroBlackLrg;
    char ThereisOnly[255];
    char WORK [255];
    ofImage Break, YouCan;
    
    ofColor colors[7];
    ofImage Nav;
    

    
    
    
};
