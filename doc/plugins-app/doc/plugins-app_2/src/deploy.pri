# @brief copyFiles копирование одного или нескольких файлов
# @param srcDir полное имя исходной директории
# @param dstDir полное имя конечной директории
# @param files имя копируемого файла (если несколько, то через пробел)
defineTest(copyFiles) {
    srcDir = $${1}
    dstDir = $${2}
    files = $${3}

    for(file, files) {
        srcFile = $${srcDir}/$${file}
        dstFile = $${dstDir}/$${file}

        win32 { # Коррекция разделителей для ОС Windows
            srcFile ~= s,/,\\,g
            dstFile ~= s,/,\\,g
        }

        QMAKE_POST_LINK += \
            $$QMAKE_COPY $$quote($${srcFile}) $$quote($${dstFile}) $$escape_expand(\\n\\t)
    }

    export(QMAKE_POST_LINK)
}

# TODO: мне не нравиться эта функция
defineTest(copyDirs) {
    srcDir = $${1}
    dstDir = $${2}

        win32 { # Коррекция разделителей для ОС Windows
            srcDir ~= s,/,\\,g
            dstDir ~= s,/,\\,g
        }

        QMAKE_POST_LINK += \
            $$QMAKE_COPY_DIR $$quote($${srcDir}) $$quote($${dstDir}) $$escape_expand(\\n\\t)

    export(QMAKE_POST_LINK)
}
