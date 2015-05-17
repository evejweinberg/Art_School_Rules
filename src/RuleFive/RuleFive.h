#pragma once
//#ifndef _TEST_APP
//#define _TEST_APP


#include "ofMain.h"
#include "particleFive.h"
#include "noiseFieldFive.h"
#include "baseScene.h"

class RuleFive : public baseScene{
    
 
    
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased (int key);
    
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased();
    
     ofImage Nav;
    ofImage Be, tobe, FollowMe;
  
    
    // let's make a vector of them
    vector <particleFive> particleFives;
    
    noiseFieldFive NF;
    
    bool bPressed;
    
    ofColor colors[12];
    
    ofPoint pos;
    int Artw;
    int Arth;
    float vx;
    float vy;
    
    
    
    
			 
    
};

//#endif

