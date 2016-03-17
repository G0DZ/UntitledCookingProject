#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void setTextEdit(QString content);
<<<<<<< HEAD
    void on_pushButton_2_clicked();
    void getRecipesByName(QString content);
    void on_pushButton_3_clicked();

=======
    void transformImg(QString content);
>>>>>>> origin/master
private:
    Ui::MainWindow *ui;
    QPixmap genImg;
};

#endif // MAINWINDOW_H
