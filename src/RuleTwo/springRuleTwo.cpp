#include "springRuleTwo.h"

//---------------------------------------------------------------------
springRuleTwo::springRuleTwo(){
	particleRuleTwoA = NULL;
	particleRuleTwoB = NULL;
}

//---------------------------------------------------------------------
void springRuleTwo::update(){
	if ((particleRuleTwoA == NULL) || (particleRuleTwoB == NULL)){ //what do double pipes mean
		return;
	}
	
	ofVec2f pta = particleRuleTwoA->pos; //stores a 2 dimentional vector
	ofVec2f ptb = particleRuleTwoB->pos;
	
	float theirDistance = (pta - ptb).length(); //find the length of the fistance from pta to ptb
	float springRuleTwoForce = (springRuleTwoiness * (distance - theirDistance));
	ofVec2f frcToAdd = (pta-ptb).normalized() * springRuleTwoForce;
	
	particleRuleTwoA->addForce(frcToAdd.x, frcToAdd.y);
	particleRuleTwoB->addForce(-frcToAdd.x, -frcToAdd.y);
}


//---------------------------------------------------------------------
void springRuleTwo::draw(){
	
    if ((particleRuleTwoA == NULL) || (particleRuleTwoB == NULL)){ //what do double pipes mean
		return;
	}
	
	ofLine(particleRuleTwoA->pos.x, particleRuleTwoA->pos.y, particleRuleTwoB->pos.x, particleRuleTwoB->pos.y); //if...draw a line, no balls are drawn here
}