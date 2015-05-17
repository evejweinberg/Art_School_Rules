#include "Intro.h"

//--------------------------------------------------------------
void Intro::setup(){
    Title.loadImage("Title.png");

}

//--------------------------------------------------------------
void Intro::update(){

}

//--------------------------------------------------------------
void Intro::draw(){
    
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
    Title.draw(0,0);

}

//--------------------------------------------------------------
void Intro::keyPressed(int key){

}

//--------------------------------------------------------------
void Intro::keyReleased(int key){

}

//--------------------------------------------------------------
void Intro::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void Intro::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Intro::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void Intro::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Intro::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Intro::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Intro::dragEvent(ofDragInfo dragInfo){ 

}
