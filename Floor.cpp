#include "Floor.h"

Slot::Slot(std::string _type) : type(_type), occupied(false) {}

Floor::Floor(int no_of_slots_per_floor) {
    slots.push_back(Slot("TRUCK"));
    slots.push_back(Slot("BIKE"));
    slots.push_back(Slot("BIKE"));
    for (int i = 3; i < no_of_slots_per_floor; ++i) {
        slots.push_back(Slot("CAR"));
    }
}

int Floor::getFreeSlotCount(std::string vehicle_type) {
    int count = 0;
    for (auto &slot : slots) {
        if (slot.type == vehicle_type && !slot.occupied) count++;
    }
    return count;
}

std::vector<int> Floor::getFreeSlots(std::string vehicle_type) {
    std::vector<int> free_slots;
    for (int i = 0; i < slots.size(); ++i) {
        if (slots[i].type == vehicle_type && !slots[i].occupied) {
            free_slots.push_back(i + 1);
        }
    }
    return free_slots;
}

std::vector<int> Floor::getOccupiedSlots(std::string vehicle_type) {
    std::vector<int> occupied_slots;
    for (int i = 0; i < slots.size(); ++i) {
        if (slots[i].type == vehicle_type && slots[i].occupied) {
            occupied_slots.push_back(i + 1);
        }
    }
    return occupied_slots;
}
