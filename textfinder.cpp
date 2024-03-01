#include "textfinder.h"
#include "./ui_textfinder.h"

TextFinder::TextFinder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    ui->addtext->setPlaceholderText("Enter text to append here");
    ui->searchfield->setPlaceholderText("Enter word to find here");;
    loadTextFile();
}

TextFinder::~TextFinder()
{
    delete ui;
}

void TextFinder::loadTextFile(){
    QFile inputFile("absolute_path_to_2input.txt");
    inputFile.open(QIODevice::ReadWrite);
    inputFile.seek(0);
    QTextStream in(&inputFile);
    QString line = in.readAll();
    // qDebug() << line;
    inputFile.close();

    ui->textEdit->setPlainText(line);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start , QTextCursor::MoveAnchor , 1);
}

void TextFinder::on_addbtn_clicked()
{
    QString newString = ui->addtext->text();
    QFile inputFile("absolute_path_to_2input.txt");
    inputFile.open(QIODevice::ReadWrite);

    QTextStream stream(&inputFile);
    stream.seek(inputFile.size());
    stream << newString <<"\n";
    inputFile.close();

    inputFile.open(QIODevice::ReadWrite);
    QString line = stream.readAll();
    ui->textEdit->setPlainText(line);

    ui->addtext->clear();
}


void TextFinder::on_deleteallbtn_clicked()
{
    QFile inputFile("absolute_path_to_2input.txt");
    inputFile.open(QIODevice::ReadWrite | QIODevice::Truncate);
    inputFile.close();

    inputFile.open(QIODevice::ReadWrite);
    QTextStream stream(&inputFile);
    stream.seek(inputFile.size());
    QString line = stream.readAll();
    ui->textEdit->setPlainText(line);
}


void TextFinder::on_findbtn_clicked()
{
    QString searchString = ui->searchfield->text();
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
    ui->textEdit->setTextCursor(cursor);
    ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
    ui->searchfield->clear();
}

