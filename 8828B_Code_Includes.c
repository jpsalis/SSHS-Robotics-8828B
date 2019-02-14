// takes a left and right val and sets to appropriate port
void move(float left, float right)
{
	motor[leftFront] = left;
	motor[leftBack] = left;
	motor[rightFront] = right;
	motor[rightBack] = right;
}

void turn (int deg)
{
	deg = deg * 7.3;
	nMotorEncoder[leftBack] = 0;
	nMotorEncoder[rightBack] = 0;
	if(deg > 0)
	{
		while(nMotorEncoder[leftBack] < deg)
		{
			move(45, -45);
		}
	}
	else if (deg < 0)
	{
		while(nMotorEncoder[leftBack] > deg)
		{
			move(-45, 45);
		}
	}
	move(0, 0);
}

void moveDistance(int position)
{
	nMotorEncoder[leftBack] = 0;
	nMotorEncoder[rightBack] = 0;
	if(position > 0)
	{
		while(nMotorEncoder[leftBack] < position && nMotorEncoder[rightBack] < position)
		{
			move(70, 70);
		}
	}
	else if (position < 0)
	{
		while(nMotorEncoder[leftBack] > position  && nMotorEncoder[rightBack] > position)
		{
			move(-70, -70);
		}
	}
	move(0, 0);
}


void lift(float speed)
{
	motor[liftMotorBottom] = speed;
	motor[liftMotorTop] = speed;
}


void liftWithEnc(float position)
{
	if(position > SensorValue[liftEnc])
	{
		while(SensorValue[liftEnc] < position)
		{
			lift(127);
		}
	}
	else if (position > SensorValue[liftEnc])
	{
		lift(-65);
	}
	lift(0);
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
