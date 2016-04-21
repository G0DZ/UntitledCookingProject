#ifndef PREVIEWLOADERMANAGER_H
#define PREVIEWLOADERMANAGER_H

#include <QThread>
#include <previewloader.h>

class PreviewLoaderManager : public QThread
{
    Q_OBJECT
public:
    PreviewLoaderManager();
    void startLoad(QString searchName);
    PreviewLoader pLoaderImpl;
private:
    void run();
signals:
    void loadFinished(); //external
    void onStuffImpl(QString); //internal
};

#endif // PREVIEWLOADERMANAGER_H
