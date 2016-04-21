#include "coremanager.h"
#include <QDebug>
#include "model/previewloadermanager.h"

CoreManager::CoreManager(QObject *parent) : QObject(parent)
{
   nameModel = new PrevRecipeModel();
   updateReadyFlag = true;
   pLoader = new PreviewLoaderManager();
   pLoader->start();
   connect(this, SIGNAL (startLoad(QString)),pLoader,SIGNAL(onStuffImpl(QString)));
   connect(pLoader, SIGNAL(loadFinished()),this,SLOT(modelFromLoader()));
}

void CoreManager::loadNameModel(QString str)
{
//    if(pLoader != NULL){
//        pLoader->quit();
//        if(pLoader->isRunning()){
//            pLoader->terminate();
//        }
//        pLoader->deleteLater();
//        pLoader = NULL;
//        nameModel->resetModel();
//    }
    //pLoader = new PreviewLoaderManager();
    //pLoader->start();
    //tconnect(this, SIGNAL (startLoad(QString)),pLoader,SIGNAL(onStuffImpl(QString)));
    //while(1){
    emit startLoad(str);
    //}
}

void CoreManager::updateNameModel()
{
    PrevRecipe A;
    A.setAuthorName("authorName");
    A.setImgLink("http://www.povarenok.ru/data/cache/2015may/13/03/1141247_46241-150x150x.jpg");
    A.setLikes("500");
    A.setRecipeDesc("Это рецепт поистине королевской ватрушки. Нежнейшая сливочно-творожная начинка просто тает в орту, шоколадное тесто приятно хрустит, а аромат смородины добавляет ему свежесть и кислинку. Это мой любимый рецепт королевской ватрушки. ");
    A.setRecipeUrl("http://www.povarenok.ru/recipes/show/107907/");
    A.setTitle("Королевская шоколадно-сливочная ватрушка с черной смородиной");
    A.setViews("999999");
    A.setVotes("9999999");
    std::vector<PrevRecipe> B;
    B.emplace_back(A);
    qDebug() << "hello";
    updateReadyFlag = true;
    nameModel->setPrevRecipes(B);
}

PrevRecipeModel *CoreManager::getNameModel() const
{
    return nameModel;
}

void CoreManager::setNameModel(PrevRecipeModel *value)
{
    nameModel = value;
}

void CoreManager::modelFromLoader()
{
    nameModel->setPrevRecipes(pLoader->pLoaderImpl.getAllPreview());
}
