#include "prevrecipe.h"

PrevRecipe::PrevRecipe()
{

}

QString PrevRecipe::getTitle() const
{
    return title;
}

void PrevRecipe::setTitle(const QString &value)
{
    title = value;
}

QString PrevRecipe::getImgLink() const
{
    return imgLink;
}

void PrevRecipe::setImgLink(const QString &value)
{
    imgLink = value;
}

QString PrevRecipe::getViews() const
{
    return views;
}

void PrevRecipe::setViews(const QString &value)
{
    views = value;
}

QString PrevRecipe::getAuthorName() const
{
    return authorName;
}

void PrevRecipe::setAuthorName(const QString &value)
{
    authorName = value;
}

QString PrevRecipe::getRecipeDesc() const
{
    return recipeDesc;
}

void PrevRecipe::setRecipeDesc(const QString &value)
{
    recipeDesc = value;
}

QString PrevRecipe::getLikes() const
{
    return likes;
}

void PrevRecipe::setLikes(const QString &value)
{
    likes = value;
}

QString PrevRecipe::getVotes() const
{
    return votes;
}

void PrevRecipe::setVotes(const QString &value)
{
    votes = value;
}

QString PrevRecipe::getRecipeUrl() const
{
    return recipeUrl;
}

void PrevRecipe::setRecipeUrl(const QString &value)
{
    recipeUrl = value;
}
