#include "command.h"

Command::Command(const std::string& path) : currentDir(QString::fromStdString(path)) {
    currentDir.makeAbsolute();
}

std::map<const std::string, fileFormat> Command::scd() {
    std::map<const std::string, fileFormat> dirContent;
    currentDir.setFilter(QDir::AllEntries | QDir::Hidden);

    QFileInfoList fileInfoList = currentDir.entryInfoList();
    for (const auto& fileInfo : fileInfoList) {
        dirContent.insert({fileInfo.fileName().toStdString(), (fileInfo.isFile() ? fileFormat::file : fileFormat::folder) });
    }

    return dirContent;
}

void Command::gtd(const std::string& path) {
    QString currentDirPathCandidate = currentDir.absolutePath() + "/" + QString::fromStdString(path);
    if (!QFileInfo(currentDirPathCandidate).isDir()) throw std::string(ErrorInfo::errorMessages.at(ErrorInfo::error::wrongPath));
    currentDir.setPath(currentDirPathCandidate);
    currentDir.makeAbsolute();
}

void Command::rename(const std::vector<std::pair<const std::string, const std::string>>& renameList) {
    for (const auto& renamePair: renameList) {
        QString oldFilePath = currentDir.absolutePath() + "/" + QString::fromStdString(renamePair.first);
        QString newFilePath = currentDir.absolutePath() + "/" + QString::fromStdString(renamePair.second);

        if (QFileInfo(oldFilePath).isDir()) throw std::string(ErrorInfo::errorMessages.at(ErrorInfo::error::fileDoesntExist));
        if (QFileInfo(newFilePath).isDir()) throw std::string(ErrorInfo::errorMessages.at(ErrorInfo::error::renameIsImpossible));

        if (!QFile(oldFilePath).exists()) throw std::string(ErrorInfo::errorMessages.at(ErrorInfo::error::fileDoesntExist));
        if (QFile(newFilePath).exists()) throw std::string(ErrorInfo::errorMessages.at(ErrorInfo::error::fileAlreadyExists));

        QFile::rename(oldFilePath, newFilePath);
    }
}

std::string Command::getCurrentDirPath() {
    return currentDir.absolutePath().toStdString();
}
