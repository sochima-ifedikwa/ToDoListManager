#ifndef TASK_H
#define TASK_H

#include <string>
using std::string;

class Task {
private:
    string name;
    bool completed;

public:
    Task(const string& taskName);
    
    void markComplete();
    string getName() const;
    bool isCompleted() const;

    string serialize() const;
    static Task deserialize(const string& line);
};

#endif
