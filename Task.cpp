#include "Task.h"
#include <sstream>
using namespace std;

Task::Task(const string& taskName)
    : name(taskName), completed(false) {}

void Task::markComplete() {
    completed = true;
}

string Task::getName() const {
    return name;
}

bool Task::isCompleted() const {
    return completed;
}

string Task::serialize() const {
    return (completed ? "1|" : "0|") + name;
}

Task Task::deserialize(const string& line) {
    stringstream ss(line);
    string status;
    getline(ss, status, '|');

    string name;
    getline(ss, name);

    Task t(name);
    if (status == "1") t.markComplete();

    return t;
}
