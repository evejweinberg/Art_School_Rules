#include "Extra.h"

//--------------------------------------------------------------
void Extra::setup(){
    
    hints.loadImage("Hints.png");

}

//--------------------------------------------------------------
void Extra::update(){

}

//--------------------------------------------------------------
void Extra::draw(){
    
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
    hints.draw(0,0);

}

//--------------------------------------------------------------
void Extra::keyPressed(int key){

}

//--------------------------------------------------------------
void Extra::keyReleased(int key){

}

//--------------------------------------------------------------
void Extra::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void Extra::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Extra::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void Extra::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Extra::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Extra::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Extra::dragEvent(ofDragInfo dragInfo){ 

}
