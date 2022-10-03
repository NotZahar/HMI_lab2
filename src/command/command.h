#ifndef COMMAND_H
#define COMMAND_H

#include <QString>
#include <QDir>
#include <QFile>
#include <QFileInfoList>

#include <map>
#include <vector>
#include <utility>

#include "../lab2.h"

using fileFormat = lab2::FileInfo::fileFormat;
using ErrorInfo = lab2::ErrorInfo;

class Command {
public:
    Command() = delete;
    explicit Command(const std::string& path);

    std::map<const std::string, fileFormat> scd();
    void gtd(const std::string& path);
    void rename(const std::vector<std::pair<const std::string, const std::string>>& renameList);

    std::string getCurrentDirPath();

private:
    QDir currentDir;
};

#endif // COMMAND_H
