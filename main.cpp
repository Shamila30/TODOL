#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TodoList {
public:
    void addTask(const string& task) {
        tasks.push_back(task);
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
            return;
        }

        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }

    void deleteTask(size_t index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid index." << endl;
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
    }

private:
    vector<string> tasks;
};

int main() {
    TodoList todoList;
    int choice = 0;

    while (true) {
        cout << "\nTodo List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore newline character left in the input buffer

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter task description: ";
                getline(cin, task);
                todoList.addTask(task);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                size_t index;
                cout << "Enter task index to delete: ";
                cin >> index;
                todoList.deleteTask(index);
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "invalid input. Try Again." <<endl;
        }

    }
    return 0;



}
