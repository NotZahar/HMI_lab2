#ifndef LAB2_H
#define LAB2_H

#include <QString>

#include <map>

namespace lab2 {

    enum class fileFormat : int {
        file,
        folder
    };

    struct ErrorInfo {
       ErrorInfo() = delete;

       enum class error : int {
           wrongPath,
           fileDoesntExist,
           fileAlreadyExists,
           renameIsImpossible,
           incorrectEntryInput
       };

       static inline const std::map<error, const QString> errorMessages{
           {error::wrongPath, "Неверный путь"},
           {error::fileDoesntExist, "Файл с таким именем не существует"},
           {error::fileAlreadyExists, "Файл с таким именем уже существует"},
           {error::renameIsImpossible, "Невозможно переименовать"},
           {error::incorrectEntryInput, "Некорректный ввод, перезапустите программу"}
       };
    };

}

#endif // LAB2_H
