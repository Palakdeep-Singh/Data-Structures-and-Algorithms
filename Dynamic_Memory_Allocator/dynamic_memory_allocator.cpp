#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Structure to represent a memory block
struct Block {
    int start;  // Start address
    int size;   // Block size
    bool free;  // Free or allocated
};

class MemoryAllocator {
private:
    vector<Block> memory;
    int totalMemory;

public:
    // Constructor
    MemoryAllocator(int size) {
        if (size <= 0) {
            cout << "Error: Memory size must be positive!" << endl;
            exit(0);
        }
        totalMemory = size;
        memory.push_back({0, size, true});
    }

    // Allocate memory using First Fit strategy
    void allocate(int size) {
        if (size <= 0) {
            cout << "Error: Invalid allocation size!" << endl;
            return;
        }

        for (size_t i = 0; i < memory.size(); i++) {
            Block &block = memory[i];
            if (block.free && block.size >= size) {
                int remaining = block.size - size;
                block.free = false;
                block.size = size;

                // Create new free block if space remains
                if (remaining > 0) {
                    memory.insert(memory.begin() + i + 1, {block.start + size, remaining, true});
                }

                cout << "Allocated " << size << " units at address " << block.start << endl;
                return;
            }
        }

        cout << "Allocation failed: Not enough memory." << endl;
    }

    // Deallocate a block
    void deallocate(int startAddress) {
        for (auto &block : memory) {
            if (block.start == startAddress) {
                if (block.free) {
                    cout << "Block at address " << startAddress << " is already free!" << endl;
                    return;
                }
                block.free = true;
                cout << "Freed block starting at address " << startAddress << endl;
                mergeFreeBlocks();
                return;
            }
        }
        cout << "Invalid address! No allocated block found at " << startAddress << "." << endl;
    }

    // Merge consecutive free blocks
    void mergeFreeBlocks() {
        for (size_t i = 0; i < memory.size() - 1; i++) {
            if (memory[i].free && memory[i + 1].free) {
                memory[i].size += memory[i + 1].size;
                memory.erase(memory.begin() + i + 1);
                i--;
            }
        }
    }

    // Display the current memory layout
    void display() {
        cout << "\nCurrent Memory Layout:" << endl;
        cout << left << setw(12) << "Start" << setw(12) << "Size" << setw(10) << "Status" << endl;
        cout << "----------------------------------" << endl;
        for (auto &block : memory) {
            cout << left << setw(12) << block.start
                 << setw(12) << block.size
                 << (block.free ? "Free" : "Allocated") << endl;
        }
        cout << "----------------------------------" << endl;
    }

    // Get total free memory
    int getFreeMemory() const {
        int freeSpace = 0;
        for (const auto &block : memory) {
            if (block.free)
                freeSpace += block.size;
        }
        return freeSpace;
    }
};

int main() {
    cout << "=== Dynamic Memory Allocator Simulation ===" << endl;

    int total;
    cout << "Enter total memory size: ";
    cin >> total;

    MemoryAllocator allocator(total);
    allocator.display();

    while (true) {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Allocate Memory" << endl;
        cout << "2. Deallocate Memory" << endl;
        cout << "3. Display Memory" << endl;
        cout << "4. Show Free Space" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            int size;
            cout << "Enter size to allocate: ";
            cin >> size;
            allocator.allocate(size);
        } 
        else if (choice == 2) {
            int start;
            cout << "Enter start address to deallocate: ";
            cin >> start;
            allocator.deallocate(start);
        } 
        else if (choice == 3) {
            allocator.display();
        } 
        else if (choice == 4) {
            cout << "Total Free Memory: " << allocator.getFreeMemory() << " units" << endl;
        } 
        else if (choice == 5) {
            cout << "Exiting program." << endl;
            break;
        } 
        else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
