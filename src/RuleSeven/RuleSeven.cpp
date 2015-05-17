#include "RuleSeven.h"
#include "ofMain.h"

void RuleSeven::reset(){
    
}


//--------------------------------------------------------------
void RuleSeven::setup(){
    salmon.setHsb(0,140,224);
    tan.setHsb(30,58,234); // (x/360*255, x/100*255, x/100*255)
    brown.setHsb(30,96,63);
    yellow.setHsb(34,150,234);
    green.setHsb(49,127,219);
    royal.setHsb(157,127,181);
    blue.setHsb(133,138,214);
    pink.setHsb(4,43,237);
    sprintf(WORK, "WORK");
    IntroBlackLrg.loadFont("Intro Black.otf", 70); //font size
    sprintf(ThereisOnly, "THE ONLY");
    sprintf(RuleIs, "RULE IS");
    
    IntroBlack.loadFont("Intro Black.otf", 50); //font size
    Inst.loadImage("Inst_RuleSeven.png");
  
    
    videoone.loadMovie("RuleSevenVideoOne.mov");
    videoone.setLoopState(OF_LOOP_NORMAL);
    videoone.play();
    
    videotwo.loadMovie("RuleSevenVideoFour.mov");
    videotwo.setLoopState(OF_LOOP_NORMAL);
    videotwo.play();
    
    
    videothree.loadMovie("RuleSevenVideoFour.mov");
    videothree.setLoopState(OF_LOOP_NORMAL);
    videothree.play();
    
    videofour.loadMovie("RuleSevenVideoSeven.mov");
    videofour.setLoopState(OF_LOOP_NORMAL);
    videofour.play();
    
    videofive.loadMovie("RuleSevenVideoFive.mov");
    videofive.setLoopState(OF_LOOP_NORMAL);
    videofive.play();
    
    videosix.loadMovie("RuleSevenVideoSix.mov");
    videosix.setLoopState(OF_LOOP_NORMAL);
    videosix.play();
    
    videoseven.loadMovie("RuleSevenVideoNine.mov");
    videoseven.setLoopState(OF_LOOP_NORMAL);
    videoseven.play();
    
    videoeight.loadMovie("RuleSevenVideoSeven.mov");
    videoeight.setLoopState(OF_LOOP_NORMAL);
    videoeight.play();
    

    
    allofthetime.loadImage("allofthetime.png");
    ifyouwork.loadImage("ifyouwork.png");
    itwilllead.loadImage("itwilllead.png");
    itspeople.loadImage("itspeople.png");
    tosomething.loadImage("toSomething.png");
    whoeventually.loadImage("whoeventually2.png");
    
 



}

//--------------------------------------------------------------
void RuleSeven::update(){
    
   
    videoone.update();
    videotwo.update();
    videothree.update();
    videofour.update();
    videofive.update();
    videosix.update();
    videoseven.update();
    videoeight.update();
    


}

//--------------------------------------------------------------
void RuleSeven::draw(){
    //BG------white paper with light blue gridded lines--------------------
    ofBackground(255);
    ofSetColor( ofColor::lightBlue);
    ofSetLineWidth(1);
    for (int i = 0; i < ofGetWidth(); i = i + 20){
        ofLine(i,0,i, ofGetHeight()); //draw a line at pt1: i,0, pt2: i,get width
        
    }
    for (int i = 0; i < ofGetHeight(); i = i + 20){
        ofLine(0, i, ofGetWidth(), i);
    }

    ofPushMatrix();
    ofTranslate(-30,0);

    ofSetColor(brown);
    ifyouwork.draw(64,160,627/2.5,177/2.5 );
    itwilllead.draw(780,140,221/2,305/2);
    allofthetime.draw(85,605,383/2,231/2);
    itspeople.draw(1035,345,530/2.2,392/2.2);
    tosomething.draw(410,365,368/2,270/2);
    whoeventually.draw(715,570,530/2.05,392/2.05);

    ofSetColor(255);
    Inst.draw(500,ofGetHeight()-115);
    videoone.draw(360,110,330,200); //top left
    videosix.draw(1000,110,330,200); //top right
    videofive.draw(40,330,330,200); //midleft
    videothree.draw(680,330,330,200); //middle right
    videoseven.draw(360,550,330,200); //bottom left
    videofour.draw(1000,550,330,200); //bottom right
    ofPopMatrix();

    

    

    
    // --------------------mesh circle that follows mouse---------------
    ofSetColor(255);
    
    float x = ofGetMouseX()-PI;
    float y = ofGetMouseY()-PI;
    float r = 200;
    
    float scale =  1;
    
    ofPushMatrix();
    ofTranslate(-100,0);
    ofSetColor(brown);
    IntroBlack.drawString(ThereisOnly, ofGetMouseX()+100,ofGetMouseY());
   IntroBlack.drawString(RuleIs, ofGetMouseX()+100,ofGetMouseY()+25);
    IntroBlackLrg.drawString(WORK, ofGetMouseX()+100,ofGetMouseY()+100);
   
    ofPopMatrix();
    
    
    
    
    
    ofPushMatrix();
    ofTranslate(0, 70);

        ofDrawBitmapStringHighlight("video speed: " + ofToString(videoone.getSpeed(), 3), ofPoint(videoone.getWidth() + 250, ofGetHeight()-80), ofColor::yellow, ofColor::brown);
    
    ofPopMatrix();
    
   



}

//--------------------------------------------------------------
void RuleSeven::keyPressed(int key){
    
    if (key == ' '){
        strokes.clear();
        TS.pts.clear();
    }
    
    
    if (key == '+'){
        videoone.setSpeed(videoone.getSpeed()+0.3);
        videotwo.setSpeed(videotwo.getSpeed()+0.3);
        videothree.setSpeed(videothree.getSpeed()+0.3);
        videofour.setSpeed(videofour.getSpeed()+0.3);
        videofive.setSpeed(videofive.getSpeed()+0.3);
        videosix.setSpeed(videosix.getSpeed()+0.3);
        videoseven.setSpeed(videoseven.getSpeed()+0.3);
        videoeight.setSpeed(videoeight.getSpeed()+0.3);
    }
    
    if (key == '-'){
        videoone.setSpeed(videoone.getSpeed()-0.3);
        videotwo.setSpeed(videotwo.getSpeed()-0.3);
        videothree.setSpeed(videothree.getSpeed()-0.3);
        videofour.setSpeed(videofour.getSpeed()-0.3);
        videofive.setSpeed(videofive.getSpeed()-0.3);
        videosix.setSpeed(videosix.getSpeed()-0.3);
        videoseven.setSpeed(videoseven.getSpeed()-0.3);
        videoeight.setSpeed(videoeight.getSpeed()-0.3);    }

}

//--------------------------------------------------------------
void RuleSeven::keyReleased(int key){

}

//--------------------------------------------------------------
void RuleSeven::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void RuleSeven::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void RuleSeven::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void RuleSeven::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void RuleSeven::windowResized(int w, int h){

}

//--------------------------------------------------------------
void RuleSeven::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void RuleSeven::dragEvent(ofDragInfo dragInfo){ 

}
