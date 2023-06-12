#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>

#pragma once

#include <string>

class Flight {
private:
    std::string flightNumber;
    std::string destination;
    std::string date;
    std::string time;

public:
    Flight(const std::string& number, const std::string& dest, const std::string& flightDate, const std::string& departureTime)
        : flightNumber(number), destination(dest), date(flightDate), time(departureTime) {}

    std::string getFlightInfo() const {
        return "Flight Number: " + flightNumber + ", Destination: " + destination + ", Date: " + date + ", Departure Time: " + time;
    }

    std::string getFlightNumber() const {
        return flightNumber;
    }

    std::string getDestination() const {
        return destination;
    }

    std::string getDate() const {
        return date;
    }

    std::string getTime() const {
        return time;
    }
};

std::vector<std::string> processFlightsData(const std::string& filePath, const std::string& date, const std::string& destination) {
	std::vector<std::string> foundFlights;

	// Open the file
	std::ifstream file(filePath);

	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string flightNumber, flightDestination, flightDate, flightTime;

		// Parse the flight information from the line
		if (iss >> flightNumber >> flightDestination >> flightDate >> flightTime) {
			// Check if the flight matches the provided date and destination
			if (flightDate == date && flightDestination == destination) {
				foundFlights.push_back(flightNumber);
			}
		}
	}

	// Close the file
	file.close();

	return foundFlights;
}