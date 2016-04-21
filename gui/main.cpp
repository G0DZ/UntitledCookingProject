#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "model.h"
#include "controller/coremanager.h"
#include <prevrecipemodel.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    qmlRegisterType<PrevRecipeModel>("Qt.app.models",1,0,"PrevRec");
    qmlRegisterSingletonType<CoreManager>("Qt.app.core",1,0,"AppCore",&CoreManager::qmlInstance);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
