#include "About.h"

//--------------------------------------------------------------
void About::setup(){
      about.loadImage("About.png");

}

//--------------------------------------------------------------
void About::update(){

}

//--------------------------------------------------------------
void About::draw(){
    
    //BG------white paper with light blue gridded lines--------------------
    ofBackground(255);
    ofSetColor( ofColor::lightBlue);
    ofSetLineWidth(1);
    for (int i = 0; i < ofGetWidth(); i = i + 20){
        ofLine(i,0,i, ofGetHeight());
        
    }
    
    for (int i = 0; i < ofGetHeight(); i = i + 20){
        ofLine(0, i, ofGetWidth(), i);
    }

    ofSetColor(255);
    about.draw(0,0);

}

//--------------------------------------------------------------
void About::keyPressed(int key){
    

}

//--------------------------------------------------------------
void About::keyReleased(int key){

}

//--------------------------------------------------------------
void About::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void About::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void About::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void About::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void About::windowResized(int w, int h){

}

//--------------------------------------------------------------
void About::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void About::dragEvent(ofDragInfo dragInfo){ 

}
