#include "RuleOne.h"

void RuleOne::reset(){
     moveZach = 220;
    
}

//--------------------------------------------------------------
void RuleOne::setup(){
    
    sprintf(letterT, "T");
    sprintf(letterR, "R");
    sprintf(letterU, "U");
    sprintf(letterS, "S");
    sprintf(letterT2, "T");
    IntroBlack.loadFont("Intro Black.otf", 187); //font size
    Zach.loadImage("Zach.png");
    RuleOneeverything.loadImage("RuleOneeverything.png");
    Inst.loadImage("RuleOne_Inst_Slide.png");
  
    
    salmon.setHsb(0,140,224);
    tan.setHsb(30,58,234); // (x/360*255, x/100*255, x/100*255)
    brown.setHsb(30,96,63);
    yellow.setHsb(34,150,234);
    green.setHsb(49,127,219);
    royal.setHsb(157,127,181);
    blue.setHsb(133,138,214);
    pink.setHsb(4,43,237);
   
   moveZach = 400;

}




//--------------------------------------------------------------
void RuleOne::update(){
//    Zach.draw(300,300,484,430);

}

//--------------------------------------------------------------
void RuleOne::draw(){
    
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
    
//----------draw ellipses------------------------------
    
    float sinOfTime				= sin( ofGetElapsedTimef() );
    float sinOfTimeMapped		= ofMap( sinOfTime, -1, 1, 0, 255);
    
    float sinOfTime2			= sin( ofGetElapsedTimef() + PI);
    float sinOfTimeMapped2		= ofMap( sinOfTime2, -1, 1, 0, 255);
    

    sin(ofGetElapsedTimef()); // moves from -1 and 1 every 2Pi seconds
    float sinValue = sin(ofGetElapsedTimef()*2);
    ofColor c;
    c.set(ofColor::pink);
    c.lerp( ofColor::blue,  ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 1, true));
    ofSetColor(c);
    ofCircle(610,480+sinValue*17, 5);
    ofCircle(640,480+sinValue*15, 5);
    ofCircle(670,480+sinValue*20, 5);

//----------draw letters-----------------
    moveup = 20;
    ofSetColor(255);
    Inst.draw(540,ofGetHeight()-60);
    
    letterheight = 380- moveup;
    float intalphaMapped = ofMap(moveZach, 20, ofGetWidth()-400, 0, 255);
  
    ofSetColor(224,103,99,intalphaMapped);
    IntroBlack.drawString(letterT, 235,letterheight);
    ofSetColor(245,155,181,intalphaMapped);
    IntroBlack.drawString(letterR, 405,letterheight);
    ofSetColor(200,221,109,intalphaMapped);
    IntroBlack.drawString(letterU, 605,letterheight);
    ofSetColor(98,196,215,intalphaMapped);
    IntroBlack.drawString(letterS, 805, letterheight);
    ofSetColor(245,155,181,intalphaMapped);
    IntroBlack.drawString(letterT2, 1005,letterheight);
    
    
    ofSetColor(brown);
    RuleOneeverything.draw(50,25);

    if (ofGetMousePressed() && ofGetMouseX()>100 && ofGetMouseX()<ofGetWidth()-305){
        moveZach = ofGetMouseX();
         }

    Zach.draw(moveZach-220,434,484/1.1,430/1.1);

   

}

//--------------------------------------------------------------
void RuleOne::keyPressed(int key){

}

//--------------------------------------------------------------
void RuleOne::keyReleased(int key){

}

//--------------------------------------------------------------
void RuleOne::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void RuleOne::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void RuleOne::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void RuleOne::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void RuleOne::windowResized(int w, int h){

}

//--------------------------------------------------------------
void RuleOne::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void RuleOne::dragEvent(ofDragInfo dragInfo){ 

}
