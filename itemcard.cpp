#include "itemcard.h"

#include <QVBoxLayout>

ItemCard::ItemCard(
    const QPixmap& image,
    const QString& name,
    const QString& type,
    double weight,
    const QString& sku,
    double price,
    QWidget* parent)
    : QWidget(parent),
    image(image),
    name(name),
    type(type),
    weight(weight),
    personalSku(sku),
    price(price)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    nameLabel = new QLabel(this);
    layout->addWidget(nameLabel);
}

ProductCard::ProductCard(
    const QPixmap& image,
    const QString& name,
    const QString& type,
    double weight,
    const QString& sku,
    double price,
    const QString& collection,
    const QList<std::pair<QString, int>>& materialsUsed,
    QWidget* parent)
    : ItemCard(image, name, type, weight, sku, price, parent),
    itemCollection(collection),
    materialsUsed(materialsUsed)
{
    nameLabel->setText(name);
}

MaterialCard::MaterialCard(
    const QPixmap& image,
    const QString& name,
    const QString& type,
    double weight,
    const QString& sku,
    double price,
    const QString& webLink,
    const QString& webSku,
    double quantity,
    QWidget* parent)
    : ItemCard(image, name, type, weight, sku, price, parent),
    websiteLink(webLink),
    websiteSku(webSku),
    quantity(quantity)
{
    nameLabel->setText(name);
}
