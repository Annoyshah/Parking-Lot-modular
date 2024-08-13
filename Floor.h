#ifndef FLOOR_H
#define FLOOR_H

#include <string>
#include <vector>

class Slot {
public:
    std::string type;
    bool occupied;

    Slot(std::string _type);
};

class Floor {
public:
    std::vector<Slot> slots;

    Floor(int no_of_slots_per_floor);

    int getFreeSlotCount(std::string vehicle_type);

    std::vector<int> getFreeSlots(std::string vehicle_type);

    std::vector<int> getOccupiedSlots(std::string vehicle_type);
};

#endif // FLOOR_H
