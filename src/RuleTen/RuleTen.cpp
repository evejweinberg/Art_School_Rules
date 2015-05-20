#include "RuleTen.h"

void RuleTen::reset(){
    float x=ofGetWidth()-500;       // set X and Y outside of the for loop (see above)
    float y = 140;
    
    
//    for (int i = 0; i < 8; i++){
//        ofSetLineWidth(LineWeight[i]);
//    }
    
//    string name;
//    ofxPanel WAVE;
    
    for (int i = 0; i < 8; i++){
     
       
        radius[i].set("Radius Size", ofRandom(20,200), 20, 300);
        amplitude[i].set("Amplitude",0.01f, 0.01f, 0.2f);
        peaks[i].set("Number of Peaks",50, 0, 100);
        noiseModFactor[i].set("Animation", 0.0, 0.0, 5.0);
        velocity[i].set("Rotation Speed", 0.1f, 0.01f, 1.0f);
        LineWeight[i].set("Line Weight", 2, 2, 20);
            }

    
}

//--------------------------------------------------------------
void RuleTen::setup(){
    
    
    
    colors[0].set(224,103,99); //coral
    colors[1].set(140,207,160); //green
    colors[2].set(98,196,215); //teal
    colors[3].set(243,167,153); //salmon
    colors[4].set(236,214,95); //yellow
    colors[5].set(150,107,138); //purple
    colors[6].set(91,116,183); //drkblue
    
    Break.loadImage("RuleTenBreak.png");
    YouCan.loadImage("YouCan.png");
    IntroBlack.loadFont("Intro Black.otf", 52); //font size
    
    string name;
    ofxPanel WAVE;
    
    
    float x=ofGetWidth()-500;       // set X and Y outside of the for loop (see above)
    float y = 140;
    for (int i = 0; i < 8; i++){
        name = "WAVE " + ofToString(i);
   
        panels[i].setup(name, "settings" + ofToString(i) + ".xml", x, y);
        panels[i].add(radius[i].set("Radius Size", ofRandom(20,200), 20, 300));
        panels[i].add(amplitude[i].set("Amplitude",0.01f, 0.01f, 0.2f));
        panels[i].add(peaks[i].set("Number of Peaks",50, 0, 100));
        panels[i].add(noiseModFactor[i].set("Noise", 0.0, 0.0, 5.0));
        panels[i].add(velocity[i].set("Velocity", 0.1f, 0.01f, 1.0f));
        panels[i].add(LineWeight[i].set("Line Weight", 2, 2, 20));
        y += 140;
        if ( y > 600){
            x=ofGetWidth()-280; //scoot the 2nd column to the left
            y = 140;
        }
    }
    
    
    
    ofBackground(0);
    
}




//--------------------------------------------------------------
void RuleTen::update(){
    
}

//--------------------------------------------------------------
void RuleTen::draw(){
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
    
    //------------------- start drawing ------------------------------------
  
    ofNoFill();
    int width;
    float resolution = 1000;
    ofPushMatrix();
     ofTranslate(570,450);
  
    
    for (int j = 0; j < 8; j++) {
    
        
        ofBeginShape();
         ofSetColor(colors[j]);
        ofSetLineWidth(LineWeight[j]);
        
       
        for(int i=0; i<=resolution; i++) {
            
            float t = i/resolution;
            
            float xraw = sin(t*TWO_PI);
            float yraw = cos(t*TWO_PI);
            
            float displaceNoiseMod = ofNoise(xraw+ofGetElapsedTimef(), yraw+ofGetElapsedTimef()) * radius[j];
            displaceNoiseMod*=noiseModFactor[j].get();
            
            float wave = (displaceNoiseMod+radius[j]) * amplitude[j] * sin(t*TWO_PI*peaks[j] + ofGetFrameNum()*velocity[j])  ;
    
            float x = (radius[j]+wave) * xraw;
            float y = (radius[j]+wave) * yraw;
            
            ofCurveVertex(x, y);
          
        
        }
         ofEndShape();
    }
    
        ofPopMatrix();

        for (int i = 0; i < 8; i++){
            panels[i].draw();
        }
    ofPushMatrix();
    ofRotate(-9);
    ofSetColor(73,66,54); //brown
    Break.draw(10,90,700/1.2,181/1.2);
    ofPopMatrix();
    YouCan.draw(1000, 745, 289,103);
    

    
}




//--------------------------------------------------------------
void RuleTen::keyPressed(int key){
    
}

//--------------------------------------------------------------
void RuleTen::keyReleased(int key){
    
}

//--------------------------------------------------------------
void RuleTen::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void RuleTen::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void RuleTen::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void RuleTen::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void RuleTen::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void RuleTen::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void RuleTen::dragEvent(ofDragInfo dragInfo){ 
    
}
