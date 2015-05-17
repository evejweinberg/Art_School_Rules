#include "RuleSix.h"


void RuleSix::reset(){
    
}

static string voices[24] = {"Agnes", "Albert", "Alex", "Bad News", "Bahh", "Bells", "Boing", "Bruce", "Bubbles", "Cellos", "Deranged", "Fred", "Good News", "Hysterical", "Junior", "Kathy", "Pipe Organ", "Princess", "Ralph", "Trinoids", "Vicki", "Victoria", "Whisper", "Zarvox"};

//--------------------------------------------------------------
void RuleSix::setup(){
    
    colors[0].set(224,103,99); //coral
    colors[1].set(140,207,160); //green
    colors[2].set(98,196,215); //teal
    colors[3].set(243,167,153); //salmon
    colors[4].set(236,214,95); //yellow
    colors[5].set(150,107,138); //purple
    colors[6].set(91,116,183); //drkblue
    colors[7].set(224,103,99); //coral
    colors[8].set(140,207,160); //green
    colors[9].set(202,222,111); //lime
    colors[10].set(148,114,101); //lightbroen
    colors[11].set(75,65,42); //drk brown

    
    IntroBlack.loadFont("Intro Black.otf", 32); //font size
    ofSetFrameRate(12);
    
    nextLetterTime = ofGetElapsedTimef();
    lineCount      = 0;
    letterCount    = 0;
    
    // this is our buffer to stroe the text data
    ofBuffer buffer = ofBufferFromFile("Nothing.txt");
    
    if(buffer.size()) {
        
        // we now keep grabbing the next line
        // until we reach the end of the file
        while(buffer.isLastLine() == false) {
            
            // move on to the next line
            string line = buffer.getNextLine();
            
            // copy the line to draw later
            // make sure its not a empty line
            if(line.empty() == false) {
                seussLines.push_back(line);
            }
            
            // print out the line
            cout << line << endl;
            
        }
        
    }
    
    voice = "Agnes";
    bRandomVoice = false;
    
    // load the lyrics from a text file and split them
    // up in to a vector of strings
    string lyrics = ofBufferFromFile("Nothing.txt").getText();
    step = 0;
    words = ofSplitString(lyrics, " ");
    
    // we are running the systems commands
    // in a sperate thread so that it does
    // not block the drawing
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    
    nPtsW = 20;
    nPtsH = 20;
    
    for (int i = 0; i < nPtsW; i++){
        for (int j = 0; j < nPtsH; j++){
            
            float x = ofMap(i,0,nPtsW, 0,ofGetWidth());
            float y = ofMap(j,0,nPtsH, 0,ofGetHeight());
            particleSix myparticleSix;
            myparticleSix.setInitialCondition(x,y,0,0);
            // more interesting with diversity :)
            // uncomment this:
            //myparticleSix.damping = ofRandom(0.01, 0.05);
            particleSixs.push_back(myparticleSix);
        }
    }




}

//--------------------------------------------------------------
void RuleSix::threadedFunction() {
    
    while (isThreadRunning()) {
        
        
        // call the system command say
        
#ifdef TARGET_OSX
        string cmd = "say -v "+voice+" "+words[step]+" ";   // create the command
        system(cmd.c_str());
#endif
#ifdef TARGET_WIN32
        string cmd = "data\\SayStatic.exe "+words[step];   // create the command
        cout << cmd << endl;
        system(cmd.c_str());
#endif
        
        // step to the next word
        step ++;
        step %= words.size();
        
        // slowdown boy
        ofSleepMillis(10);
    }
}

void RuleSix::enable() {
    enabled = true;
    startThread();
}

void RuleSix::disable() {
    enabled = false;
    stopThread();
}


//--------------------------------------------------------------
void RuleSix::update(){
    
    // get a random voice
    if(bRandomVoice) {
        voice = voices[(int)ofRandom(24)];
    }
    
    // on every frame
    // we reset the forces
    // add in any forces on the particleSix
    // perfom damping and
    // then update
    
    int count = 0;
    
    for (int i = 0; i < nPtsW; i++){
        for (int j = 0; j < nPtsH; j++){
            
            
            float x = ofMap(i,0,nPtsW, 0,ofGetWidth());
            float y = ofMap(j,0,nPtsH, 0,ofGetHeight());
            
            particleSixs[count].resetForce();
            
            
            particleSixs[count].addAttractionForce(x, y, 1000, 0.1);
            //            // particleSixs[i * nPtsH + j].addClockwiseForce(mouseX, mouseY, 100, 0.4);
            particleSixs[count].addRepulsionForce(ofGetMouseX(), ofGetMouseY(), 500, 0.2);
            //
            
            particleSixs[count].addDampingForce();
            particleSixs[count].update();
            
            count++;
            
        }
    }


}

//--------------------------------------------------------------
void RuleSix::draw(){
    
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

    
    for (int i = 0; i < particleSixs.size(); i++){
        ofSetColor(colors[i % 12]);
        particleSixs[i].draw();
    }
    
    
    int strWidth = (seussLines[lineCount].length()*25) ;
    // x and y for the drawing
    float x = (ofGetWidth()-strWidth)/2;
    float y = ofGetHeight()/2;
  
    // we are slowy grabbing part of the line
    string typedLine = seussLines[lineCount].substr(0, letterCount);
    
    ofSetColor(243,167,153);
    ofRect(x-10, y-30, strWidth, 55);
    ofSetColor(255);
    IntroBlack.drawString(typedLine, x+4, y+11);
    
    
    // this is our timer for grabbing the next letter
    float time = ofGetElapsedTimeMillis() - nextLetterTime;
    
    if(time > 9) {
        
        // increment the letter count until
        // we reach the end of the line
        if(letterCount < (int)seussLines[lineCount].size()) {
            
            // move on to the next letter
            letterCount ++;
            
            // store time for next letter type
            nextLetterTime = ofGetElapsedTimeMillis();
            
        }
        else {
            
            // wait just a flash then move on
            // to the next line...
            if(time > 300) {
                
                nextLetterTime = ofGetElapsedTimeMillis();
                letterCount = 0;
                lineCount ++;
                lineCount %= seussLines.size();
            }
            
        }
    }


}

//--------------------------------------------------------------
void RuleSix::exit() {
    // stop the thread on exit
    waitForThread(true);
}

//--------------------------------------------------------------
void RuleSix::keyPressed(int key){
    
    if(key == 'r') {
        bRandomVoice = !bRandomVoice;
    }
    
    if(key == ' ') {
        voice = voices[(int)ofRandom(24)];
    }

}

//--------------------------------------------------------------
void RuleSix::keyReleased(int key){

}

//--------------------------------------------------------------
void RuleSix::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void RuleSix::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void RuleSix::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void RuleSix::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void RuleSix::windowResized(int w, int h){

}

//--------------------------------------------------------------
void RuleSix::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void RuleSix::dragEvent(ofDragInfo dragInfo){ 

}
