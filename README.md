# Parking-System
Dynamic Parking System in C++

This project implements a dynamic parking management system in C++, designed to practice pointers and dynamic memory allocation in a structured, real-world scenario.

Overview

The system simulates a multi-level parking lot with flexible dimensions. It allows users to manage parking slots dynamically, supporting various operations such as parking, unparking, finding cars, and adjusting the parking structure in real-time.

The parking lot is organized as:

Blocks: The top-level division of the parking area.

Rows per block: Each block contains multiple rows.

Slots per row: Each row has multiple slots for parking vehicles.

All the data structures are managed using pointers and dynamic memory allocation, allowing the system to scale based on user input.

Features

The system provides the following operations:

Display Parking Area – Visualize the current parking layout with occupied and available slots.

Park a Car – Assign a car to an available slot.

Un-Park a Car – Remove a car from its slot.

Find a Car – Search for a car within the parking lot.

Smart Parking of Car – Park cars intelligently to optimize space usage.

Increase Number of Slots – Dynamically expand the number of slots in a row.

Decrease Number of Slots – Reduce slots dynamically if required.

Exit – Safely exit the system.

Implementation Details

Pointers: All parking lot elements (blocks, rows, slots) are managed via pointers to demonstrate mastery of pointer operations.

Dynamic Memory: Memory for blocks, rows, and slots is allocated and deallocated dynamically, ensuring efficient resource usage.

Functions: Each feature is encapsulated in a dedicated function to improve modularity and readability.

Data Structure: The parking system uses a hierarchical dynamic array:
