#include "RuleThree.h"



void RuleThree::reset(){
    line.clear();
    myLines.clear();

    
    
    for(int i=0; i<NSTUDENTS; i++){ // i've said in .h that NSTUDENTS is 100

        

        float radius = ofRandom(700,2500);      // <---- pick a random distance away from the center
        float angle = ofRandom(0, TWO_PI);     // <---- pick a random angle
        float centerX = ofGetWidth()/2;    // <----- this is the center of the circle x
        float centerY = ofGetHeight()/2;   // <------ also, center of the circle y
        float x = centerX + radius * cos(angle);   // <---- this is using the circle formula we discussed in class
        float y = centerY + radius * sin(angle);

        string fileName;
        float dy =  ofGetHeight()/2 - y;
        float dx = ofGetWidth()/2 - x;
        float angle2 = atan2(dy, dx ) * RAD_TO_DEG;
        
        
        if (angle2 >= 0 && angle2 < 40){
            fileName = "studentD.png";
        } else if (angle2 >= 40 && angle2 < 130){
            fileName = "studentF.png";
        } else if (angle2 >= 130 && angle2 < 180){
            fileName = "studentC.png";
        } else if (angle2 < 0 && angle2 >= -60){
            fileName = "studentB.png";
        } else if (angle2 < -60 && angle2 >= -120){ // -60  --120
            fileName = "studentB.png";
        } else if (angle2 < -120 && angle2 >= -180){
            fileName = "studentE.png";
        }
//        myStudents[i].setupWithoutLoadingImage(x,y);   // <----- now, this is where they should be setup....
        
        myStudents[i].setup(x,y, fileName);   // <----- now, this is where they should be setup....
        
        
        myStudents[i].stopPoint.x = 645 + myStudents[i].varDistance * cos(angle);
        myStudents[i].stopPoint.y = 366 + myStudents[i].varDistance * sin(angle);
    }

    
}
//--------------------------------------------------------------
void RuleThree::setup(){
    
  
    

    //----------------------style sheets--------------------
    salmon.setHsb(0,140,224);
    tan.setHsb(30,58,234); // (x/360*255, x/100*255, x/100*255)
    brown.setHsb(30,96,63);
    yellow.setHsb(34,150,234);
    green.setHsb(49,127,219);
    royal.setHsb(157,127,181);
    blue.setHsb(133,138,214);
    pink.setHsb(4,43,237);
  
    IntroBlack.loadFont("Intro Black.otf", 20); //font size

    TaeyoonTeaching.loadImage("TaeyoonTeaching.png");
    BGtemp.loadImage("BGtemp.png");
    
    //------load class of Students, tell them what position to start in ------------------
    for(int i=0; i<NSTUDENTS; i++){ // i've said in .h that NSTUDENTS is 100
        
        
    float radius = ofRandom(700,2500);      // <---- pick a random distance away from the center
    float angle = ofRandom(0, TWO_PI);     // <---- pick a random angle
    float centerX = ofGetWidth()/2;    // <----- this is the center of the circle x
    float centerY = ofGetHeight()/2;   // <------ also, center of the circle y
    float x = centerX + radius * cos(angle);   // <---- this is using the circle formula we discussed in class
    float y = centerY + radius * sin(angle);
        
        string fileName;
        float dy =  ofGetHeight()/2 - y;
        float dx = ofGetWidth()/2 - x;
        float angle2 = atan2(dy, dx ) * RAD_TO_DEG;
        
        cout << angle2 << endl;
        
        
        if (angle2 >= 0 && angle2 < 40){
            fileName = "studentD.png";
        } else if (angle2 >= 40 && angle2 < 130){
            fileName = "studentF.png";
        } else if (angle2 >= 130 && angle2 < 180){
            fileName = "studentC.png";
        } else if (angle2 < 0 && angle2 >= -60){
                fileName = "studentB.png";
        } else if (angle2 < -60 && angle2 >= -120){ // -60  --120
            fileName = "studentB.png";
        } else if (angle2 < -120 && angle2 >= -180){
            fileName = "studentE.png";
      }
        myStudents[i].setup(x,y, fileName);   // <----- now, this is where they should be setup....
        
        
        myStudents[i].stopPoint.x = 645 + myStudents[i].varDistance * cos(angle);
        myStudents[i].stopPoint.y = 366 + myStudents[i].varDistance * sin(angle);
        

    }

}


//--------------------------------------------------------------
void RuleThree::update(){
    if (ofGetMousePressed()){
        for(int i=0; i<NSTUDENTS; i++){
        myStudents[i].moveTowards(645, 366); //center point of artowkr
        
        }
    }

}

//--------------------------------------------------------------
void RuleThree::draw(){
    
    
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


    ofSetColor(salmon);
    ofSetLineWidth(6);

    for (int i =0; i < myLines.size(); i++) {
        myLines[i].draw();
    }
    
    line.draw();

  
    
    //--------call student class-------------------
    ofSetColor(255);
    for(int i=0; i<NSTUDENTS; i++){
        
        
        int randomX = ofRandom( 0, ofGetWidth() ); //generate a random value bigger than 0 and smaller than our application screen width
        int randomY = ofRandom( 0, ofGetHeight() ); //generate a random value bigger than 0 and smaller than our application screen height
        
        myStudents[i].draw();
    }
    

    ofSetColor(255);
    TaeyoonTeaching.draw(455,242,442,612);


}


//--------------------------------------------------------------
void RuleThree::keyPressed(int key){

}

//--------------------------------------------------------------
void RuleThree::keyReleased(int key){

}

//--------------------------------------------------------------
void RuleThree::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void RuleThree::mouseDragged(int x, int y, int button){
    
       if (ofGetMouseX() > 484 && ofGetMouseX() < 800 && ofGetMouseY() <474 && ofGetMouseY() > 300){
    line.addVertex(x,y);
             }


}


//--------------------------------------------------------------
void RuleThree::mousePressed(int x, int y, int button){
    
    
    line.clear();
    line.addVertex(x,y);
    

}

//--------------------------------------------------------------
void RuleThree::mouseReleased(int x, int y, int button){
    myLines.push_back(line);

}

//--------------------------------------------------------------
void RuleThree::windowResized(int w, int h){

}

//--------------------------------------------------------------
void RuleThree::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void RuleThree::dragEvent(ofDragInfo dragInfo){ 

}
