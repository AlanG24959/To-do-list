#pragma once
#include <string>
#include <vector>

class TodoList {
private:
    struct Task {
        std::string name;
        bool done;
        Task(std::string n);
    };

    std::vector<Task> tasks;

public:
    void add(const std::string& taskName);
    void complete(const std::string& taskName);
    void all() const;
    void complete() const;
    void incomplete() const;
    void clear();
};
