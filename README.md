# Dynamic Parking System in C++

This project implements a **dynamic parking management system** in C++, designed to practice pointers and dynamic memory allocation in a structured, real-world scenario.

## Overview

The system simulates a **multi-level parking lot with flexible dimensions**. Users can manage parking slots dynamically, supporting operations such as parking, unparking, finding cars, and adjusting the parking structure in real-time.

The parking lot structure is as follows:

- **Blocks** – Top-level divisions of the parking area.
- **Rows per block** – Each block contains multiple rows.
- **Slots per row** – Each row has multiple slots for parking vehicles.

All data structures are handled using **pointers** and **dynamic memory allocation**, allowing the system to scale according to user input.

## Features

The system provides the following operations:

1. **Display Parking Area** – Visualize the current parking layout, showing occupied and available slots.
2. **Park a Car** – Assign a car to an available slot.
3. **Un-Park a Car** – Remove a car from its slot.
4. **Find a Car** – Search for a car in the parking lot.
5. **Smart Parking** – Park cars intelligently to optimize space usage.
6. **Increase Number of Slots** – Expand slots dynamically in a row.
7. **Decrease Number of Slots** – Reduce slots dynamically if needed.
8. **Exit** – Safely exit the system.

## Implementation Details

- **Pointers** – All elements (blocks, rows, slots) are managed via pointers to demonstrate mastery of pointer operations.
- **Dynamic Memory** – Memory for blocks, rows, and slots is allocated and deallocated dynamically to ensure efficient resource usage.
- **Functions** – Each feature is implemented in a dedicated function for modularity and readability.
- **Data Structure** – The parking system uses a hierarchical dynamic array:
  
```cpp
// Example of dynamic allocation structure
int ***parkingLot; // Pointer to blocks -> rows -> slots
