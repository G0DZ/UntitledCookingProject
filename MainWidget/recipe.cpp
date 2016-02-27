#include "recipe.h"

std::vector<IngredientsGroup> Recipe::getIng() const
{
    return ing;
}

void Recipe::setIng(const std::vector<IngredientsGroup> &value)
{
    ing = value;
}

std::vector<RecipeStep> Recipe::getSteps() const
{
    return steps;
}

void Recipe::setSteps(const std::vector<RecipeStep> &value)
{
    steps = value;
}

std::vector<RecipeTextElement> Recipe::getText() const
{
    return text;
}

void Recipe::setText(const std::vector<RecipeTextElement> &value)
{
    text = value;
}

QString Recipe::getTime() const
{
    return time;
}

void Recipe::setTime(const QString &value)
{
    time = value;
}

QString Recipe::getPeaces() const
{
    return peaces;
}

void Recipe::setPeaces(const QString &value)
{
    peaces = value;
}

Recipe::Recipe()
{

}

QString Recipe::getTitle() const
{
    return title;
}

void Recipe::setTitle(const QString &value)
{
    title = value;
}

QString Recipe::getImgLink() const
{
    return imgLink;
}

void Recipe::setImgLink(const QString &value)
{
    imgLink = value;
}

QString Recipe::getViews() const
{
    return views;
}

void Recipe::setViews(const QString &value)
{
    views = value;
}

QString Recipe::getAuthorName() const
{
    return authorName;
}

void Recipe::setAuthorName(const QString &value)
{
    authorName = value;
}

QString Recipe::getPublishDate() const
{
    return publishDate;
}

void Recipe::setPublishDate(const QString &value)
{
    publishDate = value;
}

QString Recipe::getRecipeDesc() const
{
    return recipeDesc;
}

void Recipe::setRecipeDesc(const QString &value)
{
    recipeDesc = value;
}
