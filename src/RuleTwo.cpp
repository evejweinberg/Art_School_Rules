#include "RuleTwo.h"

//--------------------------------------------------------------
void RuleTwo::setup(){
    
    
    
    colors[0].set(224,103,99); //coral
    colors[1].set(140,207,160); //green
    colors[2].set(98,196,215); //teal
    colors[3].set(243,167,153); //salmon
    colors[4].set(236,214,95); //yellow
    colors[5].set(150,107,138); //purple
    colors[6].set(91,116,183); //drkblue
    
    Head.loadImage("Head.png");
    Ring.loadImage("Circle.png");
    PullEverything.loadImage("PullEverything.png");
    GeneralDuties.loadImage("GeneralDuties.png");
    Inst.loadImage("Inst_RuleTwo.png");
    
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    
    string name;
    for (int i = 0; i < 8; i++){
        opactity[i] = 0;
        name = "Art" + ofToString(i) + ".png";
        Art[i].loadImage(name);
        cout << name << endl;

        }

    
    for (int i = 0; i < 8; i++){ //draw all 8 particleRuleTwos, set their initial condition
        particleRuleTwo myparticleRuleTwo;

      if (i == 0){
            myparticleRuleTwo.setInitialCondition(850,700,0,0);
        }else{
          myparticleRuleTwo.setInitialCondition(ofRandom(100,800) + 100*cos(i/8.0*TWO_PI),(ofRandom(100,800) + 100  *sin(i/8.0 *TWO_PI)),0,0);
        }
        particleRuleTwos.push_back(myparticleRuleTwo);
    }
    
    for (int i = 0; i < 8; i++){  //load the particleRuleTwo pngs
        particleRuleTwos[i].myTeachers.loadImage("picture_" + ofToString(i) + ".png");
    }
    
    particleRuleTwos[0].bFixed = true;


    
    for (int i = 1; i < particleRuleTwos.size(); i++){
        springRuleTwo myspringRuleTwo;
        myspringRuleTwo.distance		= 200;
        myspringRuleTwo.springRuleTwoiness	= 0.05f;
        myspringRuleTwo.particleRuleTwoA = & (particleRuleTwos[0]); //is this my main/center particleRuleTwo?
        myspringRuleTwo.particleRuleTwoB = & (particleRuleTwos[i]);
        springRuleTwos.push_back(myspringRuleTwo);
    }


}

void RuleTwo::disable() {
    enabled = false;
    for (int i = 0; i < 7; i++){
         opactity[i] = 0.1;
    }
    
}

void RuleTwo::enable() {
    enabled = true;
    
}

//--------------------------------------------------------------
void RuleTwo::update(){
    
    
    for (int i = 0; i < particleRuleTwos.size(); i++){
        particleRuleTwos[i].resetForce();
    }
    
    for (int i = 0; i < particleRuleTwos.size(); i++){
        particleRuleTwos[i].addRepulsionForce(ofGetMouseX(), ofGetMouseY(), 200, 1.0f);
        for (int j = 0; j < i; j++){
            particleRuleTwos[i].addRepulsionForce(particleRuleTwos[j], 20, 0.03);
            }
        }
    
    for (int i = 0; i < springRuleTwos.size(); i++){
        springRuleTwos[i].update();
        }
    
    
    for (int i = 0; i < particleRuleTwos.size(); i++){
        particleRuleTwos[i].addDampingForce();
        particleRuleTwos[i].update();
        }


}

//--------------------------------------------------------------
void RuleTwo::draw(){
    
//------draw gridded paper and type--------------------
    ofBackground(255);
    ofSetColor( ofColor::lightBlue);
    ofSetLineWidth(1);
    for (int i = 0; i < ofGetWidth(); i = i + 20){
        ofLine(i,0,i, ofGetHeight());
        }
    for (int i = 0; i < ofGetHeight(); i = i + 20){
        ofLine(0, i, ofGetWidth(), i);
        }
    ofSetColor(76,68,56);
    GeneralDuties.draw(450,390,435,53);
    PullEverything.draw(530,450,426,117);
    
    ofSetColor(255);
    Inst.draw(10,10);

    
    
    
//----------variables for circles------------------------------------------
    
    int opacityPressed;
    int circleRad = 170;
    int FillCircleRad = circleRad-3;
    
    for (int i = 0; i < 7; i++){
        bool bAnyNotInMe = false;
        for (int j = 0; j < particleRuleTwos.size(); j++){
            if (  (CirclePos[i] - particleRuleTwos[j].pos).length() > FillCircleRad){
                bAnyNotInMe = true;
            }
            
//            if (bAnyNotInMe){
//                opactity[i] = 0.99 * opactity[i] + 0.01 * 0.0;
//            }
            else {
                opactity[i] = 0.995 * opactity[i] + 0.005 * 255.0;
            }
        }
    }
    

    
    sin(ofGetElapsedTimef()); // moves from -1 and 1 every 2Pi seconds
    float sinValue = sin(ofGetElapsedTimef()*2);
    float sinValueB = sin(ofGetElapsedTimef()*1.5);
    float cosinValue = cos(ofGetElapsedTimef()*2);
    
   
    CirclePos[0].x =490+sinValue*27; //coral
    CirclePos[0].y =690+cosinValue*17;
    CirclePos[1].x =210+sinValueB*17; //green
    CirclePos[1].y =290+cosinValue*17;
    CirclePos[2].x =900+sinValue*27; //teal
    CirclePos[2].y =200+cosinValue*27;
    CirclePos[3].x =1140+sinValue*27; //salmon
    CirclePos[3].y =630+cosinValue*-37;
    CirclePos[4].x =1200+sinValueB*27; //yellow
    CirclePos[4].y =320+cosinValue*-37;
    CirclePos[5].x =170+sinValueB*27; //purple
    CirclePos[5].y =600+cosinValue*-37;
    CirclePos[6].x =530+sinValue*27; //drk blue
    CirclePos[6].y =180+cosinValue*17;
  

    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for (int i = 0; i < 7; i++){ //draw the rings
        ofSetColor(colors[i]);
        Ring.draw(CirclePos[i].x,CirclePos[i].y,circleRad*2,circleRad*2);
        ofSetColor(colors[i].r, colors[i].g, colors[i].b, opactity[i]);
        ofCircle(CirclePos[i],FillCircleRad);
        ofSetColor(255);
        Art[i].draw(CirclePos[i].x,CirclePos[i].y,circleRad*2,circleRad*2);
        }
    
    ofSetRectMode(OF_RECTMODE_CORNER);
   

//---------------springRuleTwos and  particleRuleTwos----------------
    ofSetColor(76,68,56);
    for (int i = 0; i < particleRuleTwos.size(); i++){
        particleRuleTwos[i].draw();
    }
    
    for (int i = 0; i < springRuleTwos.size(); i++){
        springRuleTwos[i].draw();
    }
    

    
}

//--------------------------------------------------------------
void RuleTwo::keyPressed(int key){
    
    switch (key){
            
        case ' ':
            // reposition everything:
            for (int i = 0; i < particleRuleTwos.size(); i++){
               
                 particleRuleTwos[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
            
            }
            
            break;
    }

}

//--------------------------------------------------------------
void RuleTwo::keyReleased(int key){

}

//--------------------------------------------------------------
void RuleTwo::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void RuleTwo::mouseDragged(int x, int y, int button){
    
    particleRuleTwos[0].pos.set(ofGetMouseX(), ofGetMouseY());



}

//--------------------------------------------------------------
void RuleTwo::mousePressed(int x, int y, int button){
//particleRuleTwos[0].bFixed = true;
}

//--------------------------------------------------------------
void RuleTwo::mouseReleased(int x, int y, int button){
//particleRuleTwos[0].bFixed = false;
}

//--------------------------------------------------------------
void RuleTwo::windowResized(int w, int h){

}

//--------------------------------------------------------------
void RuleTwo::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void RuleTwo::dragEvent(ofDragInfo dragInfo){ 

}
