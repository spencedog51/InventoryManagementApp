#include "productpage.h"
#include "itemcard.h"

#include <QDialog>
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

    ProductCard* prodCardTest1 = new ProductCard(QPixmap(), "Silver Star Stud Earrings", "earrings", 0.1, "SSS-E1", 0, "debut", 5,
                                                {{"flat pad earring post", 1}, {"6 mm silver star bead", 1}, {"E6000 glue", 0.1}});
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

    connect(newProduct,
            &ItemCard::clicked,
            this,
            &ProductPage::openProduct);

    PopulateProductGrid();

}

void ProductPage::openProduct(ItemCard* product)
{
    ProductCard* productCard = dynamic_cast<ProductCard*>(product);
    if (!productCard) {
        qDebug() << product->name << "Is Not a ProductCard!";
        return;
    }
    qDebug() << "Clicked card: " << product->name;
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("test title");
    dialog->resize(1200, 800);

    QVBoxLayout *layout = new QVBoxLayout(dialog);

    // Image placeholder
    QLabel *productImage = new QLabel(dialog);
    productImage->setFixedSize(200, 200);
    productImage->setAlignment(Qt::AlignCenter);
    productImage->setStyleSheet("border: 1px gray; color: gray;");

    if (productCard->image.isNull()) {
        productImage->setText("No image yet");
    } else {
        productImage->setPixmap(productCard->image.scaled(
            productImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    QLabel *productName = new QLabel(productCard->name);
    QLabel *productType = new QLabel(productCard->type);
    QLabel *productWeight = new QLabel(QString::number(productCard->weight) + " oz");
    QLabel *productSku = new QLabel(productCard->personalSku);
    QLabel *productPrice = new QLabel("$" + QString::number(productCard->price));
    QLabel *productCollection = new QLabel(productCard->productCollection);

    //Formatting time to mm:ss
    int totalSeconds = qRound(productCard->timeToMake * 60);
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    QString formattedTime = QString("%1:%2")
                            .arg(minutes, 2, 10, QChar('0'))
                            .arg(seconds, 2, 10, QChar('0'));

    QLabel *productTimeToMake = new QLabel(formattedTime);

    //List of materials used
    QStringList materialLines;
    const auto &materials = productCard->materialsUsed;
    for (const auto &[materialName, quantity] : materials) {
        materialLines << materialName + ": " + QString::number(quantity);
    }
    QLabel *productMaterialsLabel = new QLabel("Materials Used:\n" + materialLines.join("\n"));


    layout->addWidget(productImage);
    layout->addWidget(productName);
    layout->addWidget(productType);
    layout->addWidget(productWeight);
    layout->addWidget(productSku);
    layout->addWidget(productPrice);
    layout->addWidget(productCollection);
    layout->addWidget(productTimeToMake);
    layout->addWidget(productMaterialsLabel);

    dialog->exec();
}
