#pragma once

#include "ofMain.h"
#include "Student.h"
#include "baseScene.h"
#define NSTUDENTS 400 // define the total number of students. Will I do this per quadrant?

class RuleThree : public baseScene{

	public:
		void setup();
		void update();
		void draw();
    
        void disable();
        void enable ();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
    
    //---------------for drawing a line into a shader------------
    ofFbo       lineFbo;
    ofImage     rockImage;
    ofPolyline  line;
    ofShader    shader;
    vector < ofPolyline > myLines;
    

    Student myStudents[NSTUDENTS]; //call the class Student, call it 'myStudent', and i'm not sure what NSTUDENTS is really saying
    
    ofTrueTypeFont 	IntroBlack;
    char ThereisOnly[255];
    ofColor salmon;
    ofColor tan;
    ofColor yellow;
    ofColor brown;
    ofColor green;
    ofColor royal;
    ofColor blue;
    ofColor pink;
    ofImage studentA, studentB, studentC;
    ofImage BGtemp;
    ofImage TaeyoonTeaching;
   
		
};
