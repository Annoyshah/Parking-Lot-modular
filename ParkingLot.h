#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <string>
#include <vector>
#include "Floor.h"

class ParkingLot {
public:
    std::string id;
    std::vector<Floor> floors;

    ParkingLot(std::string _id, int no_of_floors, int no_of_slots_per_floor);

    bool parkVehicle(std::string vehicle_type, std::string reg_no, std::string color, std::string &ticket_id);

    bool unparkVehicle(std::string ticket_id, std::string &reg_no, std::string &color);

    void displayFreeCount(std::string vehicle_type);

    void displayFreeSlots(std::string vehicle_type);

    void displayOccupiedSlots(std::string vehicle_type);
};

#endif // PARKINGLOT_H
