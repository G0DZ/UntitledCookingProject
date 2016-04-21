#include "previewloadermanager.h"
#include <previewloader.h>
#include <QDebug>

PreviewLoaderManager::PreviewLoaderManager()
{
    //signal to thread
   connect(this,
           SIGNAL(onStuffImpl(QString)),
           &pLoaderImpl,
           SLOT(loadAllPreviews(QString)));

   // signal from thread
   connect(&pLoaderImpl,
           SIGNAL(previewsFinished()),
           this,
           SIGNAL(loadFinished()));
}

void PreviewLoaderManager::startLoad(QString searchUrl)
{
    emit onStuffImpl(searchUrl);
}

void PreviewLoaderManager::run()
{
    exec();
}
