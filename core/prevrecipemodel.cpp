#include "prevrecipemodel.h"

PrevRecipeModel::PrevRecipeModel(QObject *parent) : QAbstractListModel(parent)
{

}

void PrevRecipeModel::setPrevRecipes(const std::vector<PrevRecipe> vec)
{
    beginResetModel();
    m_prevRecipes = QVector<PrevRecipe>::fromStdVector(vec);
    endResetModel();
}

void PrevRecipeModel::resetModel()
{
    beginResetModel();
    m_prevRecipes.clear();
    endResetModel();
}

int PrevRecipeModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return m_prevRecipes.count();
}

QVariant PrevRecipeModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= m_prevRecipes.count())
        return QVariant();

    const PrevRecipe &prevr = m_prevRecipes[index.row()];
    switch(role){
    case TitleRole:
        return prevr.getTitle();
    case ImgLinkRole:
        return prevr.getImgLink();
    case ViewsRole:
        return prevr.getViews();
    case AuthorNameRole:
        return prevr.getAuthorName();
    case RecipeDescRole:
        return prevr.getRecipeDesc();
    case LikesRole:
        return prevr.getLikes();
    case VotesRole:
        return prevr.getVotes();
    case RecipeUrlRole:
        return prevr.getRecipeUrl();
    }
    return QVariant();
}

//![0]
QHash<int, QByteArray> PrevRecipeModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    roles[ImgLinkRole] = "imgLink";
    roles[ViewsRole] = "views";
    roles[AuthorNameRole] = "authorName";
    roles[RecipeDescRole] = "recipeDesc";
    roles[LikesRole] = "likes";
    roles[VotesRole] = "votes";
    roles[RecipeUrlRole] = "recipeUrl";
    return roles;
}
