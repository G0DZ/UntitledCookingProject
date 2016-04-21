#include "previewloader.h"
#include <QDebug>
#include <httpconnect.h>
#include <QTextCodec>
#include <searchparser.h>

PreviewLoader::PreviewLoader()
{

}

void PreviewLoader::loadAllPreviews(QString searchName)
{
    //qDebug() << "авпва";
    //формируем сроку для запроса
    QByteArray result = QTextCodec::codecForName("Windows-1251")->fromUnicode(searchName.toLower())
            .toPercentEncoding();
    QString urlString = "http://www.povarenok.ru/recipes/search/?name=" + result;
    //qDebug() << urlString;
    //получаем первую страницу выдачи.
    HttpConnect *newConnect = new HttpConnect();
    newConnect->downloadContent(urlString,CBT_BUFFER,CSM_LOUD);
    connect(newConnect,SIGNAL(contentFinished(QString)),this,SLOT(parsePage(QString)));
}

void PreviewLoader::parsePage(QString content)
{
    SearchParser sp;
    if(sp.parse(content)){
         allPreview = sp.getRecipesList();
         //QDEBUG
//         for(PrevRecipe recipe : allPreview){
//             qDebug() << "\n"+recipe.getTitle()+"   "+recipe.getRecipeUrl()+"\n"
//                                           +recipe.getImgLink()+"\n"+recipe.getRecipeDesc()+"\n"
//                                           +recipe.getAuthorName()+"   "+recipe.getViews()+"   "
//                                           +recipe.getLikes()+"    "+recipe.getVotes()+"\n\n";
//         }
         emit previewsFinished();
    }
}

std::vector<PrevRecipe> PreviewLoader::getAllPreview() const
{
    return allPreview;
}

void PreviewLoader::setAllPreview(const std::vector<PrevRecipe> &value)
{
    allPreview = value;
}
