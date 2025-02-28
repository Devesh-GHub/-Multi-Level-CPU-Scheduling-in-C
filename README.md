# 🚀 Multi-Level CPU Scheduling in C  

A powerful **CPU Scheduling** simulator written in **C**, implementing **three key scheduling algorithms**:  

✅ **First-Come, First-Serve (FCFS)**  
✅ **Round Robin Scheduling** (with user-defined time quantum)  
✅ **Priority Scheduling**  

📌 **Ideal for understanding OS process scheduling & improving system performance analysis!**  

---

## 📜 Features  
🔹 Implements **three major scheduling algorithms** for CPU process management.  
🔹 **User-friendly input prompts** to enter process details (arrival time, burst time, priority).  
🔹 **Formatted tabular output** displaying waiting and turnaround times.  
🔹 **Customizable time quantum** for Round Robin scheduling.  

---

## 🖥️ How It Works  
1️⃣ The program prompts the user to enter **process details**.  
2️⃣ The user selects one of the three scheduling algorithms.  
3️⃣ The program computes & displays **waiting time and turnaround time** in a neat table.  

```bash
Enter number of processes: 3
Enter arrival time, burst time, and priority for Process 1: 0 5 2
Enter arrival time, burst time, and priority for Process 2: 1 3 1
Enter arrival time, burst time, and priority for Process 3: 2 8 3

Choose Scheduling Algorithm:
1. First-Come, First-Serve (FCFS)
2. Round Robin
3. Priority Scheduling
Enter choice: 1

Scheduling using FCFS...
------------------------------------------------------------
 ID   Arrival   Burst   Priority   Waiting   Turnaround
------------------------------------------------------------
  1       0       5        2         0         5
  2       1       3        1         4         7
  3       2       8        3         6        14
------------------------------------------------------------
