#ifndef PREVRECIPEMODEL_H
#define PREVRECIPEMODEL_H

#include <QAbstractListModel>
#include <prevrecipe.h>

class PrevRecipeModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum PrevRecipeRoles {
        TitleRole = Qt::UserRole + 1,
        ImgLinkRole,
        ViewsRole,
        AuthorNameRole,
        RecipeDescRole,
        LikesRole,
        VotesRole,
        RecipeUrlRole
    };

    PrevRecipeModel(QObject *parent = 0);

    void setPrevRecipes(const std::vector<PrevRecipe> vec);
    void resetModel();
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QVector<PrevRecipe> m_prevRecipes;
};

#endif // PREVRECIPEMODEL_H
