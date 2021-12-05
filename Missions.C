
// This mission does the stuff in the center of the board  (Truck drop off, slip roads down)
void centerMission()
{



}


// This does the missions on the south wall.  (Door Deliver, Package Drop off)
void southWallMission()
{



}

// This does the missions on the east wall (Hellicopter, Cargo Ship)
void eastWallMission()
{
	driveStraightGyroDistance(30,24,0,true);
	centerTurnUsingGyro(25,90,true);
	driveEncoderDistance(50,50,20,true);
	lineFollowForDistance(30,5,rightSensor,rightEdge,true);
	lineFollowUntilLine(20,leftSensor,leftEdge,white,true);
	lineFollowUntilLine(20,leftSensor,leftEdge,black,true);
	sideTurnUsingGyro(20,-90,true);
	lineFollowUntilLine(20,rightSensor,rightEdge,white,true);
	lineFollowUntilLine(20,rightSensor,rightEdge,black,true);
	driveEncoderDistance(-20,-20,1,true);
	moveLeftAttachmentMotorDegrees (50,-90,true);
	centerTurnUsingGyro(25,90,true);
	driveEncoderDistance(30,30,4,true);
	driveEncoderDistance(-30,-30,4,true);
	moveLeftAttachmentMotorDegrees (50,90,true);


}

// This mission does the end mission
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

	// Sound that it found the black line
	playSound(soundBlip);

	// No more line to follow, drive straight using the encoder
	driveStraightEncoderDistance(20, 13, true);

	// Center turn to line up with Cargo Connect
	centerTurnUsingGyro(10, 90, true);

	// Backup to be in the cargo connect circle
	driveStraightEncoderDistance(-10, 2, true);

	// Drop off the cargo in the cargo connect circle
	moveLeftAttachmentMotorDegrees(-400,600,false);

	// Sound that it found the black line
	playSound(soundUpwardTones);

	// Backup
	driveStraightEncoderDistance(-10, 8, true);

	// Turn using the gyro
	sideTurnUsingGyro(10, 70, true);

	// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, white, true);

	// Turn to the right until we see black.
	sideTurnUntilLine(10, rightSensor, black, true);

	// Line follow for a to get into position
	lineFollowForDistance (10, 2, rightSensor, leftEdge, false);

	// Line follow until white
	lineFollowUntilLine(10, rightSensor, leftEdge, white, false);

	// Line follow until Black
	lineFollowUntilLine(10, rightSensor, leftEdge, black, false);

	// Sound that it found the black line
	playSound(soundBlip);

	// Line follow for a to get into position
	lineFollowForDistance (10, 4, rightSensor, leftEdge, false);

	// Drive straight a bit more
	driveStraightEncoderDistance(10, 3.75, true);

	sleep(200);

	// Center turn to get into position to backup into the wall
	sideTurnUsingGyro(10, -70, true);

	// Backup to get the back wheel aligned with the black line
	driveStraightEncoderDistance(-10, 4.25, true);

	// Turn to the left until we see white.
	sideTurnUntilLine(-10, leftSensor, white, true);

	// Turn to the left until we see black.
	sideTurnUntilLine(-10, leftSensor, black, true);

	// Turn to the left until we see white.
	//sideTurnUntilLine(-10, leftSensor, grey, true);

	// Back up into the wall and coast into the wall
	driveStraightEncoderDistance(-50, 12, false);

	sleep(500);

	// Drive forward a little to be off the wall
	driveStraightEncoderDistance(5, 1, true);

	// Turn toward the ending obstacle
	centerTurnUsingGyro(10, 90, true);

	// Backup to make sure were behind the line
	driveStraightEncoderDistance(-10, 3, true);

	// Look for the white line
	driveStraightUntilLine(10, rightSensor, white, true);

	// Look for the black line
	driveStraightUntilLine(10, rightSensor, black, true);

	// Look for the gray line
	driveStraightUntilLine(10, rightSensor, grey, true);

	driveStraightEncoderDistance(5, 1.5, true);
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

	// Turn to get into position for the switch
	centerTurnUsingGyro(10, 30, true);

	// Move the arm down to prepare to do the switch
	moveLeftAttachmentMotorDegrees(50,-350,false);

	// Turn to get into position for the switch
	centerTurnUsingGyro(10, 15, true);

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

void pushBlueBoxMission()
{


		driveStraightEncoderDistance(50, 25, true);


		driveStraightEncoderDistance(-75, 24, false);

}



void secondCenterMission()
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

	// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, grey, true);

	// Lower arms to get second truck
	moveRightAttachmentMotorDegrees(100,-600,false);

	// Push second truck forward
	lineFollowForDistance (10, 7.75, rightSensor, rightEdge, true);

	// Raise arm to detach from second truck
	moveRightAttachmentMotorDegrees(100,600,false);

	// Push first half of the bridge down
	lineFollowForDistance (10, 7, rightSensor, rightEdge, true);

	// Line follow until white
	lineFollowUntilLine(10, rightSensor, rightEdge, white, false);

	// Line follow until Black
	lineFollowUntilLine(10, rightSensor, rightEdge, black, false);

	// Sound that it found the black line
	playSound(soundBlip);

	// Raise arm to avoid second half of bridge
	moveRightAttachmentMotorDegrees(100,400,false);

	// Move to get to the second half of the bridge
	lineFollowForDistance (10, 2, rightSensor, rightEdge, false);

	// knock down second half of bridge
	driveStraightEncoderDistance(10, 2, true);

	// Lower arm to be able to knock down second half of bridge
	moveRightAttachmentMotorDegrees(100,-450,false);

	// knock down second half of bridge
	driveStraightEncoderDistance(-10, 2, true);

	// Raise arm to avoid truck
	moveRightAttachmentMotorDegrees(100,200,false);

	// Drive back to base
	driveStraightEncoderDistance(-75,50,false);


}
