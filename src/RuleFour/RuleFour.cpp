#include "RuleFour.h"

void RuleFour::reset(){
//   allBallsDropping.clear;
}

//--------------------------------------------------------------
void RuleFour::setup(){
    
    ConsiderFull.loadImage("ConsiderFull.png");
    Everything.loadImage("Everything.png");
    tobe.loadImage("tobe.png");
    an.loadImage("an.png");
    Experiment.loadImage("Experiment.png");
    InstA.loadImage("Inst3.png");
  
    
    colors[0].set(224,103,99); //coral
    colors[1].set(140,207,160); //green
    colors[2].set(98,196,215); //teal
    colors[3].set(243,167,153); //salmon
    colors[4].set(236,214,95); //yellow
    colors[5].set(150,107,138); //purple
    colors[6].set(91,116,183); //drkblue
    colors[7].set(148,114,101); // lightbrown
    colors[8].set(200,221,109); //lime
    

    
    string name;
    for (int i = 0; i < ARTWORKTOTAL; i++){
        name = "RuleFour_LikeThis" + ofToString(i) + ".png";
        LikeThis[i].loadImage(name);
        cout << name << endl;
        }
    
    allBallsDropping.resize(10);
    for (int i = 0; i < allBallsDropping.size(); i++) {
        allBallsDropping[i].artwork = &LikeThis[(int)ofRandom(ARTWORKTOTAL)]; //choose random artwork, from the pointer in the balldrop header. The ball has a pointer to an image in the LikeThisArray
        allBallsDropping[i].col = colors[(int)ofRandom(9)]; //grabbing the colors
        allBallsDropping[i].pos = ofPoint(ofRandom(0,ofGetWidth()),ofRandom(0, ofGetHeight())); //first time we call the balls
    }

    Myradius=1.0;

}

void RuleFour::enable(){
    enabled = true;
}

void RuleFour::disable(){
    enabled = false;
    
    
    
}

//--------------------------------------------------------------
void RuleFour::update(){

    ofSetCircleResolution(50);

    
    for (int i = 0; i < allBallsDropping.size(); i++) {
        allBallsDropping[i].update();
        allBallsDropping[i].radius = Myradius;
        

    }


}

//--------------------------------------------------------------
void RuleFour::draw(){
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
    
    ofFill();
    

    //-----------------------bg ball drops----------------------------------------------------------------------

     ofSetColor(255);
     InstA.draw(545,347);
    
    for (int i = 0; i < allBallsDropping.size(); i++) { //drawing all the balls, every frame
        allBallsDropping[i].draw();
    }
    
    ofSetColor(73,66,54); //brown
    ConsiderFull.draw(320,120);


    ofSetColor(255);
   
    
   
    
}



//--------------------------------------------------------------
void RuleFour::keyPressed(int key){
    
    if(key=='s') 
    {
        
        Myradius -= 0.1; //Myradius is defined in header, instantiated in setup to 1
       
        
            }
    
    if(key=='l')
    {
        
        Myradius += 0.1;

    }
    
}

//--------------------------------------------------------------
void RuleFour::keyReleased(int key){

}

//--------------------------------------------------------------
void RuleFour::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void RuleFour::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void RuleFour::mousePressed(int x, int y, int button){
    
    for (int i = 0; i < allBallsDropping.size(); i++) {
        if(allBallsDropping[i].mousePressed(x, y, button)) {
            
            BallDrop ball; //instantiating a new variable 'ball' of the type 'balldrop'

            ball.artwork = &LikeThis[nextArtwork];
            ball.col = colors[nextColor];
            
            nextArtwork++;
            if(nextArtwork >= 15) nextArtwork=0;
            
            nextColor++;
            if(nextColor >= 9) nextColor=0;
            
            ball.pos.set(ofRandom(0,ofGetWidth()), ofRandom(-ball.radius, -ball.radius*10)); //also draw a new ball up top
            
            allBallsDropping.push_back(ball); //add it to the vector of all the balls, push a new element into the vector from the back of it

            
        }
    }
    

}

//--------------------------------------------------------------
void RuleFour::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void RuleFour::windowResized(int w, int h){

}

//--------------------------------------------------------------
void RuleFour::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void RuleFour::dragEvent(ofDragInfo dragInfo){ 

}
