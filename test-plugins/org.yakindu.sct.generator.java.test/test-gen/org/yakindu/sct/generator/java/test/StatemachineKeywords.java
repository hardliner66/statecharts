
package org.yakindu.sct.generator.java.test;

import org.junit.*;
import static org.junit.Assert.*;
import org.yakindu.scr.statechartkeywords.StatechartKeywordsStatemachine;
import org.yakindu.scr.statechartkeywords.StatechartKeywordsStatemachine.State;	
import org.yakindu.scr.VirtualTimer;
import org.yakindu.scr.VirtualTimer.VirtualTimeTask;
import org.yakindu.scr.VirtualTimer.CycleTimeEventTask;

/**
 * Unit TestCase for StatechartKeywords
 */
@SuppressWarnings("all")
public class StatemachineKeywords {
	
	private StatechartKeywordsStatemachine statemachine;	
	private VirtualTimer timer;
	
	
	@Before
	public void statemachineKeywords_setUp() {
		statemachine = new StatechartKeywordsStatemachine();
		timer = new VirtualTimer(200);
		timer.schedulePeriodicalTask(new CycleTimeEventTask(statemachine), 200, 200);
		statemachine.setTimer(timer);
		
		statemachine.init();
		
	}

	@After
	public void statemachineKeywords_tearDown() {
		statemachine = null;
		
		timer = null;
	}
	
	@Test
	public void statemachineKeywords() {
		statemachine.enter();
		assertTrue(statemachine.isStateActive(State.main_region_Timer));
	}
}
