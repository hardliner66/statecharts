/* Generated by YAKINDU Statechart Tools code generator. */

#include "gtest/gtest.h"
#include "HistoryWithExitPoint.h"

#include "sc_timer_service.h"



//! The timers are managed by a timer service. */
static sc_unit_timer_service_t timer_service;

static HistoryWithExitPoint statechart;

class HistoryWithExitPointTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		historyWithExitPoint_init(&statechart);
		sc_timer_service_init(
			&timer_service,
			0,
			(sc_run_cycle_fp) &historyWithExitPoint_runCycle,
			false,
			200,
			&statechart
		);
	}
};


TEST_F(HistoryWithExitPointTest, historyEntryAfterExit) {
	historyWithExitPoint_enter(&statechart);
	EXPECT_TRUE(historyWithExitPoint_isStateActive(&statechart, HistoryWithExitPoint_mr_A_r_X1));
	historyWithExitPointIface_raise_push(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(historyWithExitPoint_isStateActive(&statechart, HistoryWithExitPoint_mr_B));
	historyWithExitPointIface_raise_back(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(historyWithExitPoint_isStateActive(&statechart, HistoryWithExitPoint_mr_A_r_X1));
	historyWithExitPointIface_raise_next(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(historyWithExitPoint_isStateActive(&statechart, HistoryWithExitPoint_mr_A_r_X2));
	historyWithExitPointIface_raise_push(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(historyWithExitPoint_isStateActive(&statechart, HistoryWithExitPoint_mr_B));
	historyWithExitPointIface_raise_back(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(historyWithExitPoint_isStateActive(&statechart, HistoryWithExitPoint_mr_A_r_X2));
}

