#ifndef SEARCHPARSER_H
#define SEARCHPARSER_H

#include <qgumbonode.h>
#include <qgumbodocument.h>
#include <QString>

#include <prevrecipe.h>

class SearchParser
{
public:
    SearchParser();
    bool parse(QString content);               //парсим страницу
    std::vector<PrevRecipe> getRecipesList() const;
    void setRecipesList(const std::vector<PrevRecipe> &value);
private:
    bool getListPart();         //пытаемся получить часть страницы с списком рецептов
    int parsePrevCount();       //получаем количество рецептов
    std::vector<PrevRecipe> parsePrevRecipes(); //получаем рецепты с данной страницы
    //переменные
    int elementsCount;          //количество рецептов ВСЕГО

    std::vector<PrevRecipe> recipesList;
    QString htmlPage;
    QGumboDocument *doc;
    QGumboNode *listPart;
};

#endif // SEARCHPARSER_H
