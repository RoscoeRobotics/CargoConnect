# CargoConnect
Cargo Connect Robot C Code

This it the robot setup for the code:

Sensors
----------------------------------------------------------------
	Sensor 1 - Left Color Sensor

	Sensor 2 - Extra Color Sensor

	Sensor 3 - Gyro Sensor

	Sensor 4 - Right Color Sensor

Motors
----------------------------------------------------------------
	Motor A - Left Attachment Motor

	Motor B - Right Drive Motor 
	
	Motor C - Left Drive Motor

	Motor D - Right Attachment Motor 


Driving Functions
----------------------------------------------------------------
**driveEncoderDistance(leftspeed, rightSpeed, inchesToMove, brakeMode)**

	leftSpeed	Float	Speed of left wheel
	
	rightSpeed	Float	Speed of the right wheel
	
	inchesToMove	Float	Distance to move
	
	brakeMode	Bool	True = Turn on brakes at the end;  False = Coast at the end
	


**driveStraightEncoderDistance(speed, inchesToMove, brakeMode)**

	speed		Float	speed of both wheels 
	
	inchesToMove	Float	Distance to move
	
	brakeMode	Bool	True = Turn on brakes at the end;  False = Coast at the end



**sideTurnEncoder(speed, degreesToTurn, brakeMode)**

	speed		Float	speed to turn the outer wheel
	
	degreesToTurn	Float	degrees to turn the robot
	
	brakeMode	Bool	True = Turn on brakes at the end;  False = Coast at the end



**centerTurnEncoder(speed, degreesToTurn, brakeMode)**

	speed		Float	speed to turn one wheel forward and one wheel backwards
	
	degreesToTurn	Float	degrees to turn the robot
	
	brakeMode	Bool	True = Turn on brakes at the end;  False = Coast at the end



**driveStraightGyroDistance(speed, inchesToMove, direction, brakeMode)**

	speed		Float	speed of both wheels 

	inchesToMove	Float	Distance to move
	
	direction	float	Direction to head in using the gyroscope.  
	
	brakeMode	Bool	True = Turn on brakes at the end;  False = Coast at the end



**centerTurnUsingGyro(speed, degreesToTurn, brakeMode)**

	speed		Float	speed to turn one wheel forward and one wheel backwards

	degreesToTurn	Float	degrees to turn the robot
	
	brakeMode	Bool	True = Turn on brakes at the end;  False = Coast at the end



**sideTurnUsingGyro(speed, degreesToTurn, brakeMode)**

	speed		Float	speed to turn the outer wheel
	
	degreesToTurn	Float	degrees to turn the robot
	
	brakeMode	Bool	True = Turn on brakes at the end;  False = Coast at the end



**lineFollowForDistance(speed, inchesToMove, colorSensorToUse, edgeToUse, brakeMode)**

	speed		Float	speed of both wheels 
	
	inchesToMove	Float	Distance to move

	colorSensorToUse string	Color sensor used to line folllow - opposite for line detection		"left", "right"         
	
	edgeToUse	string	follow on left edge or right edge					"left", "right"   
	
	brakeMode	Bool	True = Turn on brakes at the end;  False = Coast at the end


    
**lineFollowUntilLine(speed, colorSensorToUse, edgeToUse, colorToLookFor, brakeMode, )**

	speed 		Float	Speed to Drive
	
	colorSensorToUse string	Color sensor used to line folllow - opposite for line detection		"left", "right"        
	
	edgeToUse	string	follow on left edge or right edge					"left", "right"
	
	colorToLookFor	Int	Look for a white line or a black line					"white", "black"  
	
	brakeMode	Bool	Apply brakes or not							true; false
