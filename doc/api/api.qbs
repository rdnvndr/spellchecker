import "../main.qbs" as DocProduct

DocProduct {
    name: "spellchecker-api"
    type: "docs"

    docName: "spellchecker-dev"
    Group {
        fileTagsFilter: ["docs"]
        qbs.install: true
        qbs.installDir: product.docPath
    }
}
