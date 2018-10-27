#include "spellchecker.h"

#include <QtCore/QDir>
#include <hunspell/hunspell.hxx>

SpellChecker::SpellChecker(QString dicPath, QString affPath)
{

#ifdef Q_OS_WIN
    // Обработка путей для Hunspell
    affPath = "\\\\?\\" + QDir::toNativeSeparators(affPath);
    dicPath = "\\\\?\\" + QDir::toNativeSeparators(dicPath);
#endif

    m_hunspell = new Hunspell(affPath.toUtf8().constData(),
                              dicPath.toUtf8().constData());

    m_encoding = QString::fromStdString(m_hunspell->get_dict_encoding());
    m_codec = QTextCodec::codecForName(m_encoding.toLatin1().constData());
}

SpellChecker::~SpellChecker()
{
    delete m_hunspell;
}

bool SpellChecker::spell(const QString &word, SpellInfo *info, QString *stem)
{
    std::string root;
    int spellInfo = 0;

    bool ret = m_hunspell->spell(m_codec->fromUnicode(word).toStdString(),
                                 (info == nullptr) ? nullptr : &spellInfo,
                                 (stem == nullptr) ? nullptr : &root);

    if (info != nullptr) {
        *info = static_cast<SpellInfo>((spellInfo & SPELL_COMPOUND)
                ? static_cast<int>(*info) | SpellChecker::CompoundWord
                : *info ^ SpellChecker::CompoundWord);
        *info = static_cast<SpellInfo>((spellInfo & SPELL_FORBIDDEN)
                ? *info | SpellChecker::ForbiddenWord
                : *info ^ SpellChecker::ForbiddenWord);
    }

    if (stem != nullptr) {
        *stem = m_codec->toUnicode(QByteArray::fromStdString(root));
        if (ret && stem->isEmpty())
            *stem = word;
    }

    return ret;
}

bool SpellChecker::spell(const QString &word, QString *stem)
{
    return this->spell(word, nullptr, stem);
}

QStringList SpellChecker::stem(const QString &word)
{
    QStringList stems;
    std::vector<std::string> stemWordList
            = m_hunspell->stem(m_codec->fromUnicode(word).toStdString());

    for (std::vector<std::string>::iterator it = stemWordList.begin();
         it != stemWordList.end(); ++it)
    {
        stems.append(m_codec->toUnicode(QByteArray::fromStdString(*it)));
    }

    return stems;
}

QStringList SpellChecker::suggest(const QString &word)
{
    QStringList suggestions;
    std::vector<std::string> suggestWordList
            = m_hunspell->suggest(m_codec->fromUnicode(word).toStdString());

    for (std::vector<std::string>::iterator it = suggestWordList.begin();
         it != suggestWordList.end(); ++it)
    {
        suggestions.append(m_codec->toUnicode(QByteArray::fromStdString(*it)));
    }

    return suggestions;
}

int SpellChecker::addWord(const QString &word)
{
    return m_hunspell->add(m_codec->fromUnicode(word).toStdString());
}

int SpellChecker::removeWord(const QString &word)
{
    return m_hunspell->remove(m_codec->fromUnicode(word).toStdString());
}

int SpellChecker::addWordAffix(const QString &word, const QString &example)
{
    return m_hunspell->add_with_affix(m_codec->fromUnicode(word).toStdString(),
                                      m_codec->fromUnicode(example).toStdString());
}
