#ifndef LAB2_H
#define LAB2_H

#include <string>
#include <map>

namespace lab2 {

    struct FileInfo {
        FileInfo() = delete;

        enum class fileFormat : int {
            file,
            folder
        };

        static inline const std::map<fileFormat, const std::string> fileType {
            {fileFormat::file, "f"},
            {fileFormat::folder, "d"}
        };
    };

    struct ErrorInfo {
       ErrorInfo() = delete;

       enum class error : int {
           wrongPath,
           fileDoesntExist,
           fileAlreadyExists,
           renameIsImpossible,
           incorrectEntryInput,
           invalidCommand
       };

       static inline const std::map<error, const std::string> errorMessages {
           {error::wrongPath, "Неверный путь"},
           {error::fileDoesntExist, "Файл с таким именем не существует"},
           {error::fileAlreadyExists, "Файл с таким именем уже существует"},
           {error::renameIsImpossible, "Невозможно переименовать"},
           {error::incorrectEntryInput, "Некорректный ввод, перезапустите программу"},
           {error::invalidCommand, "Команды не существует"}
       };
    };

}

#endif // LAB2_H
