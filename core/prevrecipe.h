#ifndef PREVRECIPE_H
#define PREVRECIPE_H

#include <QObject>

class PrevRecipe
{
public:
    PrevRecipe();
    QString getTitle() const;
    void setTitle(const QString &value);

    QString getImgLink() const;
    void setImgLink(const QString &value);

    QString getViews() const;
    void setViews(const QString &value);

    QString getAuthorName() const;
    void setAuthorName(const QString &value);

    QString getRecipeDesc() const;
    void setRecipeDesc(const QString &value);

    QString getLikes() const;
    void setLikes(const QString &value);

    QString getVotes() const;
    void setVotes(const QString &value);

    QString getRecipeUrl() const;
    void setRecipeUrl(const QString &value);

protected:
    QString title;                          //название
    QString imgLink;                        //картинка
    QString views;                          //просмотры
    QString authorName;                     //автор
    QString recipeDesc;                     //описание
    QString likes;                          //лайки
    QString votes;                          //голоса
    QString recipeUrl;                      //ссылка на рецепт
};

#endif // PREVRECIPE_H
