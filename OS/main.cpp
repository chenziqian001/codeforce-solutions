#include<bits/stdc++.h>
using namespace std;

struct Process {
    int pid, arrival_time, burst_time;
    int remaining_time, start_time = -1, finish_time = -1;
    int wait_time = 0, turnaround_time = 0;

    Process(int id, int at, int bt)
        : pid(id), arrival_time(at), burst_time(bt), remaining_time(bt) {}
}; //定义进进程结构体


void print_result(const string& algo_name, vector<Process> processes) {
    cout << "\n=== algo_name: " << algo_name << " ===\n";
    int total_wait = 0, total_turnaround = 0;

    cout << "PID\tArrival\tBurst\tStart\tFinish\tWait\tTurnaround\n";
    for (auto& p : processes) {
        cout << p.pid << "\t" << p.arrival_time << "\t" << p.burst_time << "\t"
             << p.start_time << "\t" << p.finish_time << "\t"
             << p.wait_time << "\t" << p.turnaround_time << "\n";
        total_wait += p.wait_time;
        total_turnaround += p.turnaround_time;
    }

    int n = processes.size();
    cout << "Average Waiting Time: " << (double)total_wait / n << endl;
    cout << "Average Turnaround Time: " << (double)total_turnaround / n << endl;
} //只是个打印结果的函数


void run_fcfs(vector<Process> processes) {
    sort(processes.begin(), processes.end(), [](Process& a, Process& b) {
        return a.arrival_time < b.arrival_time;
    });

    int time = 0;
    for (auto& p : processes) {
        if (time < p.arrival_time) time = p.arrival_time;
        p.start_time = time;
        p.finish_time = time + p.burst_time;
        p.wait_time = p.start_time - p.arrival_time;
        p.turnaround_time = p.finish_time - p.arrival_time;
        time = p.finish_time;
    }

    print_result("FCFS", processes);
}
void run_sjf(vector<Process> processes) {
    int time = 0, completed = 0;
    int n = processes.size();
    vector<bool> done(n, false);

    while (completed < n) {
        int idx = -1;
        int min_burst = 1e9;
        for (int i = 0; i < n; ++i) {
            if (!done[i] && processes[i].arrival_time <= time && processes[i].burst_time < min_burst) {
                min_burst = processes[i].burst_time;
                idx = i;
            }
        }

        if (idx == -1) {
            ++time;
            continue;
        }

        auto& p = processes[idx];
        p.start_time = time;
        p.finish_time = time + p.burst_time;
        p.wait_time = p.start_time - p.arrival_time;
        p.turnaround_time = p.finish_time - p.arrival_time;
        time = p.finish_time;
        done[idx] = true;
        ++completed;
    }

    print_result("SJF", processes);
}

void run_rr(vector<Process> processes, int time_quantum = 2) {
    queue<int> q;
    int time = 0;
    int n = processes.size();
    vector<bool> in_queue(n, false);
    int completed = 0;
    sort(processes.begin(), processes.end(), [](Process& a, Process& b) {
        return a.arrival_time < b.arrival_time;
    });

    q.push(0);
    in_queue[0] = true;

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        auto& p = processes[idx];
        if (p.start_time == -1)
            p.start_time = max(time, p.arrival_time);

        time = max(time, p.arrival_time);

        int run_time = min(time_quantum, p.remaining_time);
        p.remaining_time -= run_time;
        time += run_time;

        // 添加新到达进程
        for (int i = 0; i < n; ++i) {
            if (!in_queue[i] && processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                q.push(i);
                in_queue[i] = true;
            }
        }

        // 自己还有没跑完就继续排队
        if (p.remaining_time > 0) {
            q.push(idx);
        } else {
            p.finish_time = time;
            p.turnaround_time = p.finish_time - p.arrival_time;
            p.wait_time = p.turnaround_time - p.burst_time;
            ++completed;
        }

        if (completed == n) break;
    }

    print_result("Round Robin (TQ=" + to_string(time_quantum) + ")", processes);
}

int main() {
    // 你可以在这里修改进程信息
    vector<Process> processes = {
        {1, 0, 5},
        {2, 2, 3},
        {3, 4, 1},
        {4, 6, 7},
        {5, 7, 4},
    };

    run_fcfs(processes);
    run_sjf(processes);
    run_rr(processes, 2);
    system("pause");
    return 0;

}
