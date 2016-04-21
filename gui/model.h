#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <QQmlEngine>
#include <prevrecipemodel.h>
#include <prevrecipe.h>

class Model : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Model)
public:
    static QObject *qmlInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
        {
            Q_UNUSED(engine);
            Q_UNUSED(scriptEngine);
            return new Model;
        }
    explicit Model(QObject *parent = 0);
    //
    Q_INVOKABLE void updateNameModel(QString str);
    Q_INVOKABLE PrevRecipeModel *getNameModel() const;
    Q_INVOKABLE void setNameModel(PrevRecipeModel *value);
private:
    PrevRecipeModel* nameModel;
    bool updateReadyFlag;
};

#endif // CORE_H
