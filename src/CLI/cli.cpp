#include "cli.h"

void CLI::start() {
    const std::regex regex_scd("^scd$");
    const std::regex regex_gtd("^gtd \"[a-zA-Zа-яА-Я0-9 ()\\,\\.~\\_\\-\\+@№\\#%\\^\\:\\/\\\\*\?]+\"$");
    const std::regex regex_rename("[a-z]+\\.txt");

    std::string commandCandidate;
    std::getline(std::cin, commandCandidate);

    while (true) {
        std::cout << ">> " << std::flush;
        std::getline(std::cin, commandCandidate);

        if (std::regex_match(commandCandidate, regex_scd)) {
            std::cout << "scd";
        } else if (std::regex_match(commandCandidate, regex_gtd)) {
            std::cout << "gtd";
        } else if (std::regex_match(commandCandidate, regex_rename)) {
            std::cout << "rename";
        } else {
            std::cout << "ОШИБКА!!";
        }

        std::cout << std::endl << std::flush;
    }
}
