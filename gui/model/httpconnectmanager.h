#ifndef HTTPCONNECTMANAGER_H
#define HTTPCONNECTMANAGER_H

#include <QObject>
#include <QThread>
#include <httpconnect.h>

class HttpConnectManager : public QThread
{
    Q_OBJECT
public:
    HttpConnectManager();
public:
    void startDownload(QString urltext, contentBufferType cbtType = CBT_BUFFER, contentSilenceMode csmMode = CSM_LOUD);
private:
    void run();
signals:
    void contentFinished(QString); //external
    void onStuffImpl(QString urltext, contentBufferType cbtType, contentSilenceMode csmMode); //internal
};

#endif // HTTPCONNECTMANAGER_H
