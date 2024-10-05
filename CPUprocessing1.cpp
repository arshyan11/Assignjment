#include<iostream>
using namespace std;

class process {
public:
    int execution_time;
    int remaining_time;
    process* next;
    int process_id;

    process(int time, int id) {
        this->execution_time = time;
        this->remaining_time = time;
        this->next = nullptr;
        this->process_id = id;
    }
};

class schedular {
private:
    process* head;
    int time_cpu_per_process;

public:
    schedular(int tim) {
        this->head = nullptr;
        this->time_cpu_per_process = tim;
    }

    void addprocess(int id, int exe_time) {
        process* newnode = new process(exe_time, id);
        if (head == nullptr) {
            head = newnode;
            head->next = head;
            return;
        }
        process* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }

    void removeProcess(process* delprocess) {
        if (delprocess == head && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        process* temp = head;
        if (delprocess == head) {
            while (temp->next != head) {
                temp = temp->next;
            }
            process* newhead = head->next;
            temp->next = newhead;
            delete head;
            head = newhead;
            return;
        }

        while (temp->next != delprocess) {
            temp = temp->next;
        }
        temp->next = delprocess->next;
        delete delprocess;
    }

    void displayProcesses() {
        if (!head) {
            cout << "No processes remaining." << endl;
            return;
        }
        process* temp = head;
        do {
            cout << "Process ID: " << temp->process_id << ", Remaining Time: " << temp->remaining_time << endl;
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void runSchedular() {
        int cycle = 1;
        while (head != nullptr) {
            cout << "Cycle " << cycle << ":" << endl;
            process* current = head;
            process* cycleStart = head;

            do {
               
                if (current->remaining_time <= time_cpu_per_process) {
                    cout << "Process " << current->process_id << " completed!" << endl;
                    process* nextProcess = current->next;
                    removeProcess(current);
                    current = nextProcess;
                    if (!head) break;
                } 
                else {
                    if(cycle==1){//first cycle has same execution  value and remainig value 
                     
                    cout << "Process " << current->process_id << " now has " << current->remaining_time << " remaining time." << endl;
                    current = current->next;
                    }
                    else{
                           current->remaining_time -= time_cpu_per_process;
                    cout << "Process " << current->process_id << " now has " << current->remaining_time << " remaining time." << endl;
                    current = current->next;
                    }
                }
                
            } while (current != cycleStart && head);

            displayProcesses();
            cycle++;
        }
    }
};

int main() {
    schedular scheduler1(3);
    scheduler1.addprocess(1, 10);
    scheduler1.addprocess(2, 5);
    scheduler1.addprocess(3, 8);
    scheduler1.runSchedular();

    return 0;
}
