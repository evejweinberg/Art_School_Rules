#ifndef particleFive_H
#define particleFive_H

#include "ofMain.h"

class particleFive
{
    public:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
			
        particleFive();
		virtual ~particleFive(){};

        void resetForce();
		void addForce(float x, float y);
		void addRepulsionForce(float x, float y, float radius, float scale);
		void addAttractionForce(float x, float y, float radius, float scale);
		void addRepulsionForce(particleFive &p, float radius, float scale);
		void addAttractionForce(particleFive &p, float radius, float scale);
		
		void addDampingForce();
        
		void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void draw();
	
		void bounceOffWalls();
	
	
		float damping;
    
    int radiusP;
    

    protected:
    private:
};

#endif // particleFive_H
