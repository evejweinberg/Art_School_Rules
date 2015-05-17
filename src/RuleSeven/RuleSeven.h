#pragma once

#include "ofMain.h"
#include "baseScene.h"



typedef struct {
    
    float timePct; // pct is based on movie position;
    ofPoint pos;
    
} timePoint;

class timeStroke {
public:
    void addPoint(float pct, ofPoint pos){
        timePoint temp;
        temp.timePct = pct;
        temp.pos = pos;
        pts.push_back(temp);
    }
    
    void draw(float pct){
        
        if (pts.size() > 1){
            for (int i = 0; i < pts.size()-1; i++){
                if (pts[i].timePct < pct && pts[i+1].timePct < pct){
                    ofLine(pts[i].pos, pts[i+1].pos);
                }
            }
        }
    }
    
    vector < timePoint > pts;
    
};



class RuleSeven : public baseScene{

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
    
    
    ofVideoPlayer scribbles;
    ofVideoPlayer videoone, videotwo, videothree, videofour, videofive, videosix, videoseven, videoeight;
    
    ofTrueTypeFont 	IntroBlack;
    ofTrueTypeFont 	IntroBlackLrg;
    char ThereisOnly[255];
    char WORK [255];
    char RuleIs [255];
    ofColor salmon;
    ofColor tan;
    ofColor yellow;
    ofColor brown;
    ofColor green;
    ofColor royal;
    ofColor blue;
    ofColor pink;
    
 
    ofImage ifyouwork, Inst;
    ofImage allofthetime;
    ofImage itspeople, tosomething, whoeventually, itwilllead;
    

 
    
    timeStroke TS;
    vector < timeStroke > strokes;
    
    		
};


