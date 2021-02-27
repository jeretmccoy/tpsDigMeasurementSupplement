#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std; 

tagPOINT iPos, newPos;
bool print = false;
double distance(tagPOINT iPos, tagPOINT pos)
{
	double d = (iPos.x - pos.x) * (iPos.x - pos.x);
	double c = (iPos.y - pos.y) * (iPos.y - pos.y);
	d = sqrt(d + c);
	return d; 
}

void NewPosLoop()
{
	while (true) {
		GetCursorPos(&newPos);
		cout << "\r";
		cout << "Press A to measure from, S to end measurement.       ";
		if (print) {
			cout <<"dist: " << distance(iPos, newPos) << "     ";	 
		}
		if (GetAsyncKeyState(0x53) != 0)
		{
			print = false; 
		}
	}
}

int main()
{


	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(NewPosLoop), NULL, NULL, NULL);
	while (true) {
		if (GetAsyncKeyState(0x41) != 0)
		{
			GetCursorPos(&iPos);
			print = true; 
		}
	}
    return 0;
}

