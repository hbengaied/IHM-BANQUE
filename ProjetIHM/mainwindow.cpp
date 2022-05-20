#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->Retour_fenetre_principale->setHidden(true);

  std::vector<QString> tab_nom_employe_tout_agence{
      "Cristiano", "Messi",    "Hicheme", "Lucile", "Deschamps", "Wissem",
      "Nicolas",   "Segolene", "Eminem",  "Pascal", "Manuel",    "Michelle",
      "Francois",  "Emma",     "Florian", "Marco",  "Elias",     "Ymenne",
      "Eric",      "Charles",  "Karim",   "Lisa",   "Elisa"};
  tableau(tab_nom_employe_tout_agence);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::graph( int a,  int b,  int y, QChartView *nom_graphique,
                       QString premier, QString deuxieme, QString titre) {
  QBarSet *set0 = new QBarSet(premier);
  QBarSet *set1 = new QBarSet(deuxieme);

  *set0 << a << 0;
  *set1 << 0 << b;
  QBarSeries *series = new QBarSeries();
  series->append(set0);
  series->append(set1);
  QChart *chart = new QChart();
  chart->addSeries(series);
  chart->setTitle(titre);
  chart->setAnimationOptions(QChart::SeriesAnimations);
  QStringList categories;
  categories << premier << deuxieme;
  QBarCategoryAxis *axisX = new QBarCategoryAxis();
  axisX->append(categories);
  chart->addAxis(axisX, Qt::AlignBottom);
  series->attachAxis(axisX);

  QValueAxis *axisY = new QValueAxis();
  axisY->setRange(0, y);
  chart->addAxis(axisY, Qt::AlignLeft);
  series->attachAxis(axisY);
  chart->legend()->setVisible(true);
  chart->legend()->setAlignment(Qt::AlignBottom);
  QChartView *chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);
  // ui->graphicsView->setChart(chart);
  nom_graphique->setChart(chart);
}

void MainWindow::graph_une_bar( int a,  int y, QChartView *nom_graphique,
                               QString premier, QString titre) {
  QBarSet *set0 = new QBarSet(premier);
  *set0 << a;
  QBarSeries *series = new QBarSeries();
  series->append(set0);
  QChart *chart = new QChart();
  chart->addSeries(series);
  chart->setTitle(titre);
  chart->setAnimationOptions(QChart::SeriesAnimations);
  QStringList categories;
  categories << premier;
  QBarCategoryAxis *axisX = new QBarCategoryAxis();
  axisX->append(categories);
  chart->addAxis(axisX, Qt::AlignBottom);
  series->attachAxis(axisX);

  QValueAxis *axisY = new QValueAxis();
  axisY->setRange(0, y);
  chart->addAxis(axisY, Qt::AlignLeft);
  series->attachAxis(axisY);
  chart->legend()->setVisible(true);
  chart->legend()->setAlignment(Qt::AlignBottom);
  QChartView *chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);
  nom_graphique->setChart(chart);
}

 int MainWindow::randam_data( int borne_inf,  int borne_sup) {
   int nRand;
  nRand = borne_inf +
          ( int)(( int)rand() * (borne_sup - borne_inf + 1) / (RAND_MAX - 1));
  return nRand;
}

void MainWindow::tableau(std::vector<QString> tab) {
  int taille = std::size(tab);
  ui->tableWidget->setRowCount(taille+1);
  ui->tableWidget_2->setRowCount(taille+1);
  ui->tableWidget_3->setRowCount(taille+1);
  ui->tableWidget_4->setRowCount(taille+1);
  ui->tableWidget_5->setRowCount(taille+1);
  ui->tableWidget_6->setRowCount(taille+1);
  ui->tableWidget_7->setRowCount(taille);
  ui->tableWidget_8->setRowCount(taille);
  ui->tableWidget_10->setRowCount(taille+1);
  ui->tableWidget_12->setRowCount(taille+1);
  ui->tableWidget_13->setRowCount(taille+1);
  ui->tableWidget_14->setRowCount(taille+1);
  ui->tableWidget_15->setRowCount(taille+1);
  ui->tableWidget_16->setRowCount(taille+1);
  ui->tableWidget_17->setRowCount(taille);
  ui->tableWidget_18->setRowCount(taille);
  ui->tableWidget_19->setRowCount(taille+1);
  ui->tableWidget_20->setRowCount(taille+1);
  ui->tableWidget_21->setRowCount(taille);

  ui->tableWidget->setColumnCount(2);
  ui->tableWidget_2->setColumnCount(3);
  ui->tableWidget_3->setColumnCount(3);
  ui->tableWidget_4->setColumnCount(2);
  ui->tableWidget_5->setColumnCount(3);
  ui->tableWidget_6->setColumnCount(3);
  ui->tableWidget_7->setColumnCount(3);
  ui->tableWidget_8->setColumnCount(3);
  ui->tableWidget_10->setColumnCount(2);
  ui->tableWidget_12->setColumnCount(2);
  ui->tableWidget_13->setColumnCount(2);
  ui->tableWidget_14->setColumnCount(2);
  ui->tableWidget_15->setColumnCount(2);
  ui->tableWidget_16->setColumnCount(2);
  ui->tableWidget_17->setColumnCount(2);
  ui->tableWidget_18->setColumnCount(2);
  ui->tableWidget_19->setColumnCount(2);
  ui->tableWidget_20->setColumnCount(2);
  ui->tableWidget_21->setColumnCount(2);

  ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Volume"));
  ui->tableWidget->setHorizontalHeaderItem(0,
                                           new QTableWidgetItem("Banquiers"));

  ui->tableWidget_2->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Pret habitation"));
  ui->tableWidget_2->setHorizontalHeaderItem(2,
                                             new QTableWidgetItem("Pret auto"));
  ui->tableWidget_2->setHorizontalHeaderItem(0,
                                             new QTableWidgetItem("Banquiers"));

  ui->tableWidget_3->setHorizontalHeaderItem(0,
                                             new QTableWidgetItem("Banquiers"));
  ui->tableWidget_3->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Courant ouvert"));
  ui->tableWidget_3->setHorizontalHeaderItem(
      2, new QTableWidgetItem("Eparne ouvert"));

  ui->tableWidget_4->setHorizontalHeaderItem(0,
                                             new QTableWidgetItem("Banquiers"));
  ui->tableWidget_4->setHorizontalHeaderItem(1, new QTableWidgetItem("CA"));

  ui->tableWidget_5->setHorizontalHeaderItem(0,
                                             new QTableWidgetItem("Banquiers"));
  ui->tableWidget_5->setHorizontalHeaderItem(1,
                                             new QTableWidgetItem("Pret auto"));
  ui->tableWidget_5->setHorizontalHeaderItem(
      2, new QTableWidgetItem("Pret habitation"));

  ui->tableWidget_6->setHorizontalHeaderItem(0,
                                             new QTableWidgetItem("Banquiers"));
  ui->tableWidget_6->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Compte Courant"));
  ui->tableWidget_6->setHorizontalHeaderItem(
      2, new QTableWidgetItem("Compte Epargne"));

  ui->tableWidget_7->setHorizontalHeaderItem(0,
                                             new QTableWidgetItem("Banquiers"));
  ui->tableWidget_7->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Pret habitation %"));
  ui->tableWidget_7->setHorizontalHeaderItem(
      2, new QTableWidgetItem("Pret auto%"));

  ui->tableWidget_8->setHorizontalHeaderItem(0,
                                             new QTableWidgetItem("Banquiers"));
  ui->tableWidget_8->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Compte Courant %"));
  ui->tableWidget_8->setHorizontalHeaderItem(
      2, new QTableWidgetItem("Compte Epargne %"));

  ui->tableWidget_10->setHorizontalHeaderItem(
      0, new QTableWidgetItem("Banquiers"));
  ui->tableWidget_10->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Assurance vendu"));

  ui->tableWidget_12->setHorizontalHeaderItem(
      0, new QTableWidgetItem("Banquiers"));
  ui->tableWidget_12->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Assurance velo"));

  ui->tableWidget_13->setHorizontalHeaderItem(
      0, new QTableWidgetItem("Banquiers"));
  ui->tableWidget_13->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Assurance auto"));

  ui->tableWidget_14->setHorizontalHeaderItem(
      0, new QTableWidgetItem("Banquiers"));
  ui->tableWidget_14->setHorizontalHeaderItem(1, new QTableWidgetItem("CA"));

  ui->tableWidget_15->setHorizontalHeaderItem(
      0, new QTableWidgetItem("Banquiers"));
  ui->tableWidget_15->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Assurance velo"));

  ui->tableWidget_16->setHorizontalHeaderItem(
      0, new QTableWidgetItem("Banquiers"));
  ui->tableWidget_16->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Assurance auto"));

  ui->tableWidget_17->setHorizontalHeaderItem(
      0, new QTableWidgetItem("Banquiers"));
  ui->tableWidget_17->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Assurance velo %"));

  ui->tableWidget_18->setHorizontalHeaderItem(
      0, new QTableWidgetItem("Banquiers"));
  ui->tableWidget_18->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Assurance auto %"));

  ui->tableWidget_19->setHorizontalHeaderItem(
      0, new QTableWidgetItem("Banquiers"));
  ui->tableWidget_19->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Action vendu"));

  ui->tableWidget_20->setHorizontalHeaderItem(
      0, new QTableWidgetItem("Banquiers"));
  ui->tableWidget_20->setHorizontalHeaderItem(1, new QTableWidgetItem("CA "));

  ui->tableWidget_21->setHorizontalHeaderItem(
      0, new QTableWidgetItem("Banquiers"));
  ui->tableWidget_21->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Action vendu %"));

  ui->tableWidget_12->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_13->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_10->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_15->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_16->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_14->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_17->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_18->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_2->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_3->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_5->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_6->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_4->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_7->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_8->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_19->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_20->setItem(taille, 0, new QTableWidgetItem("Total :"));
  ui->tableWidget_21->setItem(taille, 0, new QTableWidgetItem("Total :"));

   int volume_bancaire = 0;
   int volume_pret_auto = 0;
   int volume_pret_habitation = 0;
   int volume_pret_auto_somme = 0;
   int volume_pret_habitation_somme = 0;
   int volume_courant = 0;
   int volume_epargne = 0;
   int volume_courant_somme = 0;
   int volume_epargne_somme = 0;

  std::vector< int> tableau_action;
  std::vector< int> tableau_velo;
  std::vector< int> tableau_auto;
  std::vector< int> tableau_pret_auto;
  std::vector< int> tableau_pret_habitation;
  std::vector< int> tableau_courant;
  std::vector< int> tableau_epargne;

   int ca_bancaire = 0;
   int ca_pret_auto = 0;
   int ca_pret_habitation = 0;
   int ca_pret_auto_somme = 0;
   int ca_pret_habitation_somme = 0;
   int ca_courant = 0;
   int ca_epargne = 0;
   int ca_courant_somme = 0;
   int ca_epargne_somme = 0;

   int volume_bourse = 0;
   int ca_bourse = 0;
   int volume_bourse_somme = 0;
   int ca_bourse_somme = 0;

   int volume_assurance = 0;
   int volume_velo = 0;
   int volume_auto = 0;
   int volume_velo_somme = 0;
   int volume_auto_somme = 0;
   int ca_assurance = 0;
   int ca_velo = 0;
   int ca_auto = 0;
   int ca_velo_somme = 0;
   int ca_auto_somme = 0;


  for (int i = 0; i < taille; i++) {

    // TABLEAU ASSURANCE

    volume_velo = randam_data(1, 20);
    tableau_velo.push_back( volume_velo);
    volume_velo_somme += volume_velo;
    ui->tableWidget_12->setItem(i, 0, new QTableWidgetItem(tab[i])); // velo
    ui->tableWidget_12->setItem(
        i, 1, new QTableWidgetItem(QString::number( volume_velo)));

    volume_auto = randam_data(1, 20);
    tableau_auto.push_back( volume_auto);
    volume_auto_somme += volume_auto;
    ui->tableWidget_13->setItem(i, 0, new QTableWidgetItem(tab[i]));
    ui->tableWidget_13->setItem(
        i, 1, new QTableWidgetItem(QString::number( volume_auto)));

    volume_assurance = volume_auto + volume_velo;
    ui->tableWidget_10->setItem(i, 0, new QTableWidgetItem(tab[i]));
    ui->tableWidget_10->setItem(
        i, 1, new QTableWidgetItem(QString::number( volume_assurance)));

    ca_velo = randam_data(1000, 5000);
    ca_velo_somme += ca_velo;
    ui->tableWidget_15->setItem(i, 0, new QTableWidgetItem(tab[i])); // Velo
    ui->tableWidget_15->setItem(
       i, 1, new QTableWidgetItem(QString::number( ca_velo)));

    ca_auto = randam_data(1000, 5000);
    ca_auto_somme += ca_auto;
    ui->tableWidget_16->setItem(i, 0, new QTableWidgetItem(tab[i]));
    ui->tableWidget_16->setItem(
        i, 1, new QTableWidgetItem(QString::number( ca_auto)));

    ca_assurance = ca_auto_somme + ca_velo_somme;
    ui->tableWidget_14->setItem(i, 0, new QTableWidgetItem(tab[i]));
    ui->tableWidget_14->setItem(
        i, 1, new QTableWidgetItem(QString::number( ca_assurance)));

    ui->tableWidget_17->setItem(i, 0, new QTableWidgetItem(tab[i]));

    ui->tableWidget_18->setItem(i, 0, new QTableWidgetItem(tab[i]));

    // TABLEAU BANCAIRE
    volume_pret_auto = randam_data(1, 20);
    tableau_pret_auto.push_back( volume_pret_auto);
    volume_pret_habitation = randam_data(1, 20);
    tableau_pret_habitation.push_back( volume_pret_habitation);
    volume_pret_auto_somme += volume_pret_auto;
    volume_pret_habitation_somme += volume_pret_habitation;

    ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(tab[i]));
    ui->tableWidget_2->setItem(
        i, 1,
        new QTableWidgetItem(QString::number( volume_pret_habitation)));
    ui->tableWidget_2->setItem(
        i, 2, new QTableWidgetItem(QString::number( volume_pret_auto)));

    volume_courant = randam_data(1, 20);
    tableau_courant.push_back( volume_courant);
    volume_epargne = randam_data(1, 20);
    tableau_epargne.push_back( volume_epargne);
    volume_courant_somme += volume_courant;
    volume_epargne_somme += volume_epargne;
    ui->tableWidget_3->setItem(i, 0, new QTableWidgetItem(tab[i]));
    ui->tableWidget_3->setItem(
        i, 1, new QTableWidgetItem(QString::number( volume_courant)));
    ui->tableWidget_3->setItem(
        i, 2, new QTableWidgetItem(QString::number( volume_epargne)));
    volume_bancaire = volume_pret_auto_somme + volume_pret_habitation_somme +
                      volume_courant_somme + volume_epargne_somme;

    ui->tableWidget->setItem(i, 0, new QTableWidgetItem(tab[i]));
    ui->tableWidget->setItem(
        i, 1, new QTableWidgetItem(QString::number( volume_bancaire)));

    ca_pret_auto = randam_data(2000, 50000);
    ca_pret_habitation = randam_data(2000, 50000);
    ca_pret_auto_somme += ca_pret_auto;
    ca_pret_habitation_somme += ca_pret_habitation;
    ui->tableWidget_5->setItem(i, 0, new QTableWidgetItem(tab[i]));
    ui->tableWidget_5->setItem(
        i, 1, new QTableWidgetItem(QString::number( ca_pret_auto)));
    ui->tableWidget_5->setItem(
        i, 2, new QTableWidgetItem(QString::number( ca_pret_habitation)));

    ca_courant = randam_data(2000, 50000);
    ca_epargne = randam_data(2000, 50000);
    ca_courant_somme += ca_courant;
    ca_epargne_somme += ca_epargne;
    ui->tableWidget_6->setItem(i, 0, new QTableWidgetItem(tab[i]));
    ui->tableWidget_6->setItem(
        i, 1, new QTableWidgetItem(QString::number( ca_courant)));
    ui->tableWidget_6->setItem(
        i, 2, new QTableWidgetItem(QString::number( ca_epargne)));

    ca_bancaire = ca_pret_auto_somme + ca_pret_habitation_somme +
                  ca_courant_somme + ca_epargne_somme;
    ui->tableWidget_4->setItem(i, 0, new QTableWidgetItem(tab[i]));
    ui->tableWidget_4->setItem(
        i, 1, new QTableWidgetItem(QString::number( ca_bancaire)));

    ui->tableWidget_7->setItem(i, 0, new QTableWidgetItem(tab[i]));

    ui->tableWidget_8->setItem(i, 0, new QTableWidgetItem(tab[i]));

    // TABLEAU BOURSE
    volume_bourse = randam_data(1, 50);
    tableau_action.push_back( volume_bourse);
    volume_bourse_somme = volume_bourse_somme + volume_bourse;
    ui->tableWidget_19->setItem(i, 0, new QTableWidgetItem(tab[i]));
    ui->tableWidget_19->setItem(
        i, 1, new QTableWidgetItem(QString::number( volume_bourse)));

    ca_bourse = randam_data(2000, 50000);
    ca_bourse_somme += ca_bourse;
    ui->tableWidget_20->setItem(i, 0, new QTableWidgetItem(tab[i]));
    ui->tableWidget_20->setItem(
        i, 1, new QTableWidgetItem(QString::number( ca_bourse)));

    ui->tableWidget_21->setItem(i, 0, new QTableWidgetItem(tab[i]));
  }

  // boucle pour pourcentage
  for (int i = 0; i < taille; i++) {
    ui->tableWidget_21->setItem(
        i, 1,
        new QTableWidgetItem(
            QString::number((tableau_action[i] * 100) / volume_bourse_somme)));

    ui->tableWidget_17->setItem(
        i, 1,
        new QTableWidgetItem(
            QString::number((tableau_velo[i] * 100) / volume_velo_somme)));

    ui->tableWidget_18->setItem(
        i, 1,
        new QTableWidgetItem(
            QString::number((tableau_auto[i] * 100) / volume_auto_somme)));

    ui->tableWidget_7->setItem(i, 1,
                               new QTableWidgetItem(QString::number(
                                   (tableau_pret_habitation[i] * 100) /
                                   volume_pret_habitation_somme)));

    ui->tableWidget_7->setItem(
        i, 2,
        new QTableWidgetItem(QString::number((tableau_pret_auto[i] * 100) /
                                             volume_pret_auto_somme)));

    ui->tableWidget_8->setItem(
        i, 1,
        new QTableWidgetItem(QString::number((tableau_courant[i] * 100) /
                                             volume_courant_somme)));

    ui->tableWidget_8->setItem(
        i, 2,
        new QTableWidgetItem(QString::number((tableau_epargne[i] * 100) /
                                             volume_epargne_somme)));
  }

  ui->tableWidget_12->setItem(
          taille, 1, new QTableWidgetItem(QString::number( volume_velo_somme)));

  ui->tableWidget_13->setItem(
          taille, 1, new QTableWidgetItem(QString::number( volume_auto_somme)));

  ui->tableWidget_10->setItem(
          taille, 1, new QTableWidgetItem(QString::number( volume_velo_somme + volume_auto_somme)));

  ui->tableWidget_15->setItem(
         taille, 1, new QTableWidgetItem(QString::number( ca_velo_somme)));

  ui->tableWidget_16->setItem(
          taille, 1, new QTableWidgetItem(QString::number( ca_auto_somme)));

  ui->tableWidget_14->setItem(
          taille, 1, new QTableWidgetItem(QString::number( ca_velo_somme +ca_auto_somme)));

  ui->tableWidget_2->setItem(
          taille, 2, new QTableWidgetItem(QString::number( volume_pret_auto_somme)));

  ui->tableWidget_2->setItem(
          taille, 1, new QTableWidgetItem(QString::number( volume_pret_habitation_somme)));

  ui->tableWidget_3->setItem(
          taille, 1, new QTableWidgetItem(QString::number( volume_courant_somme)));

  ui->tableWidget_3->setItem(
          taille, 2, new QTableWidgetItem(QString::number( volume_epargne_somme)));

  ui->tableWidget->setItem(
          taille, 1, new QTableWidgetItem(QString::number( volume_courant_somme +
                                                           volume_epargne_somme
                                                           + volume_pret_auto_somme
                                                           +volume_pret_habitation_somme)));

  ui->tableWidget_5->setItem(
          taille, 2, new QTableWidgetItem(QString::number( ca_pret_habitation_somme)));
  ui->tableWidget_5->setItem(
          taille, 1, new QTableWidgetItem(QString::number( ca_pret_auto_somme)));

  ui->tableWidget_6->setItem(
          taille, 1, new QTableWidgetItem(QString::number( ca_courant_somme)));

  ui->tableWidget_6->setItem(
          taille, 2, new QTableWidgetItem(QString::number( ca_epargne_somme)));

  ui->tableWidget_4->setItem(
          taille, 1, new QTableWidgetItem(QString::number(ca_courant_somme +ca_epargne_somme )));

  ui->tableWidget_19->setItem(
          taille, 1, new QTableWidgetItem(QString::number( volume_bourse_somme)));

  ui->tableWidget_20->setItem(
          taille, 1, new QTableWidgetItem(QString::number( ca_bourse_somme)));

  // GRAPHIQUE BOURSE
  graph_une_bar( volume_bourse_somme,
                volume_bourse_somme + ( volume_bourse_somme  ),
                ui->graphicsView_3, "Action", "Produits boursiers");
  graph_une_bar( volume_bourse_somme,
                volume_bourse_somme + ( volume_bourse_somme  ),
                ui->graphicsView_22, "Action", "Volume Produits boursiers");
  graph_une_bar( ca_bourse_somme,
                ca_bourse_somme + ( ca_bourse_somme  ),
                ui->graphicsView_23, "Action", "CA Produits boursiers");
  graph_une_bar(100, 100, ui->graphicsView_24, "Action",
                "Pourcentage Produits boursiers");

  // Graph produits bancaire
   int volume_compte = volume_epargne_somme + volume_courant_somme;
   int volume_pret = volume_pret_auto_somme + volume_pret_habitation_somme;

   int ca_pret = ca_pret_auto_somme + ca_pret_habitation_somme;
   int ca_compte = ca_courant_somme + ca_epargne_somme;

   int pourcentage_pret =
      (( volume_pret_auto_somme + volume_pret_habitation_somme) * 100) /
      ( volume_pret_auto_somme + volume_pret_habitation_somme +
       volume_courant_somme + volume_epargne_somme);

   int pourcentage_compte =
      (( volume_courant_somme + volume_epargne_somme) * 100) /
      ( volume_pret_auto_somme + volume_pret_habitation_somme +
       volume_courant_somme + volume_epargne_somme);

   int pourcentage_pret_habitation =
      ( volume_pret_habitation_somme * 100) /
      ( volume_pret_habitation_somme + volume_pret_auto_somme);

   int pourcentage_pret_auto =
      ( volume_pret_auto_somme * 100) /
      ( volume_pret_habitation_somme + volume_pret_auto_somme);

   int pourcentage_courant =
      ( volume_courant_somme * 100) /
      ( volume_courant_somme + volume_epargne_somme);

   int pourcentage_epargne =
      ( volume_epargne_somme * 100) /
      ( volume_courant_somme + volume_epargne_somme);

  graph( volume_pret,  volume_compte,
         volume_compte +  (volume_compte), ui->graphicsView, "Pret",
        "Compte", "Produits Bancaires");
  graph( volume_pret,  volume_compte,
         volume_compte +  (volume_compte  ), ui->graphicsView_4, "Pret",
        "Compte", "Volume Produits Bancaires");
  graph( volume_courant_somme,  volume_epargne_somme,  volume_compte,
        ui->graphicsView_6, "Compte Courant", "Compte Epargne",
        "Volume Produits Bancaires Compte");
  graph( volume_pret_habitation_somme,  volume_pret_auto_somme,  volume_pret,
        ui->graphicsView_5, "Pret habitation", "Pret auto",
        "Volume Produits Bancaires Pret");
  graph( ca_pret,  ca_compte, ca_pret +  ca_compte, ui->graphicsView_7,
        "Pret", "Compte", "CA Produits Bancaires");
  graph( ca_pret_habitation_somme,  ca_pret_auto_somme,  ca_pret,
        ui->graphicsView_8, "Pret habitation", "Pret auto",
        " CA Produits Bancaires Pret");
  graph( ca_courant_somme,  ca_epargne_somme,  ca_compte, ui->graphicsView_9,
        "Compte Courant", "Compte Epargne", "CA Produits Bancaires Compte");

  graph(pourcentage_pret, pourcentage_compte, 100, ui->graphicsView_10, "Pret",
        "Compte", "Pourcentage Produits Bancaires");
  graph(pourcentage_pret_habitation, pourcentage_pret_auto, 100,
        ui->graphicsView_11, "Pret habitation", "Pret auto",
        "Pourcentage Produits Bancaires Pret");
  graph(pourcentage_courant, pourcentage_epargne, 100, ui->graphicsView_12,
        "Compte Courant", "Compte Epargne",
        "Pourcentage Produits Bancaires Compte");

  // Graph produits assurance

   int pourcent_de_velo = ( volume_velo_somme * 100) /
                           ( volume_velo_somme + volume_auto_somme);

   int pourcent_de_auto = ( volume_auto_somme * 100) /
                           ( volume_velo_somme + volume_auto_somme);

  graph( volume_velo_somme,  volume_auto_somme,
         (volume_velo_somme +(volume_auto_somme)), ui->graphicsView_2,
        "Velo", "Auto", "Produits d'assurances");
  graph( volume_velo_somme,  volume_auto_somme,
         (volume_velo_somme+volume_auto_somme), ui->graphicsView_13,
        "Velo", "Auto", "Volume Produits d'assurance");
  graph_une_bar(
       volume_velo_somme,  volume_velo_somme +  (volume_velo_somme  ),
      ui->graphicsView_14, "Velo", "Volume Produits d'assurance velo");
  graph_une_bar(
       volume_auto_somme,  volume_auto_somme +  (volume_auto_somme  ),
      ui->graphicsView_15, "Auto", "Volume Produits d'assurance auto");
  graph( ca_velo_somme,  ca_auto_somme,
         ca_velo_somme +  (ca_auto_somme  ), ui->graphicsView_16, "Velo",
        "Auto", "CA Produits d'assurance");
  graph_une_bar( ca_velo_somme,  ca_velo_somme +  (ca_velo_somme  ),
                ui->graphicsView_17, "Velo", "CA Produits d'assurance velo");
  graph_une_bar( ca_auto_somme,  ca_auto_somme +  (ca_auto_somme  ),
                ui->graphicsView_18, "Auto", "CA Produits d'assurance auto");
  graph(pourcent_de_velo, pourcent_de_auto, 100, ui->graphicsView_19, "velo",
        "Auto", "Pourcentage Produits d'assurance ");
  graph_une_bar(pourcent_de_velo, 100, ui->graphicsView_20, "Velo",
                "Pourcentage Produits d'assurance velo");
  graph_une_bar(pourcent_de_auto, 100, ui->graphicsView_21, "Auto",
                "Pourcentage Produits d'assurance auto");
}

void MainWindow::on_btn_volume_pb_2_clicked() {
  ui->stackedWidget->setCurrentIndex(1);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_fermer_volume_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_ouvrir_pb_pret_clicked() {
  ui->stackedWidget->setCurrentIndex(2);
  ui->Retour_fenetre_principale->setHidden(false);
}

void MainWindow::on_ouvrir_pb_compte_clicked() {
  ui->stackedWidget->setCurrentIndex(3);
  ui->Retour_fenetre_principale->setHidden(false);
}

void MainWindow::on_btn_fermer_volume_pb_pret_clicked() {
  ui->stackedWidget->setCurrentIndex(1);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_btn_retour_volume_pb_2_clicked() {
  ui->stackedWidget->setCurrentIndex(1);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_btn_ca_pb_2_clicked() {
  ui->stackedWidget->setCurrentIndex(4);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_fermer_ca_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_ouvrir_pb_pret_ca_clicked() {
  ui->stackedWidget->setCurrentIndex(5);
  ui->Retour_fenetre_principale->setHidden(false);
}

void MainWindow::on_btn_fermer_ca_pret_clicked() {
  ui->stackedWidget->setCurrentIndex(4);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_btn_fermer_ca_compte_clicked() {
  ui->stackedWidget->setCurrentIndex(4);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_ouvrir_pb_compte_ca_clicked() {
  ui->stackedWidget->setCurrentIndex(6);
  ui->Retour_fenetre_principale->setHidden(false);
}

void MainWindow::on_btn_pourcentage_pb_2_clicked() {
  ui->stackedWidget->setCurrentIndex(7);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_pushButton_2_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_ouvrir_pb_pret_poucentage_clicked() {
  ui->stackedWidget->setCurrentIndex(8);
  ui->Retour_fenetre_principale->setHidden(false);
}

void MainWindow::on_fermer_pourcentage_pb_compte_clicked() {
  ui->stackedWidget->setCurrentIndex(7);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_fermer_pourcentage_pb_pret_clicked() {
  ui->stackedWidget->setCurrentIndex(7);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_ouvrir_pb_compte_pourcentage_clicked() {
  ui->stackedWidget->setCurrentIndex(9);
  ui->Retour_fenetre_principale->setHidden(false);
}

void MainWindow::on_pushButton_3_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_btn_volume_pa_2_clicked() {
  ui->stackedWidget->setCurrentIndex(10);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_femer_volume_pa_velo_clicked() {
  ui->stackedWidget->setCurrentIndex(10);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_ouvrir_pa_velo_clicked() {
  ui->stackedWidget->setCurrentIndex(11);
  ui->Retour_fenetre_principale->setHidden(false);
}

void MainWindow::on_ouvrir_pa_auto_clicked() {
  ui->stackedWidget->setCurrentIndex(12);
  ui->Retour_fenetre_principale->setHidden(false);
}

void MainWindow::on_btn_ca_pa_2_clicked() {
  ui->stackedWidget->setCurrentIndex(13);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_ouvrir_pa_assurance_velo_ca_2_clicked() {
  ui->stackedWidget->setCurrentIndex(14);
  ui->Retour_fenetre_principale->setHidden(false);
}

void MainWindow::on_ouvrir_pa_assurance_auto_ca_clicked() {
  ui->stackedWidget->setCurrentIndex(15);
  ui->Retour_fenetre_principale->setHidden(false);
}

void MainWindow::on_Fermer_ca_pa_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_Fermer_ca_velo_pa_clicked() {
  ui->stackedWidget->setCurrentIndex(13);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_Fermer_ca_pa_auto_clicked() {
  ui->stackedWidget->setCurrentIndex(13);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_fermer_pourcentage_pa_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_ouvrir_pa_pourcentage_auto_clicked() {
  ui->stackedWidget->setCurrentIndex(17);
  ui->Retour_fenetre_principale->setHidden(false);
}

void MainWindow::on_ouvrir_pb_compte_pourcentage_2_clicked() {
  ui->stackedWidget->setCurrentIndex(18);
  ui->Retour_fenetre_principale->setHidden(false);
}

void MainWindow::on_fermer_pa_pourcentage_velo_clicked() {
  ui->stackedWidget->setCurrentIndex(16);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_pushButton_7fermer_pa_pourcentage_auto_clicked() {
  ui->stackedWidget->setCurrentIndex(16);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_btn_pourcentage_pa_2_clicked() {
  ui->stackedWidget->setCurrentIndex(16);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_fermer_pa_volume_auto_clicked() {
  ui->stackedWidget->setCurrentIndex(10);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_Fermer_volume_bourse_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_btn_volume_pbourse_2_clicked() {
  ui->stackedWidget->setCurrentIndex(19);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_Fermer_ca_pbourse_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_btn_ca_pbourse_2_clicked() {
  ui->stackedWidget->setCurrentIndex(20);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_fermer_pbourse_pourcent_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_btn_pourcentage_pbourse_2_clicked() {
  ui->stackedWidget->setCurrentIndex(21);
  ui->Retour_fenetre_principale->setHidden(true);
}

void MainWindow::on_comboBox_liste_agence_3_activated(const QString &arg1) {
  std::vector<QString> tab_nom_employe_stras{"Hicheme", "Lucile", "Deschamps"};
  std::vector<QString> tab_nom_employe_bordeaux{
      "Wissem", "Nicolas", "Segolene", "Eminem",
      "Pascal", "Manuel",  "Michelle"};
  std::vector<QString> tab_nom_employe_marseille{
      "Francois", "Emma", "Florian", "Marco", "Elias", "Ymenne", "Eric"};
  std::vector<QString> tab_nom_employe_paris{"Charles", "Karim", "Lisa",
                                             "Elisa"};
  std::vector<QString> tab_nom_employe_metz{"Cristiano", "Messi"};
  std::vector<QString> tab_nom_employe_tout_agence{
      "Cristiano", "Messi",    "Hicheme", "Lucile", "Deschamps", "Wissem",
      "Nicolas",   "Segolene", "Eminem",  "Pascal", "Manuel",    "Michelle",
      "Francois",  "Emma",     "Florian", "Marco",  "Elias",     "Ymenne",
      "Eric",      "Charles",  "Karim",   "Lisa",   "Elisa"};

  if (ui->comboBox_liste_agence_2->currentText() == "Toutes agences")
    tableau(tab_nom_employe_tout_agence);

  if (ui->comboBox_liste_agence_2->currentText() == "Strasbourg")
    tableau(tab_nom_employe_stras);

  if (ui->comboBox_liste_agence_2->currentText() == "Paris")
    tableau(tab_nom_employe_paris);

  if (ui->comboBox_liste_agence_2->currentText() == "Metz")
    tableau(tab_nom_employe_metz);

  if (ui->comboBox_liste_agence_2->currentText() == "Bordeaux")
    tableau(tab_nom_employe_bordeaux);

  if (ui->comboBox_liste_agence_2->currentText() == "Marseille")
    tableau(tab_nom_employe_marseille);
}

void MainWindow::on_comboBox_liste_agence_2_activated(const QString &arg1) {
  std::vector<QString> tab_nom_employe_stras{"Hicheme", "Lucile", "Deschamps"};
  std::vector<QString> tab_nom_employe_bordeaux{
      "Wissem", "Nicolas", "Segolene", "Eminem",
      "Pascal", "Manuel",  "Michelle"};
  std::vector<QString> tab_nom_employe_marseille{
      "Francois", "Emma", "Florian", "Marco", "Elias", "Ymenne", "Eric"};
  std::vector<QString> tab_nom_employe_paris{"Charles", "Karim", "Lisa",
                                             "Elisa"};
  std::vector<QString> tab_nom_employe_metz{"Cristiano", "Messi"};
  std::vector<QString> tab_nom_employe_tout_agence{
      "Cristiano", "Messi",    "Hicheme", "Lucile", "Deschamps", "Wissem",
      "Nicolas",   "Segolene", "Eminem",  "Pascal", "Manuel",    "Michelle",
      "Francois",  "Emma",     "Florian", "Marco",  "Elias",     "Ymenne",
      "Eric",      "Charles",  "Karim",   "Lisa",   "Elisa"};

  if (arg1 == "Toutes agences")
    tableau(tab_nom_employe_tout_agence);

  if (arg1 == "Strasbourg")
    tableau(tab_nom_employe_stras);

  if (arg1 == "Paris")
    tableau(tab_nom_employe_paris);

  if (arg1 == "Metz")
    tableau(tab_nom_employe_metz);

  if (arg1 == "Bordeaux")
    tableau(tab_nom_employe_bordeaux);

  if (arg1 == "Marseille")
    tableau(tab_nom_employe_marseille);
}

void MainWindow::on_btn_mode_nuit_clicked() {

  if (ui->btn_mode_nuit->text() == "Mode nuit") {
    ui->centralwidget->setStyleSheet("background-color: black");
    ui->label_4->setStyleSheet("color: white;");
    ui->label_5->setStyleSheet("color: white;");
    ui->label_6->setStyleSheet("color: white;");
    ui->btn_mode_nuit->setText("Mode jour");
    ui->line->setStyleSheet("border :1px solid white;");
    ui->line_2->setStyleSheet("border :1px solid white;");
    ui->line_3->setStyleSheet("border :1px solid white;");
    ui->line_4->setStyleSheet("border :1px solid white;");
    ui->btn_mode_nuit->setStyleSheet(
        "background-color : rgb(5, 188, 255); font: 10pt;");
    ui->btn_ca_pa_2->setStyleSheet("background-color : white; font: 10pt;");
    ui->btn_ca_pb_2->setStyleSheet("background-color : white; font: 10pt;");
    ui->btn_ca_pbourse_2->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->btn_fermer_ca_compte->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->btn_fermer_ca_pret->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->btn_fermer_volume_pb_pret->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->btn_pourcentage_pa_2->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->btn_pourcentage_pb_2->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->btn_pourcentage_pbourse_2->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->btn_retour_volume_pb_2->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->btn_volume_pa_2->setStyleSheet("background-color : white; font: 10pt;");
    ui->btn_volume_pb_2->setStyleSheet("background-color : white; font: 10pt;");
    ui->btn_volume_pbourse_2->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->ouvrir_pa_assurance_auto_ca->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->ouvrir_pa_assurance_velo_ca_2->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->ouvrir_pa_auto->setStyleSheet("background-color : white; font: 10pt;");
    ui->ouvrir_pa_pourcentage_auto->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->ouvrir_pa_velo->setStyleSheet("background-color : white; font: 10pt;");
    ui->ouvrir_pb_compte->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->ouvrir_pb_compte_ca->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->ouvrir_pb_compte_pourcentage->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->ouvrir_pb_compte_pourcentage_2->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->ouvrir_pb_pret->setStyleSheet("background-color : white; font: 10pt;");
    ui->ouvrir_pb_pret_ca->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->ouvrir_pb_pret_poucentage->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->fermer_ca->setStyleSheet("background-color : white; font: 10pt;");
    ui->fermer_pa_pourcentage_velo->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->fermer_pa_volume_auto->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->fermer_pbourse_pourcent->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->fermer_pourcentage_pa->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->fermer_pourcentage_pb_compte->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->fermer_pourcentage_pb_pret->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->fermer_volume->setStyleSheet("background-color : white; font: 10pt;");
    ui->Fermer_ca_pa->setStyleSheet("background-color : white; font: 10pt;");
    ui->Fermer_ca_pa_auto->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->Fermer_ca_pbourse->setStyleSheet(
        "background-color : white; font: 10pt;e");
    ui->Fermer_ca_velo_pa->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->Fermer_volume_bourse->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->pushButton_2->setStyleSheet("background-color : white; font: 10pt;");
    ui->pushButton_3->setStyleSheet("background-color : white; font: 10pt;");
    ui->femer_volume_pa_velo->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->pushButton_7fermer_pa_pourcentage_auto->setStyleSheet(
        "background-color : white; font: 10pt;");
    ui->Quitter->setStyleSheet("background-color : white; font: 10pt;");
    ui->Retour_fenetre_principale->setStyleSheet(
        "background-color : white; font: 10pt;");

  } else {
    ui->centralwidget->setStyleSheet("background-color: white");
    ui->label_4->setStyleSheet("color: black;");
    ui->label_5->setStyleSheet("color: black;");
    ui->label_6->setStyleSheet("color: black;");
    ui->line->setStyleSheet("border :1px solid black;");
    ui->line_2->setStyleSheet("border :1px solid black;");
    ui->line_3->setStyleSheet("border :1px solid black;");
    ui->line_4->setStyleSheet("border :1px solid black;");
    ui->btn_mode_nuit->setText("Mode nuit");
    ui->btn_mode_nuit->setStyleSheet(
        "background-color : rgb(5, 188, 255); font: 10pt;");
    ui->btn_ca_pa_2->setStyleSheet("background-color : rgb(209, 209, 209); font: 10pt;");
    ui->btn_ca_pb_2->setStyleSheet("background-color : rgb(209, 209, 209); font: 10pt;");
    ui->btn_ca_pbourse_2->setStyleSheet("background-color : rgb(209, 209, 209); font: 10pt;");
    ;
    ui->btn_fermer_ca_compte->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->btn_fermer_ca_pret->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->btn_fermer_volume_pb_pret->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->btn_pourcentage_pa_2->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->btn_pourcentage_pb_2->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->btn_pourcentage_pbourse_2->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->btn_retour_volume_pb_2->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->btn_volume_pa_2->setStyleSheet("background-color : rgb(209, 209, 209); font: 10pt;");
    ui->btn_volume_pb_2->setStyleSheet("background-color : rgb(209, 209, 209); font: 10pt;");
    ui->btn_volume_pbourse_2->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->ouvrir_pa_assurance_auto_ca->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->ouvrir_pa_assurance_velo_ca_2->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->ouvrir_pa_auto->setStyleSheet("background-color : rgb(209, 209, 209); font: 10pt;");
    ui->ouvrir_pa_pourcentage_auto->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->ouvrir_pa_velo->setStyleSheet("background-color : rgb(209, 209, 209); font: 10pt;");
    ui->ouvrir_pb_compte->setStyleSheet("background-color : rgb(209, 209, 209); font: 10pt;");
    ui->ouvrir_pb_compte_ca->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->ouvrir_pb_compte_pourcentage->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->ouvrir_pb_compte_pourcentage_2->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->ouvrir_pb_pret->setStyleSheet("background-color : rgb(209, 209, 209); font: 10pt;");
    ui->ouvrir_pb_pret_ca->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->ouvrir_pb_pret_poucentage->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->fermer_ca->setStyleSheet("background-color : rgb(209, 209, 209); font: 10pt;");
    ui->fermer_pa_pourcentage_velo->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->fermer_pa_volume_auto->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->fermer_pbourse_pourcent->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->fermer_pourcentage_pa->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->fermer_pourcentage_pb_compte->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->fermer_pourcentage_pb_pret->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->fermer_volume->setStyleSheet("background-color : rgb(209, 209, 209); font: 10pt;");
    ui->Fermer_ca_pa->setStyleSheet("background-color : rgb(209, 209, 209); font: 10pt;");
    ui->Fermer_ca_pa_auto->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->Fermer_ca_pbourse->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->Fermer_ca_velo_pa->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->Fermer_volume_bourse->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->pushButton_2->setStyleSheet("background-color : rgb(209, 209, 209); font: 10pt;");
    ui->pushButton_3->setStyleSheet("background-color : rgb(209, 209, 209); font: 10pt;");
    ui->femer_volume_pa_velo->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->pushButton_7fermer_pa_pourcentage_auto->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->Quitter->setStyleSheet("background-color : rgb(209, 209, 209); font: 10pt;");
    ui->Retour_fenetre_principale->setStyleSheet(
        "background-color : rgb(209, 209, 209); font: 10pt;");
    ui->graphicsView->setStyleSheet("border :1px solid black;");
    ui->graphicsView_2->setStyleSheet("border :1px solid black;");
    ui->graphicsView_3->setStyleSheet("border :1px solid black;");
    ui->graphicsView_4->setStyleSheet("border :1px solid black;");
    ui->graphicsView_5->setStyleSheet("border :1px solid black;");
    ui->graphicsView_6->setStyleSheet("border :1px solid black;");
    ui->graphicsView_7->setStyleSheet("border :1px solid black;");
    ui->graphicsView_8->setStyleSheet("border :1px solid black;");
    ui->graphicsView_9->setStyleSheet("border :1px solid black;");
    ui->graphicsView_10->setStyleSheet("border :1px solid black;");
    ui->graphicsView_11->setStyleSheet("border :1px solid black;");
    ui->graphicsView_12->setStyleSheet("border :1px solid black;");
    ui->graphicsView_13->setStyleSheet("border :1px solid black;");
    ui->graphicsView_14->setStyleSheet("border :1px solid black;");
    ui->graphicsView_15->setStyleSheet("border :1px solid black;");
    ui->graphicsView_16->setStyleSheet("border :1px solid black;");
    ui->graphicsView_17->setStyleSheet("border :1px solid black;");
    ui->graphicsView_18->setStyleSheet("border :1px solid black;");
    ui->graphicsView_19->setStyleSheet("border :1px solid black;");
    ui->graphicsView_20->setStyleSheet("border :1px solid black;");
    ui->graphicsView_21->setStyleSheet("border :1px solid black;");
    ui->graphicsView_22->setStyleSheet("border :1px solid black;");
    ui->graphicsView_23->setStyleSheet("border :1px solid black;");
    ui->graphicsView_24->setStyleSheet("border :1px solid black;");
  }
}

void MainWindow::on_actionImprimer_triggered() {
  QPrinter printer;
  printer.setPrinterName("Imprimer");
  QPrintDialog dialog(&printer, this);
  if (dialog.exec() == QDialog::Rejected)
    return;
}

void MainWindow::on_Retour_fenetre_principale_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
  ui->Retour_fenetre_principale->setHidden(true);
}
