# Dynamic Memory Allocator (Custom Heap Manager)

## Project Overview
This project is a simulation of a **Dynamic Memory Allocator** written in C++.  
It demonstrates how an operating system manages memory allocation and deallocation in a heap using a **First Fit strategy**.  
The program allows users to allocate and free memory interactively while maintaining an updated view of memory status.

---

## Features
- **Interactive simulation** for allocating and freeing memory blocks.
- Implements the **First Fit** allocation strategy.
- Automatically merges **adjacent free blocks** to prevent fragmentation.
- Prevents invalid operations such as double freeing or invalid addresses.
- Displays **real-time memory layout** and total free memory.
- Handles all edge cases, including invalid input or over-allocation.

---

## Data Structures Used
- **Vector of structs:** Used to store memory blocks with start address, size, and allocation status.
- **Custom merging algorithm:** Combines adjacent free blocks after deallocation.

---

## Concepts Demonstrated
- Dynamic memory management simulation.
- First Fit memory allocation algorithm.
- Fragmentation and memory compaction handling.
- Object-oriented programming in C++.
- Input validation and robust console interaction.

---

## How It Works
1. The total memory size is provided by the user.
2. The user can then:
   - Allocate memory of a specific size.
   - Deallocate memory starting at a specific address.
   - View the complete memory layout.
   - Check total free memory remaining.
3. The system automatically merges free blocks when possible.

---

## Example Console Output

```
=== Dynamic Memory Allocator Simulation ===
Enter total memory size: 100

Current Memory Layout:
Start Size Status
0 100 Free

Choose an operation:

Allocate Memory

Deallocate Memory

Display Memory

Show Free Space

Exit
Enter choice: 1
Enter size to allocate: 40
Allocated 40 units at address 0

Current Memory Layout:
Start Size Status
0 40 Allocated
40 60 Free

Enter choice: 2
Enter start address to deallocate: 0
Freed block starting at address 0

Current Memory Layout:
Start Size Status
0 100 Free
```

---

## How to Run
1. Clone this repository or download the source file:
   ```bash
   git clone https://github.com/your-username/Data-Structures-and-Algorithms.git
2. Navigate to the project folder: ```cd Dynamic_Memory_Allocator```
3. Compile and run using any C++ compiler:
   ```
   g++ dynamic_memory_allocator.cpp -o allocator
   ./allocator

   ```

   Author

Developed by Palakdeep
