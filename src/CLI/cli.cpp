#include "cli.h"

CLI::CLI(const std::string& path) : command(path) {

}

void CLI::start() {
    const std::regex regex_scd("^scd$");
    const std::regex regex_gtd("^gtd \\/[^\\/]+\\/$");
    const std::regex regex_rename("^rename( \\/[^\\/]+\\/->\\/[^\\/]+\\/){1,}$");
    const std::regex regex_exit("^q$");

    std::string commandCandidate;
    std::getline(std::cin, commandCandidate);

    while (true) {
        std::cout << command.getCurrentDirPath() << " > " << std::flush;
        std::getline(std::cin, commandCandidate);

        if (std::regex_match(commandCandidate, regex_scd)) {
            doScd();
        } else if (std::regex_match(commandCandidate, regex_gtd)) {
            doGtd(commandCandidate);
        } else if (std::regex_match(commandCandidate, regex_rename)) {
            doRename(commandCandidate);
        } else if (std::regex_match(commandCandidate, regex_exit)) {
            std::cout << "Bye!" << std::endl << std::flush;
            break;
        } else {
            std::cout << lab2::ErrorInfo::errorMessages.at(lab2::ErrorInfo::error::invalidCommand);
        }

        std::cout << std::endl << std::flush;
    }
}

void CLI::doScd() {
    for (const auto& fileInfo : command.scd()) std::cout << lab2::FileInfo::fileType.at(fileInfo.second) << "  " << fileInfo.first << std::endl << std::flush;
}

void CLI::doGtd(std::string& commandCandidate)
{
    std::regex regex_path("\\/[^\\/]+\\/");
    std::smatch match;

    if (std::regex_search(commandCandidate, match, regex_path)) {
        std::string raw_path = match[0].str();
        try {
            command.gtd(raw_path.substr(1, raw_path.size() - 2));
        }  catch (std::string& msg) {
            std::cout << msg;
        }
    }
}

void CLI::doRename(std::string& commandCandidate) {
    std::vector<std::pair<const std::string, const std::string>> renameList;
    std::regex regex_pair("\\/[^\\/]+\\/->\\/[^\\/]+\\/");
    std::regex regex_first("\\/[^\\/]+\\/->");
    std::regex regex_second("->\\/[^\\/]+\\/");
    std::smatch matchPair;
    std::smatch matchFirst;
    std::smatch matchSecond;

    commandCandidate = commandCandidate.substr(7); // "rename "

    while (true) {
        if (std::regex_search(commandCandidate, matchPair, regex_pair)) {

            std::string pair = matchPair.str();
            std::regex_search(pair, matchFirst, regex_first);
            std::regex_search(pair, matchSecond, regex_second);

            std::string raw_path_first = matchFirst[0].str();
            std::string raw_path_second = matchSecond[0].str();

            renameList.push_back({raw_path_first.substr(1, raw_path_first.size() - 4),
                                 raw_path_second.substr(3, raw_path_second.size() - 4)});

            commandCandidate = commandCandidate.substr(pair.size());
        } else {
            break;
        }
   }

    try {
        command.rename(renameList);
    }  catch (std::string& msg) {
        std::cout << msg;
    }
}
