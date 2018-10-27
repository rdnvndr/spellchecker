#include <QCoreApplication>

#include <spellchecker/spellchecker.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QString affPath("/usr/share/hunspell/en_ru.aff");
    QString dicPath("/usr/share/hunspell/en_ru.dic");
    QString word("worker");
    QString stem;

    SpellChecker *spellChecker = new SpellChecker(dicPath, affPath);
    if (spellChecker->spell(word, &stem))
        qDebug() << "Stem: " + stem;
    foreach (const QString &suggest, spellChecker->stem(word)) {
        qDebug() << suggest;
    }
    delete spellChecker;
}
