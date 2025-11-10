#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include <iostream>
#include "../src/Todo.hpp"

TEST_CASE("TodoList can add tasks") {
    TodoList list;
    list.add("Buy milk");

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    list.all();
    std::cout.rdbuf(oldCout);

    std::string output = buffer.str();
    REQUIRE(output.find("Buy milk") != std::string::npos);
}

TEST_CASE("TodoList can complete tasks") {
    TodoList list;
    list.add("Buy eggs");
    list.complete("Buy eggs");

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    list.complete();
    std::cout.rdbuf(oldCout);

    std::string output = buffer.str();
    REQUIRE(output.find("Buy eggs") != std::string::npos);
}

TEST_CASE("TodoList can show incomplete tasks") {
    TodoList list;
    list.add("Prepare lesson");
    list.add("Buy bread");
    list.complete("Buy bread");

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    list.incomplete();
    std::cout.rdbuf(oldCout);

    std::string output = buffer.str();
    REQUIRE(output.find("Prepare lesson") != std::string::npos);
    REQUIRE(output.find("Buy bread") == std::string::npos);
}

TEST_CASE("TodoList can clear all tasks") {
    TodoList list;
    list.add("Task 1");
    list.add("Task 2");

    list.clear();

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    list.all();
    std::cout.rdbuf(oldCout);

    std::string output = buffer.str();
    REQUIRE(output.find("No tasks") != std::string::npos);
}