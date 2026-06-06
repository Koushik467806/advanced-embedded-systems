**FCFS (First-Come, First-Serve)**

1. Process is executed if it comes first
2. Does not check priority or burst time
3. Simple and easy to implement
4. If a process has a very high burst time and is coming first, then it will be executed first even if another process with a lesser time is present in the ready state. (disadvantage)



**SJN (Shortest Job Next)**

1. Process with minimum burst time is executed first
2. Very efficient in minimising the waiting time 
3. There is chance of starvation if short processes keep coming in the ready state (disadvantage)



**PS (Priority Scheduling)**

1. Each process is labeled with a priority and the task with highest priority is executed first
2. There is a chance of starvation if higher priority tasks keep coming up
3. If two tasks have same priority, this algorithm fails



**SRT (Shortest Remaining Time)**

1. Preemptive version of **SJN**
2. OS allocates processor to the task which is closest to completion



**RR (Round Robin)**

1. Each task is given some amount of time called **quantum**
2. After the quantum, task's progress is saved and processor moves on to next task
3. No scope of starvation
4. CPU is left idle due to lot of context switching (disadvantage)



**MLQ (Multiple Level Queues)**

1. All tasks with similar characteristics are formed into a group
2. Each group has its own **scheduling algorithm**



**MFQ (Multilevel Feedback Queue)**

1. Similar to **MLQ** but the processes can change their queue after a certain task is executed
2. Queues have priority and the one with the highest priority is executed first
3. There is a chance of starvation if higher priority queue keep coming in the ready state



**HRRN (Highest Response Ratio Next)**

1. Scheduling is based on **response ratio**
2. Process with highest response ratio will be executed first
3. $$Response\ Ratio = \frac{\text{Waiting Time} + \text{Burst Time}}{\text{Burst Time}}$$


