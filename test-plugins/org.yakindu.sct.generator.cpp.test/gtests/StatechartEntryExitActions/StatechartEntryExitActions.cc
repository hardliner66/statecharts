#include <string>
#include "gtest/gtest.h"
#include "StatechartEntryAndExitActions.h"
#include "sc_runner.h"
#include "sc_types.h"

namespace  {

void entryActionsAreExecutedOnEnteringStatechartOnlyIfGuardIsTrue();
void exitActionsAreExecutedOnEnteringStatechartOnlyIfGuardIsTrue();
statechartactions::StatechartEntryAndExitActions* statechart;



//! The timers are managed by a timer service. */
static SctUnitRunner * runner;

class StatechartEntryExitActions : public ::testing::Test{
	protected:
	virtual void SetUp() {
		statechart = new statechartactions::StatechartEntryAndExitActions();
		statechart->init();
		runner = new SctUnitRunner(
			statechart,
			false,
			200
		);
	}
	virtual void TearDown() {
		delete statechart;
		delete runner;
	}
};

void entryActionsAreExecutedOnEnteringStatechartOnlyIfGuardIsTrue(){
	EXPECT_TRUE(statechart->getDefaultSCI()->get_x()== 0l);
	
	EXPECT_TRUE(statechart->getDefaultSCI()->get_y()== 0l);
	
	statechart->getDefaultSCI()->set_b(false);
	
	statechart->enter();
	
	EXPECT_TRUE(statechart->getDefaultSCI()->get_x()== 2l);
	
	EXPECT_TRUE(statechart->getDefaultSCI()->get_y()== 3l);
	
	
}
void exitActionsAreExecutedOnEnteringStatechartOnlyIfGuardIsTrue(){
	statechart->enter();
	
	statechart->exit();
	
	EXPECT_TRUE(statechart->getDefaultSCI()->get_x()== 8l);
	
	EXPECT_TRUE(statechart->getDefaultSCI()->get_y()== 2l);
	
	
}

TEST_F(StatechartEntryExitActions, entryActionsAreExecutedOnEnteringStatechart) {
	
	EXPECT_TRUE(statechart->getDefaultSCI()->get_x()== 0l);
	
	EXPECT_TRUE(statechart->getDefaultSCI()->get_y()== 0l);
	
	statechart->getDefaultSCI()->set_b(true);
	
	statechart->enter();
	
	EXPECT_TRUE(statechart->getDefaultSCI()->get_x()== 5l);
	
	EXPECT_TRUE(statechart->getDefaultSCI()->get_y()== 3l);
	
	
}
TEST_F(StatechartEntryExitActions, exitActionsAreExecutedOnEnteringStatechart) {
	
	statechart->enter();
	
	statechart->exit();
	
	EXPECT_TRUE(statechart->getDefaultSCI()->get_x()== 6l);
	
	EXPECT_TRUE(statechart->getDefaultSCI()->get_y()== 2l);
	
	
}

}

