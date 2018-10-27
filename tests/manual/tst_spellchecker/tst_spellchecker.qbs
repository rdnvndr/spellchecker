import "../main.qbs" as SpellCheckerProduct

SpellCheckerProduct {
    name: "tst_spellchecker_mnl"

    productname: ""
    version:     "1.0.0"
    description: ""
    company:     ""
    copyright:   ""

    Depends { name: "Qt"; submodules: ["core"] }
    Depends { name: "spellchecker" }
    
    consoleApplication: true

    files: [
        "*.h",
        "*.cpp",
        "*.ui",
        "*.qrc"
    ]
}
