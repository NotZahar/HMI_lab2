#ifndef CLI_H
#define CLI_H

#include <iostream>
#include <regex>

#include "../lab2.h"
#include "../command/command.h"

class CLI
{
public:
    CLI(const std::string& path);

    void start();

private:
    void doScd();
    void doGtd(const std::string& commandCandidate);
    void doRename(std::string& commandCandidate);

private:
    Command command;
};

#endif // CLI_H
