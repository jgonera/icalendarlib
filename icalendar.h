#ifndef _ICALENDAR_H
#define _ICALENDAR_H

#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "types.h"

using namespace std;

class ICalendar {
public:
	ICalendar(const char *FileName): FileName((char *)FileName) { LoadFromFile(); }
	~ICalendar() {
		for_each(Events.begin(), Events.end(), DeleteItem());
	}
	void LoadFromFile();

	//Event* GetEventByUID(char *UID);

	void AddEvent(Event *NewEvent);
	void DeleteEvent(Event *DeletedEvent);
	void ModifyEvent(Event *ModifiedEvent);

	class Query;
	
private:
	string GetProperty(const string &Line) const {
		// if VALUE=DATE or VALUE=DATE-TIME used, then the date is not directly
		// after the property name so we just search for the string after ':'
		string Temp = Line.substr(Line.find_first_of(':')+1);
		unsigned int Length = Temp.length();
		if (Length > 0 && Temp[Length-1] == '\r')
			Temp.resize(Length-1);
		return Temp;
	}
	string GetSubProperty(const string &Line, const char *SubProperty) const {
		size_t Pos = Line.find(SubProperty);
		if (Pos == string::npos)
			return "";
		Pos += strlen(SubProperty) + 1;
		return Line.substr(Pos, Line.find_first_of(';', Pos)-Pos);
	}
	void FixLineEnd(string &Line, unsigned int Length) {
		if (Length > 0 && Line[Length-1] == '\r')
			Line.resize(Length-1);
		Line += "\r\n";
	}
	
	char *FileName;
	list<Event *> Events;
};

class ICalendar::Query {
public:
	Query(ICalendar *Calendar): Calendar(Calendar), EventsIterator(Calendar->Events.begin()) {}
	~Query() { for_each(RecurrentEvents.begin(), RecurrentEvents.end(), DeleteItem()); }
	void ResetPosition() {
	  	for_each(RecurrentEvents.begin(), RecurrentEvents.end(), DeleteItem());
	  	RecurrentEvents.clear();
	  	EventsIterator = Calendar->Events.begin();
	}
	Event* GetNextEvent(bool WithAlarm = false);
	
	EventsCriteria Criteria;
	
private:
	ICalendar *Calendar;
	list<Event *> RecurrentEvents;
	list<Event *>::iterator EventsIterator;
};

inline TimeUnit ConvertFrequency(string Name) {
	if (Name == "SECONDLY")
		return SECOND;
	if (Name == "MINUTELY")
		return MINUTE;
	if (Name == "HOURLY")
		return HOUR;
	if (Name == "DAILY")
		return DAY;
	if (Name == "WEEKLY")
		return WEEK;
	if (Name == "MONTHLY")
		return MONTH;
	
	return YEAR;
}

inline AlarmAction ConvertAlarmAction(string Name) {
	if (Name == "AUDIO")
		return AUDIO;
	if (Name == "PROCEDURE")
		return PROCEDURE;
	if (Name == "EMAIL")
		return EMAIL;
	
	return DISPLAY;
}

#endif // _ICALENDAR_H
