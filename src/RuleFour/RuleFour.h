#pragma once

#include "ofMain.h"
#include "BallDrop.h"
#include "baseScene.h"

#define ARTWORKTOTAL 15

class RuleFour : public baseScene{

	public:
		void setup();
		void update();
		void draw();
    void enable();
    void disable();
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

    
    ofImage Consider, ConsiderFull, Everything, tobe, an, Experiment, InstA;
    ofColor col;
    ofColor color;
  
 
 
    unsigned long last;
    int counter;
    float Myradius;
    
    ofColor salmon;
    ofColor tan;
    ofColor yellow;
    ofColor brown;
    ofColor green;
    ofColor royal;
    ofColor blue;
    ofColor pink;
    ofColor Blue = ofColor :: skyBlue;
    ofColor Aqua = ofColor :: aquamarine;
    ofColor MedAqua = ofColor :: mediumAquaMarine;
    ofColor Salmon = ofColor :: salmon;
    ofColor Gold = ofColor :: gold;
    
    ofColor colors[9];
    vector <BallDrop> allBallsDropping;
    
    ofImage LikeThis[ARTWORKTOTAL];
    string str = "LikeThis";
   
    
    int nextArtwork=0;
    int nextColor=0;
    
		
};
