#include "itemcard.h"

#include <QVBoxLayout>

ItemCard::ItemCard(
    const QPixmap& image,
    const QString& name,
    const QString& type,
    double weight,
    const QString& personalSku,
    double price,
    QFrame* parent)
    : QFrame(parent),
    image(image),
    name(name),
    type(type),
    weight(weight),
    personalSku(personalSku),
    price(price)
{
    setObjectName("ItemCard");
    QVBoxLayout* layout = new QVBoxLayout(this);

    setFixedSize(250, 300);
    setStyleSheet(
        "#ItemCard {"
        "border: 2px solid gray;"
        "border-radius: 10px;"
        "background-color: white;"
        "}"
        "#ItemCard QLabel {"
        "color: black;"
        "background: transparent;"
        "}"
    );

    setFrameShape(QFrame::StyledPanel);
    setFrameShadow(QFrame::Raised);
    nameLabel = new QLabel(this);
    layout->addWidget(nameLabel);
}

ProductCard::ProductCard(
    const QPixmap& image,
    const QString& name,
    const QString& type,
    double weight,
    const QString& personalSku,
    double price,
    const QString& productCollection,
    double timeToMake,
    const QList<std::pair<QString, double>>& materialsUsed,
    QFrame* parent)
    : ItemCard(image, name, type, weight, personalSku, price, parent),
    productCollection(productCollection),
    timeToMake(timeToMake),
    materialsUsed(materialsUsed)
{
    nameLabel->setText(name);
}

MaterialCard::MaterialCard(
    const QPixmap& image,
    const QString& name,
    const QString& type,
    double weight,
    const QString& personalSku,
    double price,
    const QString& webLink,
    const QString& webSku,
    double quantity,
    QFrame* parent)
    : ItemCard(image, name, type, weight, personalSku, price, parent),
    websiteLink(webLink),
    websiteSku(webSku),
    quantity(quantity)
{
    nameLabel->setText(name);
}

void ItemCard::mousePressEvent(QMouseEvent *event)
{
    emit clicked(this);

    QFrame::mousePressEvent(event);
}
