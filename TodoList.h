#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include <string>
#include "Task.h"

using std::string;
using std::vector;

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& name);
    void removeTask(int index);
    void markTaskCompleted(int index);
    void showTasks() const;

    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif
