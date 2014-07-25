/*Copyright (c) 2014, University of Zurich, Department of Informatics, Artificial Intelligence Laboratory
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holder nor the names of its contributors 
   may be used to endorse or promote products derived from this software without 
   specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/
#include "main.h"

int main() {
	char buffer[100];
	Robot *canBus = new Robot("../../../../../roboy/", false);
	PauseTimer delayTimmer(100000000);
	delayTimmer.wait();
	TRACE_RED_BOLD("Setting Motor 19 to Encoder Value to 353362. Ensure that right arm is in proper initialization position."); TRACE("\n");
	printf("Type 'e' and enter to exit. Enter to continue: ");
	gets(buffer);
	if(strncmp(buffer, "e", 1) == 0) {
		printf("Exiting program...\n");
		return 0;
	}
	
	canBus->initialize(CAN_BUS_NODE);
	canBus->enterPreOperational();
	canBus->clearFault(19);	
	canBus->initializeMotorForControl(19);
	canBus->setMotorEncoderValue(19, 353362);
	
	TRACE_PURP_BOLD("Motor 19 Encoder Values set to 353362."); TRACE("\n");
	
	delayTimmer.wait();
	canBus->uninitialize();
	delayTimmer.wait();
	
}

