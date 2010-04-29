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
	
	cout << a.Difference(b, HOUR) << endl;
	
//  ICalendar Calendar("../Calendar.ics");
//  Event *CurrentEvent;
//  ICalendar::Query SearchQuery(&Calendar);
//
//	srand(time(NULL));
//
//	SearchQuery.Criteria.From = "20080627T000000";
//	SearchQuery.Criteria.To = "20080627T235959";
////	SearchQuery.Criteria.To[HOUR] = 23;
////	SearchQuery.Criteria.To[MINUTE] = 59;
////	SearchQuery.Criteria.To[SECOND] = 59;
//
//	SearchQuery.ResetPosition();
//
//  while ((CurrentEvent = SearchQuery.GetNextEvent(false)) != NULL) {
//  	cout << CurrentEvent->UID << endl;
//    cout << CurrentEvent->DtStart.Format() << endl;
//    cout << CurrentEvent->DtEnd.Format() << endl;
//    cout << CurrentEvent->Summary << endl;
//    cout << CurrentEvent->Categories << endl;
//    cout << "\t" << CurrentEvent->RRule.Freq << endl;
//    cout << "\t" << CurrentEvent->RRule.Interval << endl;
//    cout << "\t" << CurrentEvent->RRule.Until << endl << endl;
//
////    CurrentEvent->BaseEvent->Description = "aasfjanfkjahsf";
////    Calendar.ModifyEvent(CurrentEvent->BaseEvent);
//  }
//
//  Event *NewEvent = new Event;
//  NewEvent->Summary = "test";
//  Calendar.AddEvent(NewEvent);

//	Date a;
//
//	a = "20080625T132400";
//	a[MINUTE] -= 25;
//
//	cout << a << endl;

  return 0;
}
