// This does the missions on the south wall.  (Door Deliver, Package Drop off)
void southWallMission()
{



}



// This does the missions on the east wall (Hellicopter, Cargo Ship)
void eastWallMission()
{
	// Drive to get on the line
	driveStraightEncoderDistance(30, 5, false);

	// Follow the line for distance a bit
	lineFollowForDistance (20, 4, rightSensor, rightEdge, false);

	// Line follow until white
	lineFollowUntilLine(20, rightSensor, rightEdge,white,false);

	// Line follow until Black
	lineFollowUntilLine(20, rightSensor, rightEdge, black, false);

	// Sound that it found the black line
	playSound(soundBlip);

	// drive to get ready for turn
	driveStraightEncoderDistance(20, 9.5, true);

	// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, white, true);

	// Turn to the right until we see black.
	sideTurnUntilLine(10, rightSensor, black, true);

	// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, grey, true);

	// line follow to get ready to lookfor the lines
	lineFollowForDistance (20, 14, rightSensor, rightEdge, true);

	// Line follow until white
	lineFollowUntilLine(20,rightSensor,rightEdge,white,false);

	// Line follow until Black
	lineFollowUntilLine(20,rightSensor,rightEdge,black,false);

	// turn to face the wall
	centerTurnUsingGyro(10,-90,true);
	driveStraightEncoderDistance(-10,4,true);

	// Line follow until white
	lineFollowUntilLine(10,leftSensor,rightEdge,white,true);

	// Line follow until Black
	lineFollowUntilLine(10,leftSensor,rightEdge,black,true);

	//move back a little
	driveStraightEncoderDistance(-10, 2, true);

	// turn to face the crane
	centerTurnUsingGyro(15,90,true);

	//move the arm down
	moveLeftAttachmentMotorDegrees(90,100,false);

	// move the crane forward
	driveStraightEncoderDistance(10,5,true);

	// move back
	driveStraightEncoderDistance(-15,5,true);



}


//----------------------------------------------------------------------------------------------------
// Name:endMission
//----------------------------------------------------------------------------------------------------
// Description:
//----------------------------------------------------------------------------------------------------
//Inputs: None
//----------------------------------------------------------------------------------------------------
void endMission()
{

	// Drive to get on the line
	driveStraightEncoderDistance(30, 5, false);

	// Follow the line for distance a bit
	lineFollowForDistance (20, 4, rightSensor, rightEdge, false);

	// Line follow until white
	lineFollowUntilLine(20, rightSensor, rightEdge,white,false);

	// Line follow until Black
	lineFollowUntilLine(20, rightSensor, rightEdge, black, false);

	// Sound that it found the black line
	playSound(soundBlip);

	// drive to get ready for turn
	driveStraightEncoderDistance(25, 9.5, true);

	// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, white, true);

	// Turn to the right until we see black.
	sideTurnUntilLine(10, rightSensor, black, true);

	// Turn to the right until we see grey.
	sideTurnUntilLine(10, rightSensor, grey, true);

	// line follow to get ready to lookfor the lines
	lineFollowForDistance (25, 14, rightSensor, rightEdge, true);

	// Line follow until white
	lineFollowUntilLine(25,rightSensor,rightEdge,white,false);

	// Line follow until Black
	lineFollowUntilLine(25,rightSensor,rightEdge,black,false);

	// Sound that it found the black line
	playSound(soundBlip);

	// No more line to follow, drive straight using the encoder
	driveStraightEncoderDistance(25, 13, true);

	// Center turn to line up with Cargo Connect
	centerTurnUsingGyro(20, 90, true);

	// Backup to be in the cargo connect circle
	driveStraightEncoderDistance(-20, 2, true);

	// Drop off the cargo in the cargo connect circle
	moveLeftAttachmentMotorDegrees(-400,600,false);

	// Sound that it found the black line
	playSound(soundUpwardTones);

	// Backup
	driveStraightEncoderDistance(-20, 8, true);

	// Turn using the gyro
	sideTurnUsingGyro(15, 70, true);

	// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, white, true);

	// Turn to the right until we see black.
	sideTurnUntilLine(10, rightSensor, black, true);

	// Backup to do cargo removal from dock
	driveStraightEncoderDistance(-25, 7.5, true);

	// Drive Forward
	driveStraightEncoderDistance(25, 7.5, true);

	// Line follow for a to get into position
	lineFollowForDistance (10, 2, rightSensor, leftEdge, false);

	// Line follow until white
	lineFollowUntilLine(15, rightSensor, leftEdge, white, false);

	// Line follow until Black
	lineFollowUntilLine(15, rightSensor, leftEdge, black, false);

	// Sound that it found the black line
	playSound(soundBlip);

	// Line follow for a to get into position
	lineFollowForDistance (15, 4, rightSensor, leftEdge, false);

	// Drive straight a bit more
	driveStraightEncoderDistance(15, 3.75, true);

	sleep(100);

	// Center turn to get into position to backup into the wall
	sideTurnUsingGyro(10, -70, true);

	// Backup to get the back wheel aligned with the black line
	driveStraightEncoderDistance(-15, 4.25, true);

	// Turn to the left until we see white.
	sideTurnUntilLine(-10, leftSensor, white, true);

	// Turn to the left until we see black.
	sideTurnUntilLine(-10, leftSensor, black, true);

	// Back up into the wall and coast into the wall
	driveStraightEncoderDistance(-50, 12, false);

	sleep(200);

	// Drive forward a little to be off the wall
	driveStraightEncoderDistance(15, 1, true);

	// Turn toward the ending obstacle
	centerTurnUsingGyro(20, 90, true);

	// Backup to make sure were behind the line
	driveStraightEncoderDistance(-20, 3, true);

	// Look for the white line
	driveStraightUntilLine(20, rightSensor, white, true);

	// Look for the black line
	driveStraightUntilLine(10, rightSensor, black, true);

	// Look for the gray line
	driveStraightUntilLine(10, rightSensor, grey, true);

	driveStraightEncoderDistance(5, 1.9, true);


	}





//----------------------------------------------------------------------------------------------------
// Name:northWallMission
//----------------------------------------------------------------------------------------------------
// Description: pizza
//----------------------------------------------------------------------------------------------------
//Inputs: None
//----------------------------------------------------------------------------------------------------
void northWallMission()
{

	sleep(200);

	// Reset the gyroscoe and wait 100ms to settle
	resetGyro(gyro);

	sleep(200);

	// Drive straight using the gyro to get on top of the line to follow
	driveStraightEncoderDistance(30, 11.5, true);

	// Line follow for a to get into position
	lineFollowForDistance (10, 6, leftSensor, leftEdge, false);

	// Drive straight using the gyro to get on top of the line to follow
	driveStraightEncoderDistance(30, 9.2, true);

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
	moveRightAttachmentMotorDegrees(100,950,true);

	// Wait a bit for the cargo to unload
	sleep(500);

	// Move the airplane arm back up
	moveRightAttachmentMotorDegrees(100,-950,true);

	// Drive straight to get in position to do switch
	driveStraightEncoderDistance(15, 6.7, true);

	// Move the arm down to prepare to do the switch
	moveLeftAttachmentMotorDegrees(50,-425,true);


	// Turn to get into position for the switch
	centerTurnUsingGyro(10, 30, true);

	// Engine switch
	moveLeftAttachmentMotorDegrees(10,200,false);

	// Drive Backwards
	driveStraightEncoderDistance(-30, 6,true);

	// Turn to head home
	centerTurnUsingGyro(20, 120, true);

	// Drive into home
	driveForTime(75,75,1.5);

	setBrakeMode(false);



}

//----------------------------------------------------------------------------------------------------
// Name: getBlueBoxMission
//----------------------------------------------------------------------------------------------------
// Description: Gets the blue box in case it is missed on the center mission
//----------------------------------------------------------------------------------------------------
//Inputs: None
//----------------------------------------------------------------------------------------------------

void getBlueBoxMission()
{

	sleep(500);

	// Reset the gyroscoe and wait 100ms to settle
	resetGyro(gyro);

	sleep(200);

		driveStraightEncoderDistance(40, 22.5, true);

		centerTurnUsingGyro(20, -90, true);

		driveStraightEncoderDistance(50, 19, true);


}


//----------------------------------------------------------------------------------------------------
// Name: pushBlueBoxMission
//----------------------------------------------------------------------------------------------------
// Description: Gets the blue box in case it is missed on the center mission
//----------------------------------------------------------------------------------------------------
//Inputs: None
//----------------------------------------------------------------------------------------------------
void pushBlueBoxMission()
{


		driveStraightEncoderDistance(50, 25, true);


		driveStraightEncoderDistance(-75, 24, false);

}

//----------------------------------------------------------------------------------------------------
// Name: centerMission
//----------------------------------------------------------------------------------------------------
// Description: Gets the blue box in case it is missed on the center mission
//----------------------------------------------------------------------------------------------------
//Inputs: None
//----------------------------------------------------------------------------------------------------
void centerMission()
{

	sleep(500);

	// Reset the gyroscoe and wait 100ms to settle
	resetGyro(gyro);

	sleep(200);

	// Drive to get on the line
	driveStraightEncoderDistance(15, 5, false);

	// Follow the line for distance a bit
	lineFollowForDistance (15, 4, rightSensor, rightEdge, false);

	// Line follow until white
	lineFollowUntilLine(15, rightSensor, rightEdge,white,false);

	// Line follow until Black
	lineFollowUntilLine(15, rightSensor, rightEdge, black, false);

	// Sound that it found the black line
	playSound(soundBlip);

	// drive t0 latch first truck
	driveStraightEncoderDistance(15, 1, true);

	// Raise arm after latching first truck
	moveRightAttachmentMotorDegrees(100,600,false);

	// Drive to make turn
	driveStraightEncoderDistance(30, 8, true);

	// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, white, true);

	// Turn to the right until we see black.
	sideTurnUntilLine(10, rightSensor, black, true);

	// Turn to the right until we see grey.
	sideTurnUntilLine(10, rightSensor, grey, true);

	// Lower arms to get second truck
	moveRightAttachmentMotorDegrees(100,-600,false);

	// Push second truck forward
	lineFollowForDistance (15, 7.75, rightSensor, rightEdge, true);

	// Raise arm to detach from second truck
	moveRightAttachmentMotorDegrees(100,600,false);

	// Push first half of the bridge down
	lineFollowForDistance (25, 7, rightSensor, rightEdge, true);

	// Line follow until white
	lineFollowUntilLine(25, rightSensor, rightEdge, white, false);

	// Line follow until Black
	lineFollowUntilLine(25, rightSensor, rightEdge, black, false);

	// Sound that it found the black line
	playSound(soundBlip);

	// Raise arm to avoid second half of bridge
	moveRightAttachmentMotorDegrees(100,400,false);

	// Move to get to the second half of the bridge
	lineFollowForDistance (25, 2, rightSensor, rightEdge, false);

	// knock down second half of bridge
	driveStraightEncoderDistance(25, 1, true);

	// Lower arm to be able to knock down second half of bridge
	moveRightAttachmentMotorDegrees(100,-450,false);

	// knock down second half of bridge
	driveStraightEncoderDistance(-25, 4, true);

	// Raise arm
	moveRightAttachmentMotorDegrees(100,450,false);

	// Start Helicopter Mission

	// drive straight a bit
	driveStraightEncoderDistance (20, 8.5, true);

	sleep(100);

	// Left turn to avoid false posotives
	sideTurnUsingGyro (10, -20 , true);

	// Turn left to white
	sideTurnUntilLine(-10, rightSensor, white, true);

	// Turn left to grey
	sideTurnUntilLine(-10, rightSensor, grey, true);

	//Approachig helecopter
	lineFollowForDistance (10, 2, rightSensor, rightEdge, false);

	//Approachig helecopter
	lineFollowForDistance (25, 12, rightSensor, rightEdge, false);

	//Approachig helecopter
	lineFollowForDistance (10, 2, rightSensor, rightEdge, true);


  // Drives into yellow wall to drop package
	driveStraightEncoderDistance (10, 2.3, true);

	// Backs up
	driveStraightEncoderDistance (-10, 4, true);

	// Turn to get straight
	sideTurnUsingGyro (15, 180, true);

	// Drive straight to get in line to turn
	driveStraightEncoderDistance (25, 7, true);

	// Turn to line follow
	sideTurnUsingGyro (10, 32, true);

	// Line follows to
	lineFollowForDistance (10, 3, leftSensor, leftEdge, false);

	// Line follows to
	lineFollowForDistance (30, 23, leftSensor, leftEdge, false);

	// Go to home
	driveStraightEncoderDistance(75, 36, false);


}
