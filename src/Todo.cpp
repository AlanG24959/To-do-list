#include "Todo.hpp"
#include <iostream>
#include <algorithm>

TodoList::Task::Task(std::string n) : name(std::move(n)), done(false) {}

void TodoList::add(const std::string& taskName) {
    if (taskName.empty()) {
        std::cout << "Task name cannot be empty.\n";
        return;
    }
    tasks.emplace_back(taskName);
    std::cout << "Added: \"" << taskName << "\"\n";
}

void TodoList::complete(const std::string& taskName) {
    auto it = std::find_if(tasks.begin(), tasks.end(),
                           [&](const Task& t) { return t.name == taskName; });
    if (it != tasks.end()) {
        if (it->done)
            std::cout << "Task \"" << taskName << "\" is already completed.\n";
        else {
            it->done = true;
            std::cout << "Completed: \"" << taskName << "\"\n";
        }
    } else {
        std::cout << "Task \"" << taskName << "\" not found.\n";
    }
}

void TodoList::all() const {
    if (tasks.empty()) {
        std::cout << "No tasks in the list.\n";
        return;
    }

    std::cout << "\nAll Tasks:\n";
    for (const auto& t : tasks)
        std::cout << " - " << t.name << (t.done ? " [Done]" : " [Not Done]") << "\n";
}

void TodoList::complete() const {
    bool found = false;
    std::cout << "\nCompleted Tasks:\n";
    for (const auto& t : tasks) {
        if (t.done) {
            std::cout << " - " << t.name << "\n";
            found = true;
        }
    }
    if (!found) std::cout << " (none)\n";
}

void TodoList::incomplete() const {
    bool found = false;
    std::cout << "\nIncomplete Tasks:\n";
    for (const auto& t : tasks) {
        if (!t.done) {
            std::cout << " - " << t.name << "\n";
            found = true;
        }
    }
    if (!found) std::cout << " (none)\n";
}

void TodoList::clear() {
    tasks.clear();
    std::cout << "Cleared all tasks.\n";
}
