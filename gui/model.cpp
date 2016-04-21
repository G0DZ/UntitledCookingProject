#include "model.h"
#include <QDebug>

Model::Model(QObject *parent) : QObject(parent)
{
   nameModel = new PrevRecipeModel();
   updateReadyFlag = true;
}

void Model::updateNameModel(QString str)
{
    if(updateReadyFlag == false)
        return;
    else{
        updateReadyFlag = false;
    }
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

PrevRecipeModel *Model::getNameModel() const
{
    return nameModel;
}

void Model::setNameModel(PrevRecipeModel *value)
{
    nameModel = value;
}
