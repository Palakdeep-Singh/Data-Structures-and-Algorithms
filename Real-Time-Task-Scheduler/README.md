# ⚙️ Task Scheduler (C++)

A simulation of **CPU Scheduling Algorithms** implemented in **C++**, designed to demonstrate how an operating system schedules processes efficiently using different strategies.

---

## 🚀 Overview
This project implements and compares multiple **task scheduling algorithms** such as **FCFS**, **Priority Scheduling**, and **Round Robin**.  
It calculates performance metrics like **Average Waiting Time** and **Average Turnaround Time** to analyze algorithm efficiency.

---

## 🧩 Features
- Implements key CPU scheduling techniques:
  - 🟢 **First Come First Serve (FCFS)**
  - 🟡 **Priority Scheduling**
  - 🔵 **Round Robin Scheduling**
- Uses **queues**, **priority queues**, and **OOP concepts**.
- Calculates:
  - Average Waiting Time  
  - Average Turnaround Time
- Displays clear task execution order and statistics.
- Well-documented and modular C++ design.

---

## 🧮 Example Output

```
  FCFS Scheduling -->
  Executing Task 1 | Burst: 5
  Executing Task 2 | Burst: 3
  Executing Task 3 | Burst: 8
  Executing Task 4 | Burst: 6
  
  Average Waiting Time: 5.75
  Average Turnaround Time: 11.25
  
  Priority Scheduling -->
  Executing Task 2 | Burst: 3 | Priority: 1
  Executing Task 1 | Burst: 5 | Priority: 2
  Executing Task 4 | Burst: 6 | Priority: 2
  Executing Task 3 | Burst: 8 | Priority: 3
  
  Average Waiting Time: 4.75
  Average Turnaround Time: 10.25
  
  Round Robin Scheduling -->
  Completed Task 2 | Turnaround: 5
  Completed Task 1 | Turnaround: 14
  Completed Task 4 | Turnaround: 17
  Completed Task 3 | Turnaround: 20
  
  Average Waiting Time: 8.5
  Average Turnaround Time: 14

  ```
---------------------------------------------

### **Compile & Run**
```
```bash
g++ task_scheduler.cpp -o scheduler
./scheduler
```


