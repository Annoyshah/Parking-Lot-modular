#include<bits/stdc++.h>
#include "./Floor.h"
#include "./ParkingLot.h"
using namespace std;

void commandLoop() {
    string command;
    ParkingLot *parkingLot = nullptr;

    while (cin >> command) {
        if (command == "create_parking_lot") {
            string lot_id;
            int no_of_floors, no_of_slots_per_floor;
            cin >> lot_id >> no_of_floors >> no_of_slots_per_floor;
            parkingLot = new ParkingLot(lot_id, no_of_floors, no_of_slots_per_floor);
            cout << "Created parking lot with " << no_of_floors << " floors and " << no_of_slots_per_floor << " slots per floor" << endl;
        } else if (command == "park_vehicle") {
            string vehicle_type, reg_no, color;
            cin >> vehicle_type >> reg_no >> color;
            string ticket_id;
            if (parkingLot->parkVehicle(vehicle_type, reg_no, color, ticket_id)) {
                cout << "Parked vehicle. Ticket ID: " << ticket_id << endl;
            } else {
                cout << "Parking Lot Full" << endl;
            }
        } else if (command == "unpark_vehicle") {
            string ticket_id;
            cin >> ticket_id;
            string reg_no, color;
            if (parkingLot->unparkVehicle(ticket_id, reg_no, color)) {
                cout << "Unparked vehicle with Registration Number: " << reg_no << " and Color: " << color << endl;
            } else {
                cout << "Invalid Ticket" << endl;
            }
        } else if (command == "display") {
            string display_type, vehicle_type;
            cin >> display_type >> vehicle_type;
            if (display_type == "free_count") {
                parkingLot->displayFreeCount(vehicle_type);
            } else if (display_type == "free_slots") {
                parkingLot->displayFreeSlots(vehicle_type);
            } else if (display_type == "occupied_slots") {
                parkingLot->displayOccupiedSlots(vehicle_type);
            }
        } else if (command == "exit") {
            break;
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    commandLoop();
    return 0;
}