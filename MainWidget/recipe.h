#ifndef RECIPE_H
#define RECIPE_H

#include <QString>
#include <vector>

//структура для хранения ингредиентов
typedef struct {
    QString groupName; //имя группы
    std::vector<QString> content; //состав группы
} IngredientsGroup;

//структура для хранения шагов рецепта
typedef struct {
    QString highImageLink; //высокое разрешение картинки
    QString lowImageLink;  //низкое
    QString text;          //текст шага
} RecipeStep;

//типы ссылок в рич тексте
enum class RecipeTextType {TEXT, IMAGE, HREF};

//хранит в себе элемент текста
typedef struct {
    RecipeTextType type; //вид
    QString text;        //содержание
} RecipeTextElement;

//сам рецепт
class Recipe
{  
private:
    QString title;                          //название
    QString imgLink;                        //картинка
    QString views;                          //просмотры
    QString authorName;                     //автор
    QString publishDate;                    //дата публикации
    QString recipeDesc;                     //описание
    QString time;                           //время приготовления
    QString peaces;                         //порции
    std::vector<IngredientsGroup> ing;      //ингредиенты
    std::vector<RecipeStep> steps;          //шаги
    std::vector<RecipeTextElement> text;    //текст
public:
    Recipe();

    QString getTitle() const;
    void setTitle(const QString &value);

    QString getImgLink() const;
    void setImgLink(const QString &value);

    QString getViews() const;
    void setViews(const QString &value);

    QString getAuthorName() const;
    void setAuthorName(const QString &value);

    QString getPublishDate() const;
    void setPublishDate(const QString &value);

    QString getRecipeDesc() const;
    void setRecipeDesc(const QString &value);

    std::vector<IngredientsGroup> getIng() const;
    void setIng(const std::vector<IngredientsGroup> &value);

    std::vector<RecipeStep> getSteps() const;
    void setSteps(const std::vector<RecipeStep> &value);

    std::vector<RecipeTextElement> getText() const;
    void setText(const std::vector<RecipeTextElement> &value);

    QString getTime() const;
    void setTime(const QString &value);

    QString getPeaces() const;
    void setPeaces(const QString &value);
};

#endif // RECIPE_H
