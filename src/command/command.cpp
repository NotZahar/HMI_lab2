#include "command.h"

Command::Command(QString path) : currentDir(path) {
    currentDir.makeAbsolute();
}

std::map<const QString, fileFormat> Command::scd() {
    std::map<const QString, fileFormat> dirContent;
    currentDir.setFilter(QDir::AllEntries | QDir::Hidden);

    QFileInfoList fileInfoList = currentDir.entryInfoList();
    for (const auto& fileInfo : fileInfoList) {
        dirContent.insert({fileInfo.fileName(), (fileInfo.isFile() ? fileFormat::file : fileFormat::folder) });
    }

    return dirContent;
}

void Command::gtd(const QString& path) {
    if (!QDir(path).exists()) throw QString(ErrorInfo::errorMessages.at(error::wrongPath));
    currentDir.setPath(path);
    currentDir.makeAbsolute();
}

void Command::rename(const std::vector<std::pair<const QString, const QString>>& renameList) {
    for (const auto& renamePair: renameList) {
        QString oldFilePath = currentDir.absolutePath() + "/" + renamePair.first;
        QString newFilePath = currentDir.absolutePath() + "/" + renamePair.second;

        if (!QFile(oldFilePath).exists()) throw QString(ErrorInfo::errorMessages.at(error::fileDoesntExist));
        if (QFile(newFilePath).exists()) throw QString(ErrorInfo::errorMessages.at(error::fileAlreadyExists));

        QFile::rename(oldFilePath, newFilePath);
    }
}
