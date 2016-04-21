#include "httpconnectmanager.h"

HttpConnectManager::HttpConnectManager()
{

}

void HttpConnectManager::startDownload(QString urltext, contentBufferType cbtType,
                                       contentSilenceMode csmMode)
{
    emit onStuffImpl(urltext, cbtType, csmMode);
}

void HttpConnectManager::run()
{
    HttpConnect connectImpl;
    // signal to thread
    connect(this,
            SIGNAL(onStuffImpl(QString,contentBufferType,contentSilenceMode)),
            &connectImpl,
            SLOT(downloadContent(QString,contentBufferType,contentSilenceMode)));

    // signal from thread
    connect(&connectImpl,
            SIGNAL(contentFinished(QString)),
            this,
            SIGNAL(contentFinished(QString)));
    exec();
}
