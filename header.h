#include <anotherwindow.h>

#include <QtWidgets/QApplication>
#include <QtWidgets>
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QApplication>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <QString>
#include <QDialog>
#include <QHBoxLayout>

namespace Ui
{
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
   ~MainWindow();

  private slots:
  void handleButton();
  void openFile();

private:
  Ui::MainWindow *ui;
  AnotherWindow *sWindow;
  QPushButton *ofd_button;
  QPushButton *close_button;
  QPushButton *manual_ofd_button;

};
