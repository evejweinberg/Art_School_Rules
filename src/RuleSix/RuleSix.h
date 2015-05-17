#pragma once

#include "ofMain.h"
#include "particleSix.h"
#include "baseScene.h"

class RuleSix : public baseScene, public ofThread{

	public:
    
    void setup();
    void update();
    void draw();
    void exit();
        void threadedFunction();
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
   
        float           nextLetterTime;
        int             lineCount;
        int             letterCount;
        vector <string> seussLines;
        ofTrueTypeFont 	IntroBlack;
    
    
    vector <string> words;
    int step;
    
    bool bRandomVoice;
    string voice;
    
    vector <particleSix> particleSixs;
    
    int nPtsW;
    int nPtsH;
    ofColor colors[12];
    

};
