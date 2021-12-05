
// This mission does the stuff in the center of the board  (Truck drop off, slip roads down)
void centerMission()
{

	// Reset the gyroscoe and wait 100ms to settle
	resetGyro(gyro);
	sleep(200);

	driveStraightGyroDistance(20, 2, 0, false);
	driveStraightGyroDistance(50, 10, 0, true);

	sideTurnUsingGyro(20, 45, false);



}


// This does the missions on the south wall.  (Door Deliver, Package Drop off)
void southWallMission()
{



}

// This does the missions on the east wall (Hellicopter, Cargo Ship)
void eastWallMission()
{



}

// This mission does the end mission
void endMission()
{

	driveStraightEncoderDistance(30, 5, false);

	lineFollowForDistance (10, 4, rightSensor, rightEdge, false);

	lineFollowUntilLine(10, rightSensor, rightEdge,white,false);

	lineFollowUntilLine(10, rightSensor, rightEdge, black, false);

	driveStraightEncoderDistance(20, 9.5, true);

		// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, white, true);

	// Turn to the right until we see black.
	sideTurnUntilLine(10, rightSensor, black, true);

	// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, grey, true);



	lineFollowForDistance (20, 14, rightSensor, rightEdge, true);

	lineFollowUntilLine(10,rightSensor,rightEdge,white,false);

	// Line follow until we see black (Were in the right position for the airplane)
	lineFollowUntilLine(10,rightSensor,rightEdge,black,false);

	driveStraightEncoderDistance(15, 13, true);

	// Turn to get into position for the switch
	centerTurnUsingGyro(10, 90, true);

	driveStraightEncoderDistance(-10, 2, true);

	moveLeftAttachmentMotorDegrees(-400,600,false);


	driveStraightEncoderDistance(-10, 8.5, true);

	// Turn to get into position for the switch
	centerTurnUsingGyro(10, 70, true);

		// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, white, true);

	// Turn to the right until we see black.
	sideTurnUntilLine(10, rightSensor, black, true);

	lineFollowForDistance (20, 9, rightSensor, leftEdge, true);

	driveStraightEncoderDistance(10, 1.5, true);

		// Turn to get into position for the switch
	centerTurnUsingGyro(10, -90, true);

	driveStraightEncoderDistance(-50, 14, false);

	sleep(500);

	driveStraightEncoderDistance(2, 0.75, false);

	centerTurnUsingGyro(10, 90, true);

	driveStraightEncoderDistance(10, 4.75, true);


}





















//----------------------------------------------------------------------------------------------------
// Name:northWallMission
//----------------------------------------------------------------------------------------------------
// Description:
//----------------------------------------------------------------------------------------------------
//Inputs: None
//----------------------------------------------------------------------------------------------------
void northWallMission()
{

	sleep(500);

	// Reset the gyroscoe and wait 100ms to settle
	resetGyro(gyro);

	sleep(200);

	// Drive straight using the gyro to get on top of the line to follow
	// driveStraightGyroDistance(30, 27.5, -2, true);
	driveStraightEncoderDistance(30, 26.5, true);

	// Turn using the gyro to get close and not get stuck on the yellow line
	sideTurnUsingGyro(10, 20, true);

	// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, white, true);

	// Turn to the right until we see black.
	sideTurnUntilLine(10, rightSensor, black, true);

	// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, grey, true);

	// Line follow until we see white
	lineFollowUntilLine(10,rightSensor,rightEdge,white,true);

	// Line follow until we see black (Were in the right position for the airplane)
	lineFollowUntilLine(10,rightSensor,rightEdge,black,true);

	// Lowers airplane door
	moveRightAttachmentMotorDegrees(100,650,false);

	// Wait a bit for the cargo to unload
	sleep(500);

	// Move the airplane arm back up
	moveRightAttachmentMotorDegrees(100,-650,false);

	// Drive straight to get in position to do switch
	driveStraightEncoderDistance(15, 6.5, true);

	// Move the arm down to prepare to do the switch
	moveLeftAttachmentMotorDegrees(50,-450,false);

	// Turn to get into position for the switch
	centerTurnUsingGyro(10, 45, true);

	// Engine switch
	moveLeftAttachmentMotorDegrees(10,200,false);

	// Backup for time
	driveForTime(-30,-30,1.2);

	// Turn to head home
	centerTurnUsingGyro(20, 120, true);

	// Drive into home
	driveForTime(75,75,1.5);

	setBrakeMode(false);



}

//----------------------------------------------------------------------------------------------------
// Name:blueBox
//----------------------------------------------------------------------------------------------------
// Description:
//----------------------------------------------------------------------------------------------------
//Inputs: None
//----------------------------------------------------------------------------------------------------

void blueBoxMission()
{

	sleep(500);

	// Reset the gyroscoe and wait 100ms to settle
	resetGyro(gyro);

	sleep(200);

		driveStraightEncoderDistance(40, 22.5, true);

		centerTurnUsingGyro(20, -90, true);

		driveStraightEncoderDistance(50, 19, true);



}





void secondCenterMission()
{

	sleep(500);

	// Reset the gyroscoe and wait 100ms to settle
	resetGyro(gyro);

	sleep(200);

	driveStraightEncoderDistance(10, 9, false);

	lineFollowForDistance (10, 8.5, leftSensor, leftEdge, true);
	// lineFollowForDistance(float speed, float inchesToMove,  string colorSensorToUse, string edgeToUse, bool brakeMode)

	moveRightAttachmentMotorDegrees(100,600,false);

	driveStraightEncoderDistance(30, 9.75, true);

	// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, white, true);

	// Turn to the right until we see black.
	sideTurnUntilLine(10, rightSensor, black, true);

	// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, grey, true);

	// Backup to get to second truck
	driveStraightEncoderDistance(-10, 2, true);

	// Lower arms to get second truck
	moveRightAttachmentMotorDegrees(100,-600,false);

	// Push second truck forward
	lineFollowForDistance (10, 7.25, rightSensor, rightEdge, true);

	// Raise arm to detach from second truck
	moveRightAttachmentMotorDegrees(100,600,false);

	// Push first half of the bridge down
	lineFollowForDistance (10, 7, rightSensor, rightEdge, true);

	// Raise arm to avoid second half of bridge
	moveRightAttachmentMotorDegrees(100,400,false);

	// Move to get to the second half of the bridge
	lineFollowForDistance (10, 4, rightSensor, rightEdge, false);

	// Move forward a bit
	driveStraightEncoderDistance(10, 2, true);

	// Lower arm to be able to knock down second half of bridge
	moveRightAttachmentMotorDegrees(100,-450,false);

	// knock down second half of bridge
	driveStraightEncoderDistance(-10, 2, true);

	// Drive back to base
	driveStraightEncoderDistance(-75,50,false);

	}
