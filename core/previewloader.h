#ifndef PREVIEWLOADER_H
#define PREVIEWLOADER_H

#include <QObject>
#include <prevrecipe.h>

class PreviewLoader : public QObject
{
    Q_OBJECT
public:
    PreviewLoader();
    std::vector<PrevRecipe> getAllPreview() const;
    void setAllPreview(const std::vector<PrevRecipe> &value);
public slots:
    void loadAllPreviews(QString searchName);
    void parsePage(QString content);
    //void getPage();
signals:
    void previewsFinished();
    //void pageReady();
private:
    std::vector<PrevRecipe> allPreview;
};

#endif // PREVIEWLOADER_H
