win32 {
    defineReplace(sampleSharedLibTarget) {
        TARGET_SUFFIX = ""
        CONFIG(debug,debug|release) {
            TARGET_SUFFIX = d
        }
        return ($${1}$${TARGET_SUFFIX})
    }
}
