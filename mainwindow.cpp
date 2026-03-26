#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::onNewDocument);
    connect(ui->actionOpen, &QAction::triggered, this, [this]() {
        statusBar()->showMessage(tr("Open clicked – will be implemented in PR5"), 2000);
    });
    connect(ui->actionSave, &QAction::triggered, this, [this]() {
        statusBar()->showMessage(tr("Save clicked – will be implemented in PR5"), 2000);
    });
    connect(ui->actionSaveAs, &QAction::triggered, this, [this]() {
        statusBar()->showMessage(tr("Save As clicked – will be implemented in PR5"), 2000);
    });
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::onExit);

    connect(ui->actionCut, &QAction::triggered, ui->editor, &QPlainTextEdit::cut);
    connect(ui->actionCopy, &QAction::triggered, ui->editor, &QPlainTextEdit::copy);
    connect(ui->actionPaste, &QAction::triggered, ui->editor, &QPlainTextEdit::paste);
    connect(ui->actionSelectAll, &QAction::triggered, ui->editor, &QPlainTextEdit::selectAll);

    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::onAbout);

    statusBar()->showMessage(tr("Ready"), 2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewDocument()
{
    bool ok;
    QString name = QInputDialog::getText(this, tr("New Document"),
                                         tr("Document name:"), QLineEdit::Normal,
                                         tr("untitled"), &ok);
    if (ok && !name.trimmed().isEmpty()) {
        ui->editor->clear();
        statusBar()->showMessage(tr("Created new document: %1").arg(name), 3000);
    }
}

void MainWindow::onExit()
{
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, tr("Exit"),
        tr("Are you sure you want to exit?"),
        QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        close();
    }
}

void MainWindow::onAbout()
{
    QMessageBox::about(this, tr("About QuickPad"),
                       tr("QuickPad\nVersion 1.0"));
}
