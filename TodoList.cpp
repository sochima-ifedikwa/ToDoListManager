#include "TodoList.h"
#include <iostream>
#include <fstream>
using namespace std;

void TodoList::addTask(const string& name) {
    tasks.emplace_back(name);
}

void TodoList::removeTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Task removed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void TodoList::markTaskCompleted(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].markComplete();
        cout << "Task completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void TodoList::showTasks() const {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\n--- To-Do List ---\n";
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i << ". "
             << (tasks[i].isCompleted() ? "[✔] " : "[ ] ")
             << tasks[i].getName() << "\n";
    }
    cout << "-------------------\n";
}

void TodoList::saveToFile(const string& filename) const {
    ofstream out(filename);

    for (const auto& t : tasks) {
        out << t.serialize() << "\n";
    }

    cout << "Tasks saved to file.\n";
}

void TodoList::loadFromFile(const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) return;

    string line;
    while (getline(in, line)) {
        tasks.push_back(Task::deserialize(line));
    }

    cout << "Tasks loaded from file.\n";
}
