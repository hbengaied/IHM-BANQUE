#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAreaSeries>
#include <QBarCategoryAxis>
#include <QBarSeries>
#include <QBarSet>
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QMainWindow>
#include <QPrintDialog>
#include <QPrinter>
#include <QScrollBar>
#include <QString>
#include <QValueAxis>
#include <QtCharts>
#include <string>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void graph( int a,  int b,  int y, QChartView *nom_graphique,
             QString premier, QString deuxieme, QString titre);

  void graph_une_bar( int a,  int y, QChartView *nom_graphique,
                     QString premier, QString titre);

  void on_btn_volume_pb_2_clicked();

  void on_fermer_volume_clicked();

  void on_ouvrir_pb_pret_clicked();

  void on_ouvrir_pb_compte_clicked();

  void on_btn_fermer_volume_pb_pret_clicked();

  void on_btn_retour_volume_pb_2_clicked();

  void on_btn_ca_pb_2_clicked();

  void on_fermer_ca_clicked();

  void on_ouvrir_pb_pret_ca_clicked();

  void on_btn_fermer_ca_pret_clicked();

  void on_btn_fermer_ca_compte_clicked();

  void on_ouvrir_pb_compte_ca_clicked();

  void on_btn_pourcentage_pb_2_clicked();

   int randam_data( int borne_inf,  int borne_sup);

  void tableau(std::vector<QString> tab);

  void on_pushButton_2_clicked();

  void on_ouvrir_pb_pret_poucentage_clicked();

  void on_fermer_pourcentage_pb_compte_clicked();

  void on_fermer_pourcentage_pb_pret_clicked();

  void on_ouvrir_pb_compte_pourcentage_clicked();

  void on_pushButton_3_clicked();

  void on_btn_volume_pa_2_clicked();

  void on_femer_volume_pa_velo_clicked();

  void on_ouvrir_pa_velo_clicked();

  void on_ouvrir_pa_auto_clicked();

  void on_btn_ca_pa_2_clicked();

  void on_ouvrir_pa_assurance_velo_ca_2_clicked();

  void on_ouvrir_pa_assurance_auto_ca_clicked();

  void on_Fermer_ca_pa_clicked();

  void on_Fermer_ca_velo_pa_clicked();

  void on_Fermer_ca_pa_auto_clicked();

  void on_fermer_pourcentage_pa_clicked();

  void on_ouvrir_pa_pourcentage_auto_clicked();

  void on_ouvrir_pb_compte_pourcentage_2_clicked();

  void on_fermer_pa_pourcentage_velo_clicked();

  void on_pushButton_7fermer_pa_pourcentage_auto_clicked();

  void on_btn_pourcentage_pa_2_clicked();

  void on_fermer_pa_volume_auto_clicked();

  void on_Fermer_volume_bourse_clicked();

  void on_btn_volume_pbourse_2_clicked();

  void on_Fermer_ca_pbourse_clicked();

  void on_btn_ca_pbourse_2_clicked();

  void on_fermer_pbourse_pourcent_clicked();

  void on_btn_pourcentage_pbourse_2_clicked();

  void on_comboBox_liste_agence_3_activated(const QString &arg1);

  void on_comboBox_liste_agence_2_activated(const QString &arg1);

  void on_btn_mode_nuit_clicked();

  void on_actionImprimer_triggered();

  void on_Retour_fenetre_principale_clicked();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
