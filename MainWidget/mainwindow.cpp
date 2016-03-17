#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "httpconnect.h"
#include "recipeparser.h"
#include "searchparser.h"
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //вот  в этом участке кода будем парсить страницу

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    HttpConnect *newConnect = new HttpConnect();
    newConnect->downloadContent(ui->lineEdit->text(),CBT_BUFFER,CSM_LOUD);
    connect(newConnect,SIGNAL(contentFinished(QString)),this,SLOT(setTextEdit(QString)));
}

void MainWindow::setTextEdit(QString content)
{
    //ui->textEdit->setText(content);
    //ui->textEdit->setText(content.toStdString().c_str());
    RecipeParser rc(content);
    if(rc.parse()){
        ui->textEdit->insertPlainText(rc.getRecipe().getTitle()+"\n");
        ui->textEdit->insertPlainText(rc.getRecipe().getImgLink()+"\n");
        ui->textEdit->insertPlainText(rc.getRecipe().getViews()+"\n");
        ui->textEdit->insertPlainText(rc.getRecipe().getTime()+"\n");
        ui->textEdit->insertPlainText(rc.getRecipe().getPeaces()+"\n");
        ui->textEdit->insertPlainText(rc.getRecipe().getPublishDate()+"\n");
        ui->textEdit->insertPlainText(rc.getRecipe().getAuthorName()+"\n");
        ui->textEdit->insertPlainText(rc.getRecipe().getRecipeDesc()+"\n");
        std::vector<IngredientsGroup> temp = rc.getRecipe().getIng();
        for(IngredientsGroup group : temp){
            ui->textEdit->insertPlainText(group.groupName+"\n");
            for(QString str : group.content){
              ui->textEdit->insertPlainText(str+"\n");
            }
            ui->textEdit->insertPlainText("\n\n");
        }
        std::vector<RecipeStep> temp2 = rc.getRecipe().getSteps();
        for(RecipeStep step : temp2){
            ui->textEdit->insertPlainText(step.highImageLink+"\n");
            ui->textEdit->insertPlainText(step.lowImageLink+"\n");
            ui->textEdit->insertPlainText(step.text+"\n\n\n");
        }
        std::vector<RecipeTextElement> temp3 = rc.getRecipe().getText();
        for(RecipeTextElement step : temp3){
            ui->textEdit->insertPlainText(step.text);
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
    //формируем сроку для запроса
    QByteArray result = QTextCodec::codecForName("Windows-1251")->fromUnicode(ui->lineEdit_2->text())
            .toPercentEncoding();
    QString urlString = "http://www.povarenok.ru/recipes/search/?name=" + result;
    //ui->textEdit->insertPlainText(result);
    //получаем первую страницу выдачи.
    HttpConnect *newConnect = new HttpConnect();
    newConnect->downloadContent(urlString,CBT_BUFFER,CSM_LOUD);
    connect(newConnect,SIGNAL(contentFinished(QString)),this,SLOT(getRecipesByName(QString)));
}

void MainWindow::getRecipesByName(QString content)
{
    SearchParser sp;
    if(sp.parse(content)){
         std::vector<PrevRecipe> temp = sp.getRecipesList();
         for(PrevRecipe recipe : temp){
             ui->textEdit->insertPlainText("\n"+recipe.getTitle()+"   "+recipe.getRecipeUrl()+"\n"
                                           +recipe.getImgLink()+"\n"+recipe.getRecipeDesc()+"\n"
                                           +recipe.getAuthorName()+"   "+recipe.getViews()+"   "
                                           +recipe.getLikes()+"    "+recipe.getVotes()+"\n\n");
         }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit->clear();
    //формируем сроку для запроса
    QString str = ui->lineEdit_3->text();
    QStringList list = str.split(',', QString::SkipEmptyParts);
    QString result = "";
    for(int i = 0; i < list.size(); i++){
        if(result!="")
            result+="+";
        QString a = list.at(i);
        a = a.replace(" ","");
        a+=",";
        result+= QTextCodec::codecForName("Windows-1251")->fromUnicode(a)
                .toPercentEncoding();
    }
    QString urlString = "http://www.povarenok.ru/recipes/search/?ing=" + result+"+&cat=";
    ui->textEdit->insertPlainText(result);
    //получаем первую страницу выдачи.
    HttpConnect *newConnect = new HttpConnect();
    newConnect->downloadContent(urlString,CBT_BUFFER,CSM_LOUD);
    connect(newConnect,SIGNAL(contentFinished(QString)),this,SLOT(getRecipesByName(QString)));
}
