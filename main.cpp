#include <iostream>
#include <string>
#include "TodoList.h"
using namespace std;

int main() {
    TodoList todo;
    string filename = "data/tasks.txt";

    todo.loadFromFile(filename);

    int choice;
    while (true) {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add task\n";
        cout << "2. Remove task\n";
        cout << "3. Mark task completed\n";
        cout << "4. Show tasks\n";
        cout << "5. Save and exit\n";
        cout << "Choose an option: ";

        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name;
            cout << "Enter task name: ";
            getline(cin, name);
            todo.addTask(name);

        } else if (choice == 2) {
            int index;
            cout << "Enter task number to remove: ";
            cin >> index;
            todo.removeTask(index);

        } else if (choice == 3) {
            int index;
            cout << "Enter task number to mark completed: ";
            cin >> index;
            todo.markTaskCompleted(index);

        } else if (choice == 4) {
            todo.showTasks();

        } else if (choice == 5) {
            todo.saveToFile(filename);
            cout << "Goodbye!\n";
            break;

        } else {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}
