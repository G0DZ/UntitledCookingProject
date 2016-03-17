#include "recipe.h"

Recipe::Recipe()
{

}

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

QString Recipe::getPublishDate() const
{
    return publishDate;
}

void Recipe::setPublishDate(const QString &value)
{
    publishDate = value;
}
