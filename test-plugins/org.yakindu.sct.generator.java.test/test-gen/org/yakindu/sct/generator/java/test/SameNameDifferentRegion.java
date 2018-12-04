
package org.yakindu.sct.generator.java.test;

import org.junit.*;
import static org.junit.Assert.*;
import org.yakindu.scr.samenamedifferentregion.SameNameDifferentRegionStatemachine;
import org.yakindu.scr.samenamedifferentregion.SameNameDifferentRegionStatemachine.State;	
import org.yakindu.scr.VirtualTimer;
import org.yakindu.scr.VirtualTimer.VirtualTimeTask;
import org.yakindu.scr.VirtualTimer.CycleTimeEventTask;

/**
 * Unit TestCase for SameNameDifferentRegion
 */
@SuppressWarnings("all")
public class SameNameDifferentRegion {
	
	private SameNameDifferentRegionStatemachine statemachine;	
	private VirtualTimer timer;
	
	
	@Before
	public void sameNameDifferentRegion_setUp() {
		statemachine = new SameNameDifferentRegionStatemachine();
		timer = new VirtualTimer(200);
		timer.schedulePeriodicalTask(new CycleTimeEventTask(statemachine), 200, 200);
		
		statemachine.init();
		
	}

	@After
	public void sameNameDifferentRegion_tearDown() {
		statemachine = null;
		
		timer = null;
	}
	
	@Test
	public void sameNameDifferenRegionTest() {
		statemachine.enter();
		assertTrue(statemachine.isStateActive(State.main_region_StateA));
		statemachine.getSCInterface().raiseE1();
		timer.cycleLeap(1);
		assertTrue(statemachine.isStateActive(State.main_region_StateB));
		assertTrue(statemachine.isStateActive(State.main_region_StateB_r1_StateA));
		statemachine.getSCInterface().raiseE1();
		timer.cycleLeap(1);
		assertTrue(statemachine.isStateActive(State.main_region_StateB));
		assertTrue(statemachine.isStateActive(State.main_region_StateB_r1_StateB));
	}
}
