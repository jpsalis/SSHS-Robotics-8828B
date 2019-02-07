// takes a left and right val and sets to appropriate port
void move(float left, float right)
{
	motor[leftFront] = left;
	motor[leftBack] = left;
	motor[rightFront] = right;
	motor[rightBack] = right;
}
void lift(float speed)
{
	motor[liftMotorBottom] = speed;
	motor[liftMotorTop] = speed;
}

// range must be a positive int
void clawDeadzone(int speed, int range)
{
	if (speed > range)
	{
		motor[claw] = speed - range;
	}
	else if (speed < -range)
	{
		motor[claw] = speed + range;
	}
	else
	{
		motor[claw] = 0;
	}
}
