#include "RuleNine.h"
#include "ofxImageSequence.h"

//--------------------------------------------------------------
void RuleNine::setup(){
    
    type.loadImage("Rule9_type.png");
  
    frame.loadImage("frame.png");
    Mate.loadImage("Mate.png");
    Inst.loadImage("Inst_RuleNine.png");
    
    videoGrabber.initGrabber(320, 240);
    
    colorImg.allocate(videoGrabber.width, videoGrabber.height);
    grayImage.allocate(videoGrabber.width, videoGrabber.height);
    CompyImages.loadSequence("CompyAlpha/CompyAlpha_", "png", 0, 33, 5);
    CompyImages.preloadAllFrames();

    float colWidth = ofGetWidth()/3; // distance of columns, 3 cloumns per frame
    float rowHeight = ofGetHeight()/3; // distance of rows also 3
    
    for(int row=0; row<5; row++) { //make 5 rows
        float offSet = (row % 2)*(colWidth/2); //offset = every other row ---> half the columm width
        for(int col=0; col<5; col++) { //take all 5 rows and make 5 cloumns
            Cloud cloud; // create a new instance of Cloud, called cloud
            cloud.pos = ofVec2f(col*(colWidth+100) + offSet, row*rowHeight); // set the new clouds starting position to be a vector of col * width/3+100
            allClouds.push_back(cloud); // push the cloud into the vector storing all our clouds, the vector goes on forever, add cloud to the vector allClouds, at the end
        }
    }
    

//    `allClouds` is a vector that stores instances of `Cloud`.
//    when we have added `Cloud`s to `allCloud` we can access them again with square brackets: `allCloud[0]`  will access the first instance of `Cloud` in the vector.

}

//--------------------------------------------------------------
void RuleNine::update(){
    
    counter = counter + 0.033f;
    


        for (int i = 0; i < allClouds.size(); i++) {
        allClouds[i].update();

        
    }

    
    videoGrabber.update();
    bool bNewFrame = false;
    unsigned char * pixels;
    
    pixels = videoGrabber.getPixels();
    bNewFrame = videoGrabber.isFrameNew();
    
    if (bNewFrame){
        colorImg.setFromPixels(pixels, videoGrabber.width, videoGrabber.height);
        
        grayImage = colorImg;
        grayImage.mirror(false, true);
    }

}

//--------------------------------------------------------------
void RuleNine::draw(){

    

    
    ////BG------white paper with light blue gridded lines--------------------
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
    Inst.draw(590,ofGetHeight()-150);
    
    for (int k = 0; k < 2; k ++) {
                  for (int j = 0; j < 3; j ++) {
            
           ofSetColor(255);
                    
            Mate.draw(j*455+430,k*400-330,73,130);
            Mate.draw(j*445+20,k*400+686,73,130);//about to switch him into his own class
                    
//            Mate.draw(j*400,k*400-340,100+(10 * sin(counter)),210+(10 * sin(counter))); //about to switch him into his own class
            CompyImages.getFrameForTime(ofGetElapsedTimef())->draw((j*800)-660,610*k+10,240,240); //the frame and the current frame
           CompyImages.getFrameForTime(ofGetElapsedTimef())->draw((j*580)-50,410*k-130,240,240); //the frame and the current frame
            
            

            
            
            }
        }
    

    ofSetColor(255);
    frame.draw(330,220);
    ofSetColor(73,66,54);
   
    
    
    ofSetColor(200, 200, 200);
    int videowidth = 600;
    int videoheight = 338;
    grayImage.draw(370, 240,videowidth,videoheight);
    
    IplImage* eig = cvCreateImage( cvGetSize(grayImage.getCvImage()), 32, 1 );
    IplImage* temp = cvCreateImage( cvGetSize(grayImage.getCvImage()), 32, 1 );
    
    cvReleaseImage( &eig );
    cvReleaseImage( &temp );
    
    grayImage.draw(360, 240,videowidth,videoheight);
    
    //id like to tint the video but not sure how
    for (int i=400; i<grayImage.width; i++){
        for (int j=200; j< grayImage.height; j++){
            float brightness = myColor.getBrightness(); // get the brightness of the color
            float length = ofMap(brightness,0,255,1,12);
            if (brightness >=0 && brightness < 40){
                colorvar = ofColor :: darkTurquoise;
            } else if (brightness >= 40 && brightness < 69 ){
                colorvar = ofColor :: cornflowerBlue;
            } else if (brightness >= 69 && brightness <= 70 ){
                colorvar = ofColor :: coral;
            } else if (brightness > 70 && brightness <=120){
                colorvar = ofColor :: aqua;
            } else if (brightness > 120 && brightness <=200){
                colorvar = ofColor :: cyan;
            } else if (brightness > 200 && brightness <215){
                colorvar = ofColor :: lawnGreen;
            } else if (brightness > 215 && brightness <255){
                colorvar = ofColor :: yellow;
            } else if (brightness == 255){
                colorvar = ofColor :: pink;
                
            }
        }
    }

    for (int i = 0; i < allClouds.size(); i++) { //drawing all the clouds, every frame
        allClouds[i].draw();
    }

    ofSetColor(73,66,54);
    type.draw(470,105);

    }

//--------------------------------------------------------------
void RuleNine::keyPressed(int key){

}

//--------------------------------------------------------------
void RuleNine::keyReleased(int key){

}

//--------------------------------------------------------------
void RuleNine::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void RuleNine::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void RuleNine::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void RuleNine::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void RuleNine::windowResized(int w, int h){

}

//--------------------------------------------------------------
void RuleNine::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void RuleNine::dragEvent(ofDragInfo dragInfo){ 

}
