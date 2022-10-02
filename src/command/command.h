#ifndef COMMAND_H
#define COMMAND_H

#include <QString>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QFileInfoList>

#include <map>
#include <vector>
#include <utility>

#include "../lab2.h"

using fileFormat = lab2::fileFormat;
using ErrorInfo = lab2::ErrorInfo;
using error = ErrorInfo::error;

class Command {
public:
    Command() = delete;
    explicit Command(QString path);

    std::map<const QString, fileFormat> scd();
    void gtd(const QString& path);
    void rename(const std::vector<std::pair<const QString, const QString>>& renameList);

public:
    QDir currentDir;
};

#endif // COMMAND_H
