#ifndef COREMANAGER_H
#define COREMANAGER_H


#include <QObject>
#include <QQmlEngine>
#include <prevrecipemodel.h>
#include <prevrecipe.h>
#include "model/previewloadermanager.h"

class CoreManager : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(CoreManager)
public:
    static QObject *qmlInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
        {
            Q_UNUSED(engine);
            Q_UNUSED(scriptEngine);
            return new CoreManager;
        }
    explicit CoreManager(QObject *parent = 0);
    //
    Q_INVOKABLE void loadNameModel(QString str);
    Q_INVOKABLE void updateNameModel();
    Q_INVOKABLE PrevRecipeModel *getNameModel() const;
    Q_INVOKABLE void setNameModel(PrevRecipeModel *value);
private:
    PreviewLoaderManager* pLoader;
    PrevRecipeModel* nameModel;
    bool updateReadyFlag;
private slots:
    void modelFromLoader();
signals:
    void startLoad(QString);

};

#endif // COREMANAGER_H
