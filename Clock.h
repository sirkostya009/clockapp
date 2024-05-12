#pragma once
#include <array>
#include <string>

using namespace System;

class Clock {
private:
	const char* timezones[25] = {
		"GMT-12", "GMT-11", "GMT-10", "GMT-9", "GMT-8", "GMT-7", "GMT-6", "GMT-5", "GMT-4", "GMT-3", "GMT-2", "GMT-1",
		"GMT", "GMT+1", "GMT+2", "GMT+3", "GMT+4", "GMT+5", "GMT+6", "GMT+7", "GMT+8", "GMT+9", "GMT+10", "GMT+11", "GMT+12",
	};

    const char* timezoneDescription[25] = {
        "New Zealand",
        "Some shit idfk",
        "Hawaii, French Polynesia, Jarvis Island",
        "Some shit idfk",
        "Alaska",
        "California, Washington, British Columbia",
        "Mexico, New Mexico",
        "Texas, Chicago",
        "Venezuela, Chile, Bolivia",
        "Brazil, Argentina",
        "Atlantis",
        "Greenland, Portugal",
        "Iceland",
        "Britain, Iceland",
        "Germany, Poland, France",
        "Israel, Ukraine, Turkey",
        "Saudi Arabia",
        "Pakistan, India",
        "Bangladesh, Myanmar",
        "Thailand, Vietnam",
        "China, Philippines",
        "Japan, Korea",
        "Australia, Papua New Guinea",
        "New Caledonia, Fiji, Tonga",
        "New Zealand"
    };

    Clock() = default;
public:
    static Clock Instance;

    String^ GetTimezoneDescription(int i) {
        return gcnew String(timezoneDescription[i + 12]);
    }

    String^ GetTimezoneString(int i) {
        return gcnew String(timezones[i + 12]);
    }

    String^ FormatTime(String^ format, int timezone = 0) {
        return DateTime::UtcNow.AddHours(timezone).ToString(format);
    }
};

Clock Clock::Instance;
