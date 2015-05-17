#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxImageSequence.h"
#include "Cloud.h"
#include "baseScene.h"




class RuleNine : public baseScene{

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
    
  
    ofImage Nav;
    ofVideoGrabber		videoGrabber;
    ofxCvColorImage		colorImg;
    ofxCvGrayscaleImage 	grayImage;
    ofColor myColor;
    ofColor colorvar;
    ofImage art, frame;
    ofImage Mate, Inst;
    ofImage type;
    ofxImageSequence CompyImages;
  
    
    float cloudx;
    float 	counter;
    vector <Cloud> allClouds;

  
};
