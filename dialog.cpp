#include "dialog.h"
#include "ui_dialog.h"

#include <QColor>
#include <QFile>
#include <QTextStream>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <QProcess>
#include <QFileDialog>
//include "stable.h"
#include <sys/stat.h>
#include <QDirIterator>
using namespace std;
#include <iostream>
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
QString s;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
QString  Nazvaniye_fayla_s_neyronami_i_signalom ;
QString  Nazvaniye_fayla_s_bmp;
  int var = 3;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {
  ui->setupUi(this);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Теперь это надо в цикле файлы с 4 по 1452
    for (int var = 4; var < 1452; ++var)
    {
  ui->textEdit->clear();
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /// начнём с  /mnt/247E7EDA7E7EA3E8/картинки/RandomCrosswords/ там кроссвордные картинки с именами числами
  /// начинаем с 3 файла
  ///
  //  for (int var = 3; var < 1452; ++var)
  //  {
//  int var = 3;
  Nazvaniye_fayla_s_bmp="/mnt/247E7EDA7E7EA3E8/картинки/RandomCrosswords/"+QString::number(var);
                              //  } 
                              
                                  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                  /// \brief img
                                  /// \return 
                                  ///  
                                  QImage img(
                                      
                                      Nazvaniye_fayla_s_bmp.toStdString().c_str()
                                      //NOTE: файл изображения bmp
                                      
                                      ); // входящий файл изображения
  
  
  s = QString::number(img.height());
  
  s = QString::number(img.width());
  
  
  int kolichestvo = img.height() * img.width();
  s = QString::number(kolichestvo);
  
  // int z;
  for (int x = 0; x < img.width(); x++)
      for (int y = 0; y < img.height(); y++)
          ui->textEdit->append(QString::number(img.pixel(x, y)));
  
  // Заполнили текстовое первое поле
  //  QProcess().execute("/home/viktor/my_scripts_2/zvuk.sh");
  //i->label_2->settext(
  ui->label_2->setText ("textEdit заполнено");
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///// автоматически определяем новейший файл /
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  long long sekundi=0;
  QString noveyshiy_katalog;
  /// 
  struct stat fileInfo; 
  /// 
  QDirIterator it("/home/viktor/Изображения/edinitsi/Sgenerirovannye_fayly",
                  QDirIterator::NoIteratorFlags
                  //  QDirIterator::Subdirectories
                  );
  while (it.hasNext()) {
      QString dir = it.next();
      // qDebug()
      if (dir.toStdString()!="/home/viktor/Изображения/edinitsi/Sgenerirovannye_fayly/." &&
          dir.toStdString()!="/home/viktor/Изображения/edinitsi/Sgenerirovannye_fayly/..")
      {
          // std::cout     << dir.toStdString()<< endl;
          if (stat(dir.toStdString().c_str(), &fileInfo) != 0) {  // Use stat( ) to get the info
              std::cerr << "Error: " << strerror(errno) << '\n';
              //   return(EXIT_FAILURE);
          }
          //  std::cout <<  "Прошло секунд эпохи Unix до создания каталога     : " << fileInfo.st_ctime << endl;
          
          if (fileInfo.st_ctime >sekundi)
          {
              noveyshiy_katalog=dir.toStdString().c_str();
              sekundi=fileInfo.st_ctime ;
          }
      }
      
      
  }
  std::cout << "Новейший каталог: "<< noveyshiy_katalog.toStdString ()<<"; время создания: "<< sekundi<<endl;
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Nazvaniye_fayla_s_neyronami_i_signalom=noveyshiy_katalog+"/neurons_and_signal.txt";
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                           ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                           
                                           QFile file_n(
                                               
                                               Nazvaniye_fayla_s_neyronami_i_signalom.toStdString().c_str()
                                               // тут надо на уже сделанный прочитать
                                               
                                               //NOTE: файл neyroni.txt
                                               
                                               );
  // заряды нейронов
  if (!file_n.open(QIODevice::ReadOnly | QIODevice::Text))
      return;
  for (int var2 = 1; var2 < 202; ++var2) { // 204
      ui->textEdit_2->append(
          file_n.readLine()
              .simplified()); // во второе текстовое поле вывели все нейроны
  }
  
  // теперь в конец первого текстового поля добавим из второго
  QString str = ui->textEdit_2->toPlainText();
  QStringList strList =
      str.split('\n'); // разбиваем строку из текстедита на отдельные строки
  
  for (int var2 = 100; var2 < 201; ++var2) { // 202
      
      str = strList.at(var2); // берем строку
      ui->textEdit->append(str);
      // ui->textEdit->append(file_n.readLine(var).simplified());
      //  file.readLine().simplified()
  }
  file_n.close();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Куда записать файл с нейронами и сигналами txt
  // в папке /home/viktor/Изображения/edinitsi/Sgenerirovannye_fayly/ надо создать новую папку типа "2-r"; 2
  // сконструируем имя папки
  QString imia_papki= QString::number(var)+"-r";
// теперь надо созать эту папку
  QDir().mkdir("/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/"+imia_papki);
// и создать в этой папке файл neurons_and_signal.txt

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
  QString fname = "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/"+imia_papki+"/neurons_and_signal.txt";
  QFile file(fname);
  if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
    //  file.write("blablabla");
      file.close();
  }// else не удалось создать/открыть файл
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///  
  QFile file3(
      
      fname.toStdString().c_str()
      // перезаписался /home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/0-2/neurons_and_signal.txt с сигналом 1-2
      // а надо выбрать куда его сохранить
      // перезаписать с новым сигналом
      //NOTE: файл neyroni_i_signal.txt
      
      ); // выходной файл
  if (!file3.open(QIODevice::WriteOnly | QIODevice::Text))
      return;
  QTextStream out3(&file3); //поток для записи текста
  out3 << ui->textEdit
              ->toPlainText(); // записали картинку в neyroni_i_signal.txt
  
  file3.close();
 // QProcess().execute("/home/viktor/my_scripts_2/zvuk.sh");
  ui->label_3->setText ("Файл /"+imia_papki+"/neurons_and_signal.txt сгенерирован.");
///
    } 
} // Dialog

Dialog::~Dialog() { delete ui; }
// считываем картинку:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::on_pushButton_clicked
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////// кнопка считать файл изображения //////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
void Dialog::on_pushButton_clicked() {
  ui->textEdit->clear();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// начнём с  /mnt/247E7EDA7E7EA3E8/картинки/RandomCrosswords/ там кроссвордные картинки с именами числами
/// начинаем с 3 файла
///
//  for (int var = 3; var < 1452; ++var)
//  {
  int var = 3;
      Nazvaniye_fayla_s_bmp="/mnt/247E7EDA7E7EA3E8/картинки/RandomCrosswords/"+QString::number(var);
//  } 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \brief img
  /// \return 
  ///  
  QImage img(

      Nazvaniye_fayla_s_bmp.toStdString().c_str()
      //NOTE: файл изображения bmp
      
             ); // входящий файл изображения


  s = QString::number(img.height());

  s = QString::number(img.width());


  int kolichestvo = img.height() * img.width();
  s = QString::number(kolichestvo);

 // int z;
  for (int x = 0; x < img.width(); x++)
    for (int y = 0; y < img.height(); y++)
      ui->textEdit->append(QString::number(img.pixel(x, y)));

  // Заполнили текстовое первое поле
 //  QProcess().execute("/home/viktor/my_scripts_2/zvuk.sh");
 //i->label_2->settext(
   ui->label_2->setText ("textEdit заполнено");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// автоматически определяем новейший файл /
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   long long sekundi=0;
   QString noveyshiy_katalog;
   /// 
   struct stat fileInfo; 
   /// 
   QDirIterator it("/home/viktor/Изображения/edinitsi/Sgenerirovannye_fayly",
                   QDirIterator::NoIteratorFlags
                   //  QDirIterator::Subdirectories
                   );
   while (it.hasNext()) {
       QString dir = it.next();
       // qDebug()
       if (dir.toStdString()!="/home/viktor/Изображения/edinitsi/Sgenerirovannye_fayly/." &&
           dir.toStdString()!="/home/viktor/Изображения/edinitsi/Sgenerirovannye_fayly/..")
       {
           // std::cout     << dir.toStdString()<< endl;
           if (stat(dir.toStdString().c_str(), &fileInfo) != 0) {  // Use stat( ) to get the info
               std::cerr << "Error: " << strerror(errno) << '\n';
               //   return(EXIT_FAILURE);
           }
           //  std::cout <<  "Прошло секунд эпохи Unix до создания каталога     : " << fileInfo.st_ctime << endl;
           
           if (fileInfo.st_ctime >sekundi)
           {
               noveyshiy_katalog=dir.toStdString().c_str();
               sekundi=fileInfo.st_ctime ;
           }
       }
       
       
   }
   std::cout << "Новейший каталог: "<< noveyshiy_katalog.toStdString ()<<"; время создания: "<< sekundi<<endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
   
   
   
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::on_pushButton_2_clicked
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////// кнопка Записать в файл ///////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
void Dialog::on_pushButton_2_clicked() {
//    QPushButton *openFileNameButton =
//        new QPushButton(tr("QFileDialog::get&OpenFileName()"));
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
/// 
/// автоматически определяем новейший файл
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  
////// тут  QDateTime QFileInfo::birthTime() const
/// QFileInfo fi("/tmp/archive.tar.gz");
// QString name = fi.fileName(); 
//QFileDialog::ExistingFile
QFileDialog dialog(this);
dialog.setFileMode(QFileDialog::ExistingFile);
      Nazvaniye_fayla_s_neyronami_i_signalom = QFileDialog::getOpenFileName(this,
 tr("Open последний текущий файл с нейронами и сигналами txt"), "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly", tr("Txt Files (*.txt)"));
//dialog.
/// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  QFile file_n(

        Nazvaniye_fayla_s_neyronami_i_signalom.toStdString().c_str()
      // тут надо на уже сделанный прочитать
      
      //NOTE: файл neyroni.txt
      
      );
  // заряды нейронов
  if (!file_n.open(QIODevice::ReadOnly | QIODevice::Text))
    return;
  for (int var = 1; var < 202; ++var) { // 204
    ui->textEdit_2->append(
        file_n.readLine()
            .simplified()); // во второе текстовое поле вывели все нейроны
  }

  // теперь в конец первого текстового поля добавим из второго
  QString str = ui->textEdit_2->toPlainText();
  QStringList strList =
      str.split('\n'); // разбиваем строку из текстедита на отдельные строки

  for (int var = 100; var < 201; ++var) { // 202

    str = strList.at(var); // берем строку
    ui->textEdit->append(str);
    // ui->textEdit->append(file_n.readLine(var).simplified());
    //  file.readLine().simplified()
  }
  file_n.close();
  /// тут надо записать обновлённый файл neyroni.txt с сигналами-рисунком
  ///
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Nazvaniye_fayla_s_neyronami_i_signalom = QFileDialog::getOpenFileName(this,
 tr("Куда записать файл с нейронами и сигналами txt"), "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly", tr("Txt Files (*.txt)"));
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  
  QFile file3(

       Nazvaniye_fayla_s_neyronami_i_signalom.toStdString().c_str()
      // перезаписался /home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/0-2/neurons_and_signal.txt с сигналом 1-2
      // а надо выбрать куда его сохранить
      // перезаписать с новым сигналом
      //NOTE: файл neyroni_i_signal.txt
      
      ); // выходной файл
  if (!file3.open(QIODevice::WriteOnly | QIODevice::Text))
    return;
  QTextStream out3(&file3); //поток для записи текста
  out3 << ui->textEdit
              ->toPlainText(); // записали картинку в neyroni_i_signal.txt

  file3.close();
   QProcess().execute("/home/viktor/my_scripts_2/zvuk.sh");
}
