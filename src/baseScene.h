#pragma once

#include "ofMain.h"

// 'vurtual void' is telling the compiler that anything subclassing this class shoud always have this function
class baseScene {
    
public:
    
    virtual void setup();
    
    
    
    virtual void update();
    virtual void draw();
    
    virtual void keyPressed(int key);
    virtual void keyReleased(int key);
    virtual void mouseMoved(int x, int y );
    virtual void mouseDragged(int x, int y, int button);
    virtual void mousePressed(int x, int y, int button);
    virtual void mouseReleased(int x, int y, int button);
    virtual void windowResized(int w, int h);
    virtual void dragEvent(ofDragInfo dragInfo);
    virtual void gotMessage(ofMessage msg);
    
    
    virtual void enable()  {enabled=true;};
    virtual void disable() {enabled=false;};
    
    
    bool isEnabled() {return enabled;};
    
protected:
    bool enabled = false;
    
};


