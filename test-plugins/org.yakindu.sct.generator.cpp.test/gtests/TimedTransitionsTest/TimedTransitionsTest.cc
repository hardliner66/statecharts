/* Generated by YAKINDU Statechart Tools code generator. */
#include <string>
#include "gtest/gtest.h"
#include "TimedTransitions.h"
#include "sc_runner_timed.h"
#include "sc_types.h"

namespace  {

TimedTransitions* statechart;



//! The timers are managed by a timer service. */
static TimedSctUnitRunner * runner;

class TimedTransitionsTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		statechart = new TimedTransitions();
		statechart->init();
		runner = new TimedSctUnitRunner(
			statechart,
			false,
			200
		);
		statechart->setTimer(runner);
	}
	virtual void TearDown() {
		delete statechart;
		delete runner;
	}
};


TEST_F(TimedTransitionsTest, Timer01) {
	
	statechart->enter();
	
	EXPECT_TRUE(statechart->isStateActive(TimedTransitions::main_region_Start));
	
	runner->proceed_time(2030);
	
	runner->proceed_cycles(1);
	
	EXPECT_TRUE(statechart->isStateActive(TimedTransitions::main_region_End));
	
	
}


}
