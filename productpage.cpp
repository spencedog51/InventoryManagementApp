#include "productpage.h"
#include "itemcard.h"

#include <QLabel>
#include <QGridLayout>
#include <QScrollArea>
#include <QVBoxLayout>


ProductPage::ProductPage(QWidget *parent)
    : QWidget{parent}
{
    //Holder for title, buttons, and product grid
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    //Title of page
    QLabel* pageTitle = new QLabel("Product Page", this);
    pageTitle->setStyleSheet("font-size: 32px; font-weight: bold; color: #e8e8e8;");
    pageTitle->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(pageTitle);

    //Product Grid
    QScrollArea* productGridScrollArea = new QScrollArea(this);
    productGridScrollArea->setWidgetResizable(true);
    QWidget* productContainer = new QWidget();
    QGridLayout* productGrid = new QGridLayout(productContainer);
    productGridScrollArea->setWidget(productContainer);

    mainLayout->addWidget(productGridScrollArea);

    ProductCard* prodCardTest = new ProductCard(QPixmap(), "product");
    MaterialCard* materCardTest = new MaterialCard(QPixmap(), "material");

    productGrid->addWidget(prodCardTest, 0, 0);
    productGrid->addWidget(materCardTest, 0, 1);
}
