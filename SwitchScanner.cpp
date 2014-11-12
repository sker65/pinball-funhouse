/*
 * SwitchScanner.cpp
 *
 *  Created on: 12.11.2014
 *      Author: srinke
 */

#include "SwitchScanner.h"
#include "Arduino.h"

SwitchScanner::SwitchScanner() :
		Task(10) {
	colStrobe = false;
	rowIndex = 0;
	handlerIndex = 0;
}

void SwitchScanner::run() {
	if (colStrobe) {
		colStrobe = false;
		int nrow = rowIndex + 1;
		if (nrow == 2)
			nrow = 0;

		// check for changes
		boolean switchesChanged = false;
		for (int col = 0; col < 8; col++) {
			if (rows[nrow][col] != rows[rowIndex][col]) {
				switchesChanged = true;
				// scan handlers
				for( int h = 0; h<handlerIndex; h++) {
					if( handlers[h].col == col ) {
						if( ( rows[nrow][col] & handlers[h].rowMask )
								!= ( rows[rowIndex][col] & handlers[h].rowMask) ) {
							if( rows[rowIndex][col] & handlers[h].rowMask == LOW ) {
								handlers[h].action->onSwitchActive();
							} else {
								handlers[h].action->onSwitchInactive();
							}
						}
					}
				}
			}
		}
		rowIndex = nrow;
	}
}

void SwitchScanner::registerSwitchAction(int col, int row, SwitchAction* action) {
	handlers[handlerIndex].action = action;
	handlers[handlerIndex].col = col;
	handlers[handlerIndex].rowMask = !(1 << row);
	if( handlerIndex < MAX_HANDLERS ) handlerIndex++;
}

void SwitchScanner::readSwitches() {
	int col = 0;
	rows[rowIndex][col++] = (PIND >> 3) + (PINB << 5);
	delayMicroseconds(28);
	rows[rowIndex][col++] = (PIND >> 3) + (PINB << 5);
	delayMicroseconds(28);
	rows[rowIndex][col++] = (PIND >> 3) + (PINB << 5);
	delayMicroseconds(28);
	rows[rowIndex][col++] = (PIND >> 3) + (PINB << 5);
	delayMicroseconds(28);
	rows[rowIndex][col++] = (PIND >> 3) + (PINB << 5);
	delayMicroseconds(28);
	rows[rowIndex][col++] = (PIND >> 3) + (PINB << 5);
	delayMicroseconds(28);
	rows[rowIndex][col++] = (PIND >> 3) + (PINB << 5);
	delayMicroseconds(28);
	rows[rowIndex][col++] = (PIND >> 3) + (PINB << 5);
	colStrobe = true;
}

