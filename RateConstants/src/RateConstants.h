
	#ifndef SRC_RATECONSTANTS_H
	#define SRC_RATECONSTANTS_H

	#include "SemanticAdaptation.h"
	#include <memory>
	#include "Fmu.h"
	
	using namespace std;
	using namespace fmi2;
	
	namespace adaptation
	{
		
		#define CONSTANTSPSUVOLT 0
		#define CONSTANTSREF 1
		#define CONSTANTSCONST.K 2
		#define CONSTANTSCONST2.K 3
		#define CONSTANTSCONST.Y 2
		#define CONSTANTSCONST2.Y 3
		
		#define RATECONSTANTSPSUVOLT 0
		#define RATECONSTANTSREF 1
	
		class RateConstants : public SemanticAdaptation<RateConstants>, public enable_shared_from_this<RateConstants>
		{
			public:
				RateConstants(shared_ptr<std::string> fmiInstanceName, shared_ptr<string> resourceLocation, const fmi2CallbackFunctions* functions);
				void initialize();
				virtual ~RateConstants();
				
				void setFmiValue(fmi2ValueReference id, int value);
				void setFmiValue(fmi2ValueReference id, bool value);
				void setFmiValue(fmi2ValueReference id, double value);
				void setFmiValue(fmi2ValueReference id, string value);
			
				int getFmiValueInteger(fmi2ValueReference id);
				bool getFmiValueBoolean(fmi2ValueReference id);
				double getFmiValueReal(fmi2ValueReference id);
				string getFmiValueString(fmi2ValueReference id);
				
			private:
				
				RateConstants* getRuleThis();
				
				/*in rules*/
				bool in_rule_condition1();
				void in_rule_body1();
				void in_rule_flush1();
				shared_ptr<list<Rule<RateConstants>>> createInputRules();
				
				/*out rules*/
				bool out_rule_condition1();
				void out_rule_body1();
				void out_rule_flush1();
				shared_ptr<list<Rule<RateConstants>>> createOutputRules();
				
				double executeInternalControlFlow(double H, double t);
				
				shared_ptr<FmuComponent> constants;
				
				double psuvolt;
				double ref;
				
				double INIT_PSUVOLT;
				double INIT_REF;
				double stored__psuvolt;
				double stored__ref;
		};
	}
	
	#endif
