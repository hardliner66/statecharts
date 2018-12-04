
#include "gtest/gtest.h"
#include "DeepHistory.h"

#include "sc_timer_service.h"

static DeepHistory statechart;


class DeepHistoryTest : public ::testing::Test
{
public:
	/* All operations from the SCTUnit test class. */
	void deepHistoryTest();
	void setTimer(DeepHistory* statechart, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);
	void unsetTimer(DeepHistory* handle, const sc_eventid evid);
protected:
	sc_unit_timer_service_t timer_service;
	virtual void SetUp();
};

static DeepHistoryTest * tc;


void DeepHistoryTest::SetUp()
{
	deepHistory_init(&statechart);
	sc_timer_service_init(
		&timer_service,
		0,
		(sc_run_cycle_fp) &deepHistory_runCycle,
		false,
		200,
		&statechart
	);
	
	
	tc = this;
}
void DeepHistoryTest::deepHistoryTest()
{
	deepHistory_enter(&statechart);
	deepHistoryIface_raise_event1(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	deepHistoryIface_raise_event3(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	deepHistoryIface_raise_event5(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	deepHistoryIface_raise_event7(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(!deepHistory_isStateActive(&statechart, DeepHistory_mainRegion_State1));
	EXPECT_TRUE(deepHistory_isStateActive(&statechart, DeepHistory_mainRegion_State2__region0_State4__region0_State7__region0_State9));
	deepHistoryIface_raise_event2(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(deepHistory_isStateActive(&statechart, DeepHistory_mainRegion_State1));
	EXPECT_TRUE(!deepHistory_isStateActive(&statechart, DeepHistory_mainRegion_State2__region0_State4__region0_State7__region0_State9));
	deepHistoryIface_raise_event1(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(!deepHistory_isStateActive(&statechart, DeepHistory_mainRegion_State1));
	EXPECT_TRUE(deepHistory_isStateActive(&statechart, DeepHistory_mainRegion_State2__region0_State4__region0_State7__region0_State9));
}

void DeepHistoryTest::setTimer(DeepHistory* statechart, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic){
	sc_timer_t timer;
	sc_timer_init(&timer, time_ms, periodic, evid);
	insert_timer(&(tc->timer_service), timer);
}

void DeepHistoryTest::unsetTimer(DeepHistory* handle, const sc_eventid evid){
	delete_task(&(tc->timer_service), find_time_event(&timer_service, evid));
}

TEST_F(DeepHistoryTest, deepHistoryTest) {
	deepHistoryTest();
}


