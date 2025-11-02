#include <bits/stdc++.h>
using namespace std;

struct Task
{
  int id;
  int burst;
  int priority;
};

//  Utility functions
void printTask(const Task &t)
{
  cout << "Task " << t.id << " | Burst: " << t.burst
       << " | Priority: " << t.priority << endl;
}

//  FCFS Scheduling
void fcfs(vector<Task> tasks)
{
  cout << "\n  FCFS Scheduling --->\n";
  int n = tasks.size();
  vector<int> waiting(n), turnaround(n);

  waiting[0] = 0;
  turnaround[0] = tasks[0].burst;

  for (int i = 1; i < n; i++)
  {
    waiting[i] = waiting[i - 1] + tasks[i - 1].burst;
    turnaround[i] = waiting[i] + tasks[i].burst;
  }

  double avgWait = accumulate(waiting.begin(), waiting.end(), 0.0) / n;
  double avgTurn = accumulate(turnaround.begin(), turnaround.end(), 0.0) / n;

  for (int i = 0; i < n; i++)
    cout << "Executing Task " << tasks[i].id << " | Burst: " << tasks[i].burst
         << endl;

  cout << "Average Waiting Time: " << avgWait << endl;
  cout << "Average Turnaround Time: " << avgTurn << endl;
}

//  Priority Scheduling
void priorityScheduling(vector<Task> tasks)
{
  cout << "\n  Priority Scheduling --->\n";
  sort(tasks.begin(), tasks.end(), [](Task a, Task b)
       {
    if (a.priority == b.priority)
      return a.id < b.id;
    return a.priority < b.priority; });

  int n = tasks.size();
  vector<int> waiting(n), turnaround(n);

  waiting[0] = 0;
  turnaround[0] = tasks[0].burst;

  for (int i = 1; i < n; i++)
  {
    waiting[i] = waiting[i - 1] + tasks[i - 1].burst;
    turnaround[i] = waiting[i] + tasks[i].burst;
  }

  for (auto &t : tasks)
    printTask(t);

  double avgWait = accumulate(waiting.begin(), waiting.end(), 0.0) / n;
  double avgTurn = accumulate(turnaround.begin(), turnaround.end(), 0.0) / n;

  cout << "Average Waiting Time: " << avgWait << endl;
  cout << "Average Turnaround Time: " << avgTurn << endl;
}

//  Round Robin Scheduling
void roundRobin(vector<Task> tasks, int quantum)
{
  cout << "\n  Round Robin Scheduling --->\n";

  queue<Task> q;
  for (auto &t : tasks)
    q.push(t);

  int time = 0;
  map<int, int> turnaround;
  map<int, int> waiting;
  map<int, int> remaining;

  for (auto &t : tasks)
    remaining[t.id] = t.burst;

  while (!q.empty())
  {
    Task t = q.front();
    q.pop();

    if (remaining[t.id] > quantum)
    {
      time += quantum;
      remaining[t.id] -= quantum;
      q.push(t);
    }
    else
    {
      time += remaining[t.id];
      remaining[t.id] = 0;
      turnaround[t.id] = time;
    }
  }

  double totalWait = 0, totalTurn = 0;
  for (auto &t : tasks)
  {
    waiting[t.id] = turnaround[t.id] - t.burst;
    totalWait += waiting[t.id];
    totalTurn += turnaround[t.id];
    cout << "Completed Task " << t.id << " | Turnaround: " << turnaround[t.id]
         << " | Waiting: " << waiting[t.id] << endl;
  }

  cout << "Average Waiting Time: " << totalWait / tasks.size() << endl;
  cout << "Average Turnaround Time: " << totalTurn / tasks.size() << endl;
}

// ---------- Main ----------
int main()
{
  int n;
  cout << "Enter number of tasks: ";
  cin >> n;

  vector<Task> tasks(n);
  for (int i = 0; i < n; i++)
  {
    cout << "Enter details for Task " << i + 1 << " (Burst Time, Priority): ";
    tasks[i].id = i + 1;
    cin >> tasks[i].burst >> tasks[i].priority;
  }

  int quantum;
  cout << "Enter time quantum for Round Robin: ";
  cin >> quantum;

  fcfs(tasks);
  priorityScheduling(tasks);
  roundRobin(tasks, quantum);

  return 0;
}
