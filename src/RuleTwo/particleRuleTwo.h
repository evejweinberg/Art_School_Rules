#ifndef particleRuleTwo_H
#define particleRuleTwo_H

#include "ofMain.h"

class particleRuleTwo
{
    public:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
			
        particleRuleTwo();
        virtual ~particleRuleTwo(){}; //why do we do a virtual particleRuleTwo?

        void resetForce();
		void addForce(float x, float y);
		void addRepulsionForce(float x, float y, float radius, float scale);
		void addAttractionForce(float x, float y, float radius, float scale);
		
		void addRepulsionForce(particleRuleTwo &p, float radius, float scale);
		void addAttractionForce(particleRuleTwo &p, float radius, float scale);
		void addClockwiseForce(particleRuleTwo &p, float radius, float scale);
		void addCounterClockwiseForce(particleRuleTwo &p, float radius, float scale);
	
		
		void addDampingForce();
        
		void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void draw();
	
		void bounceOffWalls();
	
		bool  bFixed;
	
		float damping;
    
    ofImage myTeachers; //attempting to setup the for loop to load particleRuleTwos




    protected:
    private:
};

class particleRuleTwoMain
{
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
    
    particleRuleTwoMain();
    virtual ~particleRuleTwoMain(){}; //why do we do a virtual particleRuleTwo?
    
    void resetForce();
    void addForce(float x, float y);
    void addRepulsionForce(float x, float y, float radius, float scale);
    void addAttractionForce(float x, float y, float radius, float scale);
    
    void addRepulsionForce(particleRuleTwo &p, float radius, float scale);
    void addAttractionForce(particleRuleTwo &p, float radius, float scale);
    void addClockwiseForce(particleRuleTwo &p, float radius, float scale);
    void addCounterClockwiseForce(particleRuleTwo &p, float radius, float scale);
    
    
    void addDampingForce();
    
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
    void bounceOffWalls();
    bool  bFixed;
    float damping;
    
    ofImage Head; // my main particleRuleTwo

    
protected:
private:
};


#endif // particleRuleTwo_H
