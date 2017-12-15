/* Generated by YAKINDU Statechart Tools code generator. */

#include "gtest/gtest.h"
#include "InEventLifeCycle.h"

#include "sc_timer_service.h"



//! The timers are managed by a timer service. */
static sc_unit_timer_service_t timer_service;

static InEventLifeCycle statechart;

class InEventLifeCycleTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		inEventLifeCycle_init(&statechart);
		sc_timer_service_init(
			&timer_service,
			0,
			(sc_run_cycle_fp) &inEventLifeCycle_runCycle,
			false,
			200,
			&statechart
		);
	}
};


TEST_F(InEventLifeCycleTest, eventLifeCycle) {
	inEventLifeCycle_enter(&statechart);
	inEventLifeCycleIface_raise_e(&statechart);
	EXPECT_TRUE(inEventLifeCycleIface_get_i(&statechart)== 0l);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(inEventLifeCycleIface_get_i(&statechart)== 1l);
}

