# Input
HEADERS  += $$PWD/httpconnect.h \
	    $$PWD/recipe.h \
	    $$PWD/recipeparser.h \
	    $$PWD/prevrecipe.h \
	    $$PWD/searchparser.h \
    $$PWD/prevrecipemodel.h \
    $$PWD/previewloader.h

SOURCES += $$PWD/httpconnect.cpp \
	$$PWD/recipe.cpp \
	$$PWD/recipeparser.cpp \
	$$PWD/prevrecipe.cpp \
	$$PWD/searchparser.cpp \
    $$PWD/prevrecipemodel.cpp \
    $$PWD/previewloader.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libs/QGumboParser/release/ -lQGumboParser
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libs/QGumboParser/debug/ -lQGumboParser
else:unix: LIBS += -L$$OUT_PWD/../libs/QGumboParser/ -lQGumboParser

INCLUDEPATH += $$PWD/../libs/QGumboParser
DEPENDPATH += $$PWD/../libs/QGumboParser

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/QGumboParser/release/libQGumboParser.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/QGumboParser/debug/libQGumboParser.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/QGumboParser/release/QGumboParser.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/QGumboParser/debug/QGumboParser.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../libs/QGumboParser/libQGumboParser.a
