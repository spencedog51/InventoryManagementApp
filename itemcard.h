#ifndef ITEMCARD_H
#define ITEMCARD_H

#include <QLabel>
#include <QMouseEvent>

class ItemCard : public QFrame
{
    Q_OBJECT

public:
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

    explicit ItemCard(
        const QPixmap& image,
        const QString& name,
        const QString& type,
        double weight,
        const QString& sku,
        double price,
        QFrame* parent = nullptr);

    void mousePressEvent(QMouseEvent *event) override;

    // /**
    //  * @brief getItemCard - gets an item card and all its info
    //  * @param isProduct - determines whether this is a product (true)
    //  * or material (false).
    //  * @param itemName - the name of the item to get (TODO: THIS MAY CHANGE TO SKU OR SOMETHING ELSE)
    //  * @return - the entire item card
    //  */
    // ItemCard getItemCard(bool isProduct, QString itemName);

signals:
    void clicked(ItemCard* card);
};

class ProductCard : public ItemCard
{
    //product collection
    QString productCollection;

    //materials used to make (name and quantity)
    QList<std::pair<QString, int>> materialsUsed;

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
        QFrame* parent = nullptr);

signals:
};

class MaterialCard : public ItemCard
{
    Q_OBJECT
public:
    //website purchased from
    QString websiteLink;

    //website's sku
    QString websiteSku;

    //Quantity of material (individual)
    double quantity;

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
        QFrame* parent = nullptr);

signals:
};

#endif // ITEMCARD_H
