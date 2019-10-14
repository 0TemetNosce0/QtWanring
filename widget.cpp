#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btn_png_clicked()
{
    const QStringList paths = QFileDialog::getOpenFileNames(this, "Please choose PNG", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), "*.png");
    if(paths.isEmpty())
    {
        return;
    }

    foreach(const QString &path, paths)
    {
        QImage image(path);
        if(image.isNull())
        {
            continue;
        }

        if(!image.save(path, "PNG"))
        {
            QMessageBox::warning(this, "Error", QString("%1 save fail").arg(path));
        }
    }

    QMessageBox::information(this, "Done", "All png image processing is completed");
}




