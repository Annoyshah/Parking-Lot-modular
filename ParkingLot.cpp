#include "ParkingLot.h"
#include <sstream>
#include <iostream>

ParkingLot::ParkingLot(std::string _id, int no_of_floors, int no_of_slots_per_floor) : id(_id) {
    for(int i = 0; i < no_of_floors; ++i) {
        floors.push_back(Floor(no_of_slots_per_floor));
    }
}

bool ParkingLot::parkVehicle(std::string vehicle_type, std::string reg_no, std::string color, std::string &ticket_id) {
    for (int i = 0; i < floors.size(); ++i) {
        for (int j = 0; j < floors[i].slots.size(); ++j) {
            if (floors[i].slots[j].type == vehicle_type && !floors[i].slots[j].occupied) {
                floors[i].slots[j].occupied = true;
                ticket_id = id + "_" + std::to_string(i + 1) + "_" + std::to_string(j + 1);
                return true;
            }
        }
    }
    return false;
}

bool ParkingLot::unparkVehicle(std::string ticket_id, std::string &reg_no, std::string &color) {
    std::stringstream ss(ticket_id);
    std::string lot_id, floor_no_str, slot_no_str;
    getline(ss, lot_id, '_');
    getline(ss, floor_no_str, '_');
    getline(ss, slot_no_str);

    int floor_no = std::stoi(floor_no_str) - 1;
    int slot_no = std::stoi(slot_no_str) - 1;

    if (lot_id == id && floor_no < floors.size() && slot_no < floors[floor_no].slots.size() && floors[floor_no].slots[slot_no].occupied) {
        floors[floor_no].slots[slot_no].occupied = false;
        return true;
    }
    return false;
}

void ParkingLot::displayFreeCount(std::string vehicle_type) {
    for (int i = 0; i < floors.size(); ++i) {
        std::cout << "No. of free slots for " << vehicle_type << " on Floor " << i + 1 << ": " << floors[i].getFreeSlotCount(vehicle_type) << std::endl;
    }
}

void ParkingLot::displayFreeSlots(std::string vehicle_type) {
    for (int i = 0; i < floors.size(); ++i) {
        std::vector<int> free_slots = floors[i].getFreeSlots(vehicle_type);
        std::cout << "Free slots for " << vehicle_type << " on Floor " << i + 1 << ": ";
        if (!free_slots.empty()) {
            for (int slot : free_slots) {
                std::cout << slot << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "None" << std::endl;
        }
    }
}

void ParkingLot::displayOccupiedSlots(std::string vehicle_type) {
    for (int i = 0; i < floors.size(); ++i) {
        std::vector<int> occupied_slots = floors[i].getOccupiedSlots(vehicle_type);
        std::cout << "Occupied slots for " << vehicle_type << " on Floor " << i + 1 << ": ";
        if (!occupied_slots.empty()) {
            for (int slot : occupied_slots) {
                std::cout << slot << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "None" << std::endl;
        }
    }
}
