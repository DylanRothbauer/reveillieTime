/*
  @ a program that calculates a soldiers Retreat time for the night.
  @ Dylan Rothbauer
  @ 2-22-22
*/

#include <iostream>>
#include <string>
using namespace std;

int main() {

	int reveillieTime;
	int reveillieHours;
	int reveillieMinutes;
	bool flag = false;
	bool flag2 = false;


	do {
		flag = false;
		cout << "Please enter Reveille time: ";
		cin >> reveillieTime;

		if (cin.fail()) {
			cout << "Military Time Format Required: Bad input, try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			flag = true;
		}
		else {
			reveillieHours = reveillieTime / 100;
			reveillieMinutes = reveillieTime % 100;
			if ((reveillieTime < 0) || (reveillieHours < 0) || (reveillieHours > 23)) {
				cout << "Military Time Format Required: Hours must be between 00 and 23, try again" << endl;
				flag = true;

			}
			else if (reveillieMinutes < 0 || reveillieMinutes > 59) {
				cout << "Military Time Format Required: Minutes must be between 00 and 59, try again" << endl;
				flag = true;
			}
		}
		
	} while (flag);
		
	// leading 0's for formatting
	cout << "Reveille Time ";
	if (reveillieTime < 10) {
		cout << "000" << reveillieTime;
	}
	else if (reveillieTime < 60) {
		cout << "00" << reveillieTime;
	}
	else if (reveillieTime < 1000) {
		cout << "0" << reveillieTime;
	} 
	cout << " hours accepted." << endl;


	int sleepDuration;
	int sleepHours;
	int sleepMinutes;
	
	do {
		flag2 = false;
		cout << "Please enter sleep duration: ";
		cin >> sleepDuration;

	if (cin.fail()) {
		cout << "Duration Format HHMM Required: Bad input, try again." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		flag = true;
	}
	else {
		sleepHours = sleepDuration / 100;
		sleepMinutes = sleepDuration % 100;
		if ((sleepDuration < 0) || (sleepHours < 0) || (sleepHours > 23)) {
			cout << "Duration Format HHMM Required: Hours must be between 00 and 23, try again" << endl;
			flag = true;

		}
		else if (sleepMinutes < 0 || sleepMinutes > 59) {
			cout << "Duration Format HHMM Required: Minutes must be between 00 and 59, try again" << endl;
			flag = true;
		}
	}

} while (flag);

	cout << "Sleep Duration of " << sleepHours << " hour(s) and " << sleepMinutes << " minute(s) accepted." << endl;

	int retreatTime;
	int newRMinutes;
	int newSMinutes;
	int retreatHours;
	int retreatMinutes;
	int retreatTimeMinutes;

	newRMinutes = (reveillieHours * 60) + reveillieMinutes; // converting reveillieTime to minutes
	newSMinutes = (sleepHours * 60) + sleepMinutes;

	retreatTimeMinutes = newRMinutes - newSMinutes; // getting both reveillie time and sleed duration in total minutes

	if (retreatTimeMinutes < 0) {
		retreatTimeMinutes += 1440;
	}

	retreatHours = retreatTimeMinutes / 60; // converting back to (HHMM) format
	retreatMinutes = retreatTimeMinutes % 60;


	// The code below is me troubleshooting the hours for my civilian time

	cout << "Retreat time at " << retreatHours << retreatMinutes << " (or ";

	retreatHours = reveillieTime / 100;
	retreatMinutes = reveillieTime % 100;

	if ((retreatHours < 12) || (retreatHours < 12 && retreatMinutes < 60)) {
		if (retreatMinutes < 10) {
			cout << retreatHours << ":" << "0" << retreatMinutes << "am)" << endl;
		}
	}
	else {
		cout << retreatHours << ":" << "00" << retreatMinutes << "pm)" << endl;
	}

	cout << "Lights out soldier!" << endl;

	return 0;
}