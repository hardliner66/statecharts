/* Generated by YAKINDU Statechart Tools code generator. */

#include "gtest/gtest.h"
#include "TriggerExpressionPrecedence.h"

#include "sc_timer_service.h"



//! The timers are managed by a timer service. */
static sc_unit_timer_service_t timer_service;

static TriggerExpressionPrecedence statechart;

class TriggerExpressionPrecedenceTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		triggerExpressionPrecedence_init(&statechart);
		sc_timer_service_init(
			&timer_service,
			0,
			(sc_run_cycle_fp) &triggerExpressionPrecedence_runCycle,
			false,
			200,
			&statechart
		);
	}
};


TEST_F(TriggerExpressionPrecedenceTest, unsatisfiedTriggerAndFGuardFalseOrFalse) {
	triggerExpressionPrecedence_enter(&statechart);
	triggerExpressionPrecedenceIface_set_c1(&statechart,false);
	triggerExpressionPrecedenceIface_set_c2(&statechart,false);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(!triggerExpressionPrecedenceIface_get_e1_transition(&statechart));
}
TEST_F(TriggerExpressionPrecedenceTest, unsatisfiedTriggerAndFGuardTrueOrFalse) {
	triggerExpressionPrecedence_enter(&statechart);
	triggerExpressionPrecedenceIface_set_c1(&statechart,true);
	triggerExpressionPrecedenceIface_set_c2(&statechart,false);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(!triggerExpressionPrecedenceIface_get_e1_transition(&statechart));
}
TEST_F(TriggerExpressionPrecedenceTest, unsatisfiedTriggerAndFGuardFalseOrTrue) {
	triggerExpressionPrecedence_enter(&statechart);
	triggerExpressionPrecedenceIface_set_c1(&statechart,false);
	triggerExpressionPrecedenceIface_set_c2(&statechart,true);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(!triggerExpressionPrecedenceIface_get_e1_transition(&statechart));
}
TEST_F(TriggerExpressionPrecedenceTest, unsatisfiedTriggerAndFGuardTrueOrTrue) {
	triggerExpressionPrecedence_enter(&statechart);
	triggerExpressionPrecedenceIface_set_c1(&statechart,true);
	triggerExpressionPrecedenceIface_set_c2(&statechart,true);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(!triggerExpressionPrecedenceIface_get_e1_transition(&statechart));
}

