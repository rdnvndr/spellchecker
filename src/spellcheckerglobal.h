#include <QtCore/QtGlobal>

#if defined(SPELLCHECKER_LIBRARY)
#  define SPELLCHECKERLIB Q_DECL_EXPORT
#else
#  define SPELLCHECKERLIB Q_DECL_IMPORT
#endif
