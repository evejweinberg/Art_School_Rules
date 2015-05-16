#ifndef springRuleTwo_H
#define springRuleTwo_H

#include "ofMain.h"

#include "particleRuleTwo.h"

class springRuleTwo {

	public:

		springRuleTwo();
		
		particleRuleTwo * particleRuleTwoA; //what is this?
		particleRuleTwo * particleRuleTwoB;
		
		float distance;
		float springRuleTwoiness;	 // this is the k, springRuleTwoiness constant
	
		void update();
		void draw();
	
	
};


#endif