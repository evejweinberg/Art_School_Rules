#include "Nav.h"

//--------------------------------------------------------------
void Nav::setup(){
    
    colors[0].set(224,103,99); //coral
    colors[1].set(140,207,160); //green
    colors[2].set(98,196,215); //teal
    colors[3].set(243,167,153); //salmon
    colors[4].set(236,214,95); //yellow
    colors[5].set(150,107,138); //purple
    colors[6].set(91,116,183); //drkblue
    colors[7].set(200,221,109); //lime
    colors[8].set(211,137,104); // sunburn
    colors[9].set(224,103,99); //pinkagain
    colors[10].set(85,85,140); //reallydarkblue
    
    float xPos = ofGetMouseX();
    
    IntroBlack.loadFont("Intro Black.otf", 15);
    
    string name;
    for (int i = 0; i < 3; i++){
        name = "Navicons-0" + ofToString(i) + ".png";
        icon[i].loadImage(name);
        cout << name << endl;
    }


}

//--------------------------------------------------------------
void Nav::update(){
    

}

//--------------------------------------------------------------
void Nav::draw(){
    
   
    
    for (int navcirc = 0; navcirc < circlesTotal; navcirc++) {
        ofSetColor(colors[navcirc]);
        pos.set(ofGetWidth()-37,-100+ofGetHeight()-50*navcirc);
        if (navcirc > 10){
            colors[navcirc] = colors[navcirc % 10];
        }
        
        if (pos.distance(ofPoint(ofGetMouseX(),ofGetMouseY())) < 15 || ballclicked == navcirc){
            radius = 25;
            
        } else {
            radius = 15;
        }
    
        
        
        
        
        ofCircle(pos,radius);
        int currentCircle = circlesTotal - navcirc;
        
        
        ofPushMatrix();
        
        
        ofTranslate(ofGetWidth()-37, -93+ofGetHeight());
        ofSetColor(73,66,54); //brown
        if (navcirc > 1 && navcirc < 12) {
            
            int swidth = IntroBlack.stringWidth(ofToString(currentCircle-1));
            IntroBlack.drawString(ofToString(currentCircle-1), -swidth/2, -50*navcirc);
            
        }
        
        ofPopMatrix();
        
        
    }
    
    
    
    icon[1].draw(ofGetWidth()-47, ofGetHeight()-709); //house
    icon[0].draw(ofGetWidth()-47, ofGetHeight()-109); //?
    icon[2].draw(ofGetWidth()-47, ofGetHeight()-158); // +

}

//--------------------------------------------------------------
void Nav::keyPressed(int key){
    

}

//--------------------------------------------------------------
void Nav::keyReleased(int key){

}

//--------------------------------------------------------------
void Nav::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void Nav::mouseDragged(int x, int y, int button){

}


int Nav::check_mouse_nav(int x, int y){
    int cur_scene=-1;
    cout<<"hey mouse was clicked"<<endl;
    for (int navcirc = 0; navcirc < circlesTotal; navcirc++) {
        pos.set(ofGetWidth()-37,-100+ofGetHeight()-50*navcirc);
        
        if (pos.distance(ofPoint(x,y)) < radius){
            currentScene = circlesTotal-navcirc-1;
            cur_scene=currentScene;
            ballclicked = navcirc;
            cout<<ballclicked<<endl;
            
            
            
        }
    }
      return cur_scene;
}

void Nav::mousePressed(int x, int y, int button){
    cout<<"hey mouse was clicked"<<endl;
    for (int navcirc = 0; navcirc < circlesTotal; navcirc++) {
        pos.set(ofGetWidth()-37,-100+ofGetHeight()-50*navcirc);
        
        if (pos.distance(ofPoint(x,y)) < radius){
            currentScene = circlesTotal-navcirc-1;
           
            ballclicked = navcirc;
             cout<<ballclicked<<endl;
          

       
        
        }
    }
//    return currentScene;
}

//--------------------------------------------------------------
void Nav::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Nav::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Nav::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Nav::dragEvent(ofDragInfo dragInfo){ 

}
