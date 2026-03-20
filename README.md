<div align="center">

# 🅿️ SMART PARKING SYSTEM

### *A real-time graphical parking management system built in C++ with SFML*

<br>

![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![SFML](https://img.shields.io/badge/SFML-2.x-8CC445?style=for-the-badge&logo=sfml&logoColor=white)
![Dynamic Memory](https://img.shields.io/badge/Memory-4D_Dynamic_Array-9B59B6?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-lightgrey?style=for-the-badge)

<br>

> *Multi-block layout · License plate tracking · Smart allocation · Live occupancy bars · Toast notifications*

<br>

---

</div>

## 🌟 Features at a Glance

<div align="center">

| 🟢 Park | 🔴 Unpark | 🔍 Find | ⚡ Smart Park |
|:---:|:---:|:---:|:---:|
| Park by block / row / slot | Remove by exact location | Search by license plate | Auto-finds nearest empty slot |

| 📈 Grow Slots | 📉 Shrink Slots | 👁️ View Lot | 🔔 Toasts |
|:---:|:---:|:---:|:---:|
| Expand any row dynamically | Shrink if trailing slots empty | Full visual board with bars | Live feedback notifications |

</div>

---

## 🖥️ UI Panels

The application opens at **1280 × 780** with a dark navy theme and a **7-button sidebar**. Each button switches the right panel:

| # | Panel | Colour | Description |
|:---:|:---|:---:|:---|
| 1 | **View Lot** | 🔵 Cyan | Scrollable visual board — all blocks, rows, slots |
| 2 | **Park Vehicle** | 🟢 Green | Enter block / row / slot + license plate |
| 3 | **Unpark** | 🔴 Red | Remove vehicle by exact location |
| 4 | **Find Vehicle** | 🔵 Cyan | Search the entire lot by license plate |
| 5 | **Smart Park** | 🟡 Yellow | Auto-allocate nearest empty slot to a block |
| 6 | **Grow Slots** | 🔵 Cyan | Increase slot count for any row |
| 7 | **Shrink Slots** | 🔴 Red | Decrease slot count (only if trailing slots empty) |

---

## 🎨 Visual Design

| Element | Detail |
|:---|:---|
| **Background** | Deep navy `#05080A` — zero eye strain |
| **Accent colour** | Cyan `#00D4FF` — active inputs, labels, borders |
| **Empty slot** | Dark green background + green border + `P` icon |
| **Occupied slot** | Dark red background + red border + `CAR` + plate text |
| **Highlighted slot** | Gold border + gold background — result of Find / Smart Park |
| **Occupancy bar** | Green → Yellow → Red as the block fills up |
| **Toast notifications** | Slide-in top-right messages with 3-second fade timer |

---

## ⚙️ Core Architecture

### Data Structure

The entire lot is stored as a **4-dimensional dynamic `char` array**:

```
char**** ptr
  └── ptr[block][row][slot] → "EMPTY" or "ABC-123" (license plate)
```

Supporting arrays:
```cpp
int*  rpb     // rows per block
int** spb     // slots per block per row
```

### Key Functions

```cpp
void allocateLot(ParkingLot& lot, ...)    // Build full 4D structure at setup
void freeLot(ParkingLot& lot)             // Recursively deallocate everything

bool isSlotEmpty(...)                     // Check if a slot holds "EMPTY"
void emptySlot(...)                       // Write "EMPTY" into a slot

vector<int> findCar(lot, plate)           // Scan all slots → return {b, r, s}
vector<int> smartFind(lot, block)         // Nearest empty slot by Euclidean distance

void growRow(lot, block, row, newSlots)   // Reallocate row with more slots
bool shrinkRow(lot, block, row, newSlots) // Shrink only if trailing slots are empty

void getStats(lot, total, occupied, free) // Aggregate counts across all blocks
```

### Smart Allocation Formula

```cpp
// Each slot's position relative to block entrance:
double x = slot_index  * 8.0;   // 8 ft per slot width
double y = row_index   * 16.0;  // 16 ft per row depth

double distance = sqrt(x*x + y*y);
// → picks the slot with minimum distance
```

---

## 🚀 Setup Flow

```
1. Enter number of blocks
2. Click GENERATE STRUCTURE
3. For each block → enter number of rows + slots per row
4. Click CREATE LOT
5. Full parking dashboard opens
```

---

## 🛠️ How to Build & Run

### 🐧 Linux / 🍎 macOS

```bash
# Clone
git clone https://github.com/Abd-Abdullah83/Parking-System.git
cd Parking-System

# Compile
g++ -std=c++17 CarPark.cpp ParkingClass.cpp -o parking \
    -lsfml-graphics -lsfml-window -lsfml-system

# Run
./parking
```

### 🪟 Windows (MinGW)

```bash
g++ -std=c++17 CarPark.cpp ParkingClass.cpp -o parking.exe ^
    -lsfml-graphics -lsfml-window -lsfml-system

parking.exe
```

> [!NOTE]
> **SFML 2.x** must be installed.
> - Ubuntu → `sudo apt install libsfml-dev`
> - macOS → `brew install sfml`
> - Windows → [sfml-dev.org](https://www.sfml-dev.org/download.php)

> [!WARNING]
> The app searches for a font at startup in this order:
> `arial.ttf` → `fonts/arial.ttf` → `C:/Windows/Fonts/arial.ttf` → system fonts.
> If none are found the program exits with an error. Place `arial.ttf` next to the executable to be safe.

---

## 🕹️ How to Use

### Parking a Vehicle
```
1. Click PARK VEHICLE in the sidebar
2. Enter Block number, Row number, Slot number
3. Enter License plate  e.g. ABC-123
4. Click PARK VEHICLE — green toast confirms success
```

### Smart Parking
```
1. Click SMART PARK
2. Enter the desired Block number + License plate
3. Click FIND + PARK
4. System calculates nearest empty slot automatically
5. Slot highlights in gold on the board
```

### Finding a Vehicle
```
1. Click FIND VEHICLE
2. Enter the license plate
3. Click SEARCH
4. Result shows Block / Row / Slot — highlighted gold on board
```

### Growing / Shrinking a Row
```
GROW   → Enter block, row, new slot count → always succeeds
SHRINK → Enter block, row, new slot count → fails if occupied slots would be removed
```

---

## 📁 Project Structure

```
Parking-System/
│
├── 📄 Output                ← Contains Screenshot of Output
├── 📄 ParkingSystem(SFML)   ← Graphical SFML application
├── 📄 ParkingClass.cpp      ← Core parking logic & data structures
├── 📄 CarPark.cpp           ← Entry point / supporting code
├── 📄 README.md
└── 📄 LICENSE
```

> The app auto-searches for a font — no asset folder required unless `arial.ttf` is not on your system path.

---

## 📐 Technical Highlights

| Concept | Implementation |
|:---|:---|
| **4D dynamic array** | `char****` — blocks → rows → slots → plate string |
| **Manual memory management** | `new` / `delete[]` with full recursive cleanup in `freeLot()` |
| **Dynamic resize** | `growRow()` and `shrinkRow()` reallocate in-place with data preservation |
| **Euclidean smart search** | Minimises `√(x²+y²)` over all empty slots per block |
| **Toast system** | Timed overlay messages with per-operation colour coding |
| **Input validation** | Numbers-only fields enforced at `TextInput` level |
| **Occupancy bar** | Per-block fill bar changes Green → Yellow → Red |

---

<div align="center">

---

### Built by **Abd-Abdullah83**
*FAST National University of Computer & Emerging Sciences (NUCES)*

<br>

*Every slot has a coordinate. Every car has a place.*

</div>
