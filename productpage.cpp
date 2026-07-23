#include "productpage.h"
#include "itemcard.h"

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
    productGrid = new QGridLayout(productContainer);
    productGridScrollArea->setWidget(productContainer);

    mainLayout->addWidget(productGridScrollArea);

    ProductCard* prodCardTest1 = new ProductCard(QPixmap(), "product1");
    ProductCard* prodCardTest2 = new ProductCard(QPixmap(), "product2");
    ProductCard* prodCardTest3 = new ProductCard(QPixmap(), "product3");
    ProductCard* prodCardTest4 = new ProductCard(QPixmap(), "product4");
    ProductCard* prodCardTest5 = new ProductCard(QPixmap(), "product5");
    ProductCard* prodCardTest6 = new ProductCard(QPixmap(), "product6");
    ProductCard* prodCardTest7 = new ProductCard(QPixmap(), "product7");
    ProductCard* prodCardTest8 = new ProductCard(QPixmap(), "product8");
    ProductCard* prodCardTest9 = new ProductCard(QPixmap(), "product9");

    AddNewProduct(prodCardTest1);
    AddNewProduct(prodCardTest2);
    AddNewProduct(prodCardTest3);
    AddNewProduct(prodCardTest4);
    AddNewProduct(prodCardTest5);
    AddNewProduct(prodCardTest6);
    AddNewProduct(prodCardTest7);
    AddNewProduct(prodCardTest8);
    AddNewProduct(prodCardTest9);

}

void ProductPage::PopulateProductGrid()
{
    const int columns = 4;

    for (int i = 0; i < productCards.size(); i++)
    {
        int row = i / columns;
        int col = i % columns;

        productGrid->addWidget(productCards[i], row, col);
    }
}

void ProductPage::AddNewProduct(ProductCard* newProduct)
{
    productCards.append(newProduct);
    PopulateProductGrid();

    connect(newProduct,
            &ItemCard::clicked,
            this,
            &ProductPage::openCard);
}

void ProductPage::openCard(ItemCard* card)
{
    qDebug() << "Clicked card: " << card;
    // QDialog dialog(this);

    // QVBoxLayout layout(&dialog);

    // QLabel label("Product details");
    // layout.addWidget(&label);

    // dialog.exec();
}
