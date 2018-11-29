// takes a left and right val and sets to appropriate port
void move(float left, float right)
{
	motor[leftFront] = left;
	motor[leftBack] = left;
	motor[rightFront] = right;
	motor[rightBack] = right;
}


void driveControl(int toggleState)
{
		if (toggleState)
			move((vexRT[Ch3] * 0.5) + (vexRT[Ch4] * 0.5), (vexRT[Ch3] * 0.5) - (vexRT[Ch4] * 0.5));
		else
			move((vexRT[Ch3] * 0.6) + (vexRT[Ch4] * 0.6), (vexRT[Ch3] * 0.6) - (vexRT[Ch4] * 0.6));
}
