#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "httpconnect.h"
#include "recipeparser.h"

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
//    RecipeParser rc(content);
//    if(rc.parse()){
//        ui->textEdit->insertPlainText(rc.getRecipe().getTitle()+"\n");
//        ui->textEdit->insertPlainText(rc.getRecipe().getImgLink()+"\n");
//        ui->textEdit->insertPlainText(rc.getRecipe().getViews()+"\n");
//        ui->textEdit->insertPlainText(rc.getRecipe().getTime()+"\n");
//        ui->textEdit->insertPlainText(rc.getRecipe().getPeaces()+"\n");
//        ui->textEdit->insertPlainText(rc.getRecipe().getPublishDate()+"\n");
//        ui->textEdit->insertPlainText(rc.getRecipe().getAuthorName()+"\n");
//        ui->textEdit->insertPlainText(rc.getRecipe().getRecipeDesc()+"\n");
//        std::vector<IngredientsGroup> temp = rc.getRecipe().getIng();
//        for(IngredientsGroup group : temp){
//            ui->textEdit->insertPlainText(group.groupName+"\n");
//            for(QString str : group.content){
//              ui->textEdit->insertPlainText(str+"\n");
//            }
//            ui->textEdit->insertPlainText("\n\n");
//        }
//        std::vector<RecipeStep> temp2 = rc.getRecipe().getSteps();
//        for(RecipeStep step : temp2){
//            ui->textEdit->insertPlainText(step.highImageLink+"\n");
//            ui->textEdit->insertPlainText(step.lowImageLink+"\n");
//            ui->textEdit->insertPlainText(step.text+"\n\n\n");
//        }
//        std::vector<RecipeTextElement> temp3 = rc.getRecipe().getText();
//        for(RecipeTextElement step : temp3){
//            ui->textEdit->insertPlainText(step.text);
//        }
//    }
}
