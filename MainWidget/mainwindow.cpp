#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "httpconnect.h"
#include "recipeparser.h"
#include <QMovie>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //вот  в этом участке кода будем парсить страницу

    // Общее оформление
        // Размещаем фон
        QMovie *background = new QMovie(":/Pictures/background.gif");
        ui->label_bg->setMovie(background);
        ui->label_bg->setScaledContents(true);
        background->start();
        // Размещаем котика
        QMovie *bakercat = new QMovie(":/Pictures/bakercat.gif");
        ui->label_cat->setMovie(bakercat);
        ui->label_cat->setScaledContents(true);
        bakercat->start();
        // Готовим место для главной картинки рецепта
        //ui->label_genImg->setScaledContents(true);
        // Делаем TextLabel-ы пустыми
        ui->label_title->setText("");
        ui->label_genImg->setText("");
        ui->label_views->setText("");
        ui->label_publishingDate->setText("");
        ui->label_author->setText("");
        ui->label_time->setText("");
        ui->label_peaces->setText("");
        ui->label_recipeDesc->setText("");
        // Шрифт
        this->setFont(QFont("Comic Sans MS"));
        // Описание рецепта
        //ui->scrollArea->
        ui->label_recipeDesc->setWordWrap(true);
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
        Recipe rec = rc.getRecipe();
        // Размещаем название рецепта
            // Устанавливаем стили
            ui->label_title->setWordWrap(true);
            QFont font = ui->label_title->font();
            ui->label_title->setScaledContents(true);
            font.setPointSize(20);
            font.setBold(true);
            ui->label_title->setFont(font);
            QPalette sample_palette;
            sample_palette.setColor(QPalette::WindowText, QColor(153,116,75));
            ui->label_title->setPalette(sample_palette);
            // Собственно название
            if (rec.getTitle() != "")
                ui->label_title->setText(rec.getTitle());
        // Размещаем главное изображение блюда
        if (rec.getImgLink() != ""){
            HttpConnect *newConnect = new HttpConnect();
            newConnect->downloadContent(rec.getImgLink(),CBT_BUFFER,CSM_SILENCE);
            connect(newConnect,SIGNAL(contentFinished(QString)),this,SLOT(transformImg(QString)));
        }
        // Количество просмотров
        if (rec.getViews() != "") {
            ui->label_views->setText(rec.getViews());
        }
        // Дата публикации
        if (rec.getPublishDate() != "") {
            ui->label_publishingDate->setText(rec.getPublishDate());
        }
        // Имя автора
        if (rec.getAuthorName() != "") {
            ui->label_author->setText(rec.getAuthorName());
        }
        // Время приготовления
        if (rec.getTime() != "") {
            ui->label_time->setText(rec.getTime());
        }
        // Количество порций
        if (rec.getPeaces() != "") {
            ui->label_peaces->setText(rec.getPeaces());
        }
        // Общее описание рецепта
        if (rec.getRecipeDesc() != "") {
           ui->label_recipeDesc->setText(rec.getRecipeDesc());
        }




       // ui->textEdit->insertPlainText(rc.getRecipe().getRecipeDesc()+"\n");



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

void MainWindow::transformImg(QString content)
{
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    QByteArray encodedString = codec->fromUnicode(content);
    genImg.loadFromData(encodedString,"jpg");
    ui->label_genImg->setPixmap(genImg);
}
