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

#define MOTOR_38_REST_POSE 409977
#define MOTOR_39_REST_POSE 211106
#define MOTOR_40_REST_POSE 238316
#define MOTOR_41_REST_POSE 283353
#define MOTOR_42_REST_POSE 218016

#define MOTOR_38_LIFT_POSE 108953
#define MOTOR_39_LIFT_POSE 587836
#define MOTOR_40_LIFT_POSE 222139
#define MOTOR_41_LIFT_POSE 134231
#define MOTOR_42_LIFT_POSE 123502

int main() {
	Robot *canBus = new Robot("../../../../../roboy/", false);
	PauseTimer waitTimer(1000000000);
	char buffer[100];
	
	canBus->initialize(CAN_BUS_NODE);

	canBus->clearFault(38);
	canBus->clearFault(39);
	canBus->clearFault(41);
	
	canBus->setMaxVelocityAndAcceleration(38, 4000, 40000);
	canBus->setMaxVelocityAndAcceleration(39, 4000, 40000);
	canBus->setMaxVelocityAndAcceleration(40, 4000, 40000);
	canBus->setMaxVelocityAndAcceleration(41, 4000, 40000);
	canBus->setMaxVelocityAndAcceleration(42, 4000, 40000);
	
	canBus->initializeMotorForControl(38);
	canBus->initializeMotorForControl(39);
	canBus->initializeMotorForControl(40);
	canBus->initializeMotorForControl(41);
	canBus->initializeMotorForControl(42);
	
	canBus->setMotorControl(40, MOTOR_41_LIFT_POSE, POSITION_CONTROL);
	canBus->setMotorControl(42, MOTOR_41_LIFT_POSE, POSITION_CONTROL);
	canBus->setMotorControl(38, MOTOR_38_LIFT_POSE, POSITION_CONTROL);
	canBus->setMotorControl(41, MOTOR_41_LIFT_POSE, POSITION_CONTROL);
	canBus->setMotorControl(39, MOTOR_39_LIFT_POSE, POSITION_CONTROL);
	
	waitTimer.wait();
	waitTimer.wait();
	waitTimer.wait();
	waitTimer.wait();
	waitTimer.wait();
	
	canBus->setMotorControl(39, MOTOR_39_REST_POSE, POSITION_CONTROL);
	canBus->setMotorControl(38, MOTOR_38_REST_POSE, POSITION_CONTROL);
	canBus->setMotorControl(41, MOTOR_41_REST_POSE, POSITION_CONTROL);
	canBus->setMotorControl(40, MOTOR_41_LIFT_POSE, POSITION_CONTROL);
	canBus->setMotorControl(42, MOTOR_41_LIFT_POSE, POSITION_CONTROL);
	
	waitTimer.wait();
	waitTimer.wait();
	waitTimer.wait();

	canBus->stopMotorControl(38);
	canBus->stopMotorControl(39);
	canBus->stopMotorControl(41);
	canBus->uninitialize();
	
	return 0;
}

