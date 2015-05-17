#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    scenes[0] = new Intro();
    scenes[1] = new RuleOne();
    scenes[2] = new RuleTwo();
    scenes[3] = new RuleThree();
    scenes[4] = new RuleFour();
    scenes[5] = new RuleFive();
    scenes[6] = new RuleSix();
    scenes[7] = new RuleSeven();
    scenes[8] = new RuleEight();
    scenes[9] = new RuleNine();
    scenes[10] = new RuleTen();
    scenes[11] = new Extra);
    scenes[12] = new About();
    
    currentScene = 0;
    
    for (int i = 0; i < 3; i++){
        scenes[i]->setup();
    }
    
    nav.setup();

}



//--------------------------------------------------------------
void ofApp::update(){
    
   scenes[currentScene]->update();
    
    nav.update();

}

//-----draw the scenes---------------------------------------------------------
void ofApp::draw(){
    
    scenes[currentScene]->draw();
    nav.draw();
    
}

//----------for all numbers check if that number is pressed, if it is then enable the scene--------------------------------------------
void ofApp::keyPressed(int key){
    currentScene++;
    currentScene %= 13;
    scenes[currentScene]->reset();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
   }

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
        nav.mousePressed(x,y,button);
   
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
