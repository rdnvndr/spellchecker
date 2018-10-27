import "./main.qbs" as LibProduct

LibProduct {
    name: "spellchecker"

    productname: "SpellChecker Library"
    version:     "1.0.0"
    description: "SpellChecker Library"
    company:     ""
    copyright:   ""

    cpp.defines: base.concat([
        "SPELLCHECKER_LIBRARY"
    ])
    cpp.dynamicLibraries: "hunspell"
    Depends { name: "Qt"; submodules: ["core"] }

    files: [
        "*.h",
        "*.cpp",
        "*.ui",
        "*.qrc"
    ]
}
