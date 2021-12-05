//----------------------------------------------------------------------------------------------------
// Name: driveEncoderDistance
//----------------------------------------------------------------------------------------------------
// Description:
// 	This function takes a left speed, right speed, rotations to move and the brake mode
// 	and then drives at the speed for each motor for the number of rotations.
// 	When it is finished, it then sets the brakes or coasts depending on the brake mode.
//      The wheel diameter of the robot is 62.4mm, which is 2.456693 inches.
//      Wheel circumfrence is Pi x Diameter = 2.456693 x 3.14159 = 7.717922162 inches per ratation.
//----------------------------------------------------------------------------------------------------
//Inputs:
//	leftSpeed	Float	Speed of left wheel
//	rightSpeed	Float	Speed of the right wheel
//	rotations	Float	Distance to move
//	brakeMode	Bool	True = Turn on brakes at the end;  False = Coast at the end
//----------------------------------------------------------------------------------------------------
void driveEncoderDistance(float leftspeed, float rightSpeed, float inchesToMove, bool brakeMode)
{

	float degreesToMove;
	float rotationsToMove;

	rotationsToMove = inchesToMove / 7.717922162;

	// Always make sure rotations is positive.  If it is negative, ignore it.   Needs to have negative speed to go backwards.
	if (rotationsToMove < 0)
	{
			rotationsToMove = -rotationsToMove;
	}

	// Compute the number of degrees to move.
	degreesToMove = 360 * rotationsToMove;

	setBrakeMode(brakeMode);

	// Reset the Motor Encoders
	resetDriveMotorEncoders();

	// Start Motors with the proper speed.
	setMotorSpeed(leftDrive, leftspeed);
	setMotorSpeed(rightDrive, rightSpeed);


	// Wait until the left motor encoder is greater than or equal to the degrees to move.
	while (abs(getLeftMotorEncoder()) <= degreesToMove)
	{

	}



	turnOffDriveMotors();





}



//----------------------------------------------------------------------------------------------------
// Name:   driveStraightEncoderDistance
//----------------------------------------------------------------------------------------------------
// Description: we always make sure that the roatations is positive and compute the numbers of degreesToMove
// we remove the brakes and reset the motor encoders. we then turn off drive motors and set brake mode
//----------------------------------------------------------------------------------------------------
//Inputs: speed    			float           speed we want to go at
//        inchesToMove      float           inches we want to move
//        brakeMode         bool            coast or brake
//----------------------------------------------------------------------------------------------------
void driveStraightEncoderDistance(float speed, float inchesToMove, bool brakeMode)
{

	float error;
	float correctionFactor;
	float speedLeft;
	float speedRight;
	float degreesToMove;
	float rotationsToMove;

	rotationsToMove = inchesToMove / 7.717922162;

	// Always make sure rotations is positive.
	if (rotationsToMove < 0)
	{
			rotationsToMove = -rotationsToMove;
	}

	// Compute the number of degrees to move.
	degreesToMove = 360 * rotationsToMove;

	setBrakeMode(brakeMode);

	// Reset the Motor Encoders
	resetDriveMotorEncoders();

	while (abs(getLeftMotorEncoder()) <= degreesToMove)
	{
		error = abs(getLeftMotorEncoder()) - abs(getRightMotorEncoder());
		correctionFactor = error * .01;
		speedLeft = speed - correctionFactor;
		speedRight = speed + correctionFactor;

		setMotorSpeed(leftDrive, speedLeft);
		setMotorSpeed(rightDrive, speedRight);


	}

	turnOffDriveMotors();


}

//----------------------------------------------------------------------------------------------------
// Name:   driveStraightUntilLine
//----------------------------------------------------------------------------------------------------
// Description:
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
void driveStraightUntilLine(float speed, string colorSensorToUse, string colorToLookFor, bool brakeMode)
{

	float error;
	float correctionFactor;
	float speedLeft;
	float speedRight;

	float lightLevelToLookFor;
	float colorSensorDetecting;
	bool foundLine;


	// Compute the limtis for stopping;
	if (colorToLookFor == "white")     // Look for white
  {
    lightLevelToLookFor = reflectedLightIntensityOnWhite - 10;
  }
  else if (colorToLookFor == "black")     // Look for black
  {
    lightLevelToLookFor = reflectedLightIntensityOnBlack + 10;
  }
  else
	{
    lightLevelToLookFor = ((reflectedLightIntensityOnWhite + reflectedLightIntensityOnBlack) / 2);

	}


	// Get the initial current value based upon which sensor to use - Use the one not using for the line following
	if (colorSensorToUse == "leftSensor")				// Use the left color sensor
	{
		colorSensorDetecting = getColorReflected(leftColor);
	}
	else																				// Use the right color sensor
	{
		colorSensorDetecting = getColorReflected(rightColor);
	}

	// Set the foundline variable to false
	foundLine = false;

	// Turn on brakes or coast
	setBrakeMode(brakeMode);

	// Reset the Motor Encoders
	resetDriveMotorEncoders();

	while (!foundLine)
	{

		// Control speed with a proportiional controller getting the encoders to match distance
		error = abs(getLeftMotorEncoder()) - abs(getRightMotorEncoder());
		correctionFactor = error * .01;
		speedLeft = speed - correctionFactor;
		speedRight = speed + correctionFactor;

		setMotorSpeed(leftDrive, speedLeft);
		setMotorSpeed(rightDrive, speedRight);


		// Read the correct color sensor
		if (colorSensorToUse == "leftSensor")				// Use the left color sensor
		{
			colorSensorDetecting = getColorReflected(leftColor);
		}
		else														// Use the right color sensor
		{
			colorSensorDetecting = getColorReflected(rightColor);
		}


		// Dtecting if we found the line
		if (colorToLookFor == "white")
		{
			if (colorSensorDetecting > lightLevelToLookFor) foundLine = true;
		}
		else if (colorToLookFor == "black")
		{
			if (colorSensorDetecting < lightLevelToLookFor) foundLine = true;
		}
		else				//Assume grey
		{
			if ((colorSensorDetecting > lightLevelToLookFor - 10) && (colorSensorDetecting < lightLevelToLookFor + 10))  foundLine = true;
		}


	}

	turnOffDriveMotors();

}
