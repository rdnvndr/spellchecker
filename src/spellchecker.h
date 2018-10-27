#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include "spellcheckerglobal.h"

#include <QtCore/QString>
#include <QtCore/QTextCodec>

class Hunspell;

//! Класс для проверки орфографии на основе Hunspell
class SPELLCHECKERLIB SpellChecker
{
public:
    //! Информация по проверке
    enum SpellInfo {
        CompoundWord  = 0x1, //! Сложное слово
        ForbiddenWord = 0x2  //! Запрещённое слово
    };

    //! Конструктор класса
    explicit SpellChecker(QString dicPath, QString affPath);

    //! Деструктор класса
    virtual ~SpellChecker();


    //! Проверяет на наличие ошибок
    bool spell(const QString &word, SpellInfo *info  = nullptr,
               QString *stem = nullptr);

    //! Проверяет на наличие ошибок
    bool spell(const QString &word, QString *stem = nullptr);

    //! Возвращает список слов без ошибок
    QStringList suggest(const QString &word);

    //! Получает корни слова
    QStringList stem(const QString &word);


    //! Добавляет слово в загруженный словарь
    int addWord(const QString &word);

    //! Удаляет слово из загруженного словаря
    int removeWord(const QString &word);

    //! Добавляет словоформу
    int addWordAffix(const QString &word, const QString &example);

private:
    Hunspell *m_hunspell; //! Объект Hunspell

    QString m_encoding;   //! Кодировка словаря
    QTextCodec *m_codec;  //! Конвертер кодировки словаря из/в Unicode

};

#endif // SPELLCHECKER_H
