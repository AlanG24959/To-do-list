#include <iostream>
#include <string>
#include "src/Todo.hpp"

void showLegend() {
    std::cout << "\n--- Todo List Commands ---\n";
    std::cout << "add      - Add a new task\n";
    std::cout << "complete - Mark a task as complete\n";
    std::cout << "all      - Show all tasks\n";
    std::cout << "done     - Show completed tasks\n";
    std::cout << "todo     - Show incomplete tasks\n";
    std::cout << "clear    - Clear all tasks\n";
    std::cout << "quit     - Exit the program\n";
    std::cout << "---------------------------\n";
}

int main() {
    TodoList todo;
    std::string command;

    showLegend();

    while (true) {
        std::cout << "\nEnter command: ";
        std::getline(std::cin, command);

        if (command == "quit" || command == "exit") {
            std::cout << "Exiting program.\n";
            break;
        }

        showLegend();

        if (command == "add") {
            std::string task;
            std::cout << "Enter task: ";
            std::getline(std::cin, task);
            todo.add(task);
        }
        else if (command == "complete") {
            std::string task;
            std::cout << "Enter task to complete: ";
            std::getline(std::cin, task);
            todo.complete(task);
        }
        else if (command == "all") {
            todo.all();
        }
        else if (command == "done") {
            todo.complete();
        }
        else if (command == "todo") {
            todo.incomplete();
        }
        else if (command == "clear") {
            todo.clear();
        }
        else {
            std::cout << "Unknown command. Try again.\n";
        }
    }

    return 0;
}
