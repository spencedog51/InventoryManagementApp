#ifndef ITEMCARD_H
#define ITEMCARD_H

#include <QWidget>
#include <Qlabel>

class ItemCard : public QWidget
{
    Q_OBJECT


protected:
    explicit ItemCard(
        const QPixmap& image,
        const QString& name,
        const QString& type,
        double weight,
        const QString& sku,
        double price,
        QWidget* parent = nullptr);

    //Picture of product/material
    QPixmap image;

    //item name
    QString name;

    //label to display name
    QLabel* nameLabel;

    //item type (bracelet, necklace, etc for product; wire, bead, etc for material)
    QString type;

    //item weight (ounces)
    double weight;

    //personal sku (letters and numbers)
    QString personalSku;

    //price (sell price for products, buy price for materials)
    double price;

signals:
};

class ProductCard : public ItemCard
{
    Q_OBJECT
public:
    explicit ProductCard(
        const QPixmap& image = QPixmap(),
        const QString& name = "",
        const QString& type = "",
        double weight = 0,
        const QString& sku = "",
        double price = 0,
        const QString& collection = "",
        const QList<std::pair<QString, int>>& materialsUsed = {},
        QWidget* parent = nullptr);

    //item collection (none if material)
    QString itemCollection;

    //materials used to make (name and quantity)
    QList<std::pair<QString, int>> materialsUsed;

signals:
};

class MaterialCard : public ItemCard
{
    Q_OBJECT
public:
    explicit MaterialCard(
        const QPixmap& image = QPixmap(),
        const QString& name = "",
        const QString& type = "",
        double weight = 0,
        const QString& sku = "",
        double price = 0,
        const QString& webLink = "",
        const QString& webSku = "",
        double quantity = 0,
        QWidget* parent = nullptr);

    //website purchased from
    QString websiteLink;

    //website's sku
    QString websiteSku;

    //Quantity of material (individual)
    double quantity;

signals:
};

#endif // ITEMCARD_H
