// test file

#include <iostream>
#include <ctime>
#include <fstream>
#include "icalendar.h"

using namespace std;

int main() {
	Date a, b;
	
	a = "20080627T140000";
	b = "20080626T100000";
	
	a[MINUTE] -= 65;

	cout << a << endl;
	cout << a.Difference(b, HOUR) << endl;
	
	ICalendar Calendar("calendar.ics");
	Event *CurrentEvent;
	ICalendar::Query SearchQuery(&Calendar);

	srand(time(NULL));

	SearchQuery.Criteria.From = "20100927T000000";
	SearchQuery.Criteria.To = "20100927T235959";
	// SearchQuery.Criteria.To[HOUR] = 23;
	// SearchQuery.Criteria.To[MINUTE] = 59;
	// SearchQuery.Criteria.To[SECOND] = 59;

	SearchQuery.ResetPosition();

	while ((CurrentEvent = SearchQuery.GetNextEvent(false)) != NULL) {
		cout << CurrentEvent->UID << endl;
		cout << CurrentEvent->DtStart.Format() << endl;
		cout << CurrentEvent->DtEnd.Format() << endl;
		cout << CurrentEvent->Summary << endl;
		cout << CurrentEvent->Categories << endl;
		cout << "\t" << CurrentEvent->RRule.Freq << endl;
		cout << "\t" << CurrentEvent->RRule.Interval << endl;
		cout << "\t" << CurrentEvent->RRule.Until << endl << endl;

		// CurrentEvent->BaseEvent->Description = "aasfjanfkjahsf";
		// Calendar.ModifyEvent(CurrentEvent->BaseEvent);
	}

	Event *NewEvent = new Event;
	NewEvent->Summary = "test";
	a.SetToNow();
	NewEvent->DtStart = a;
	Calendar.AddEvent(NewEvent);

	return 0;
}
