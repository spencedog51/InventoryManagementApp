#ifndef PRODUCTPAGE_H
#define PRODUCTPAGE_H

#include "itemcard.h"

#include <QGridLayout>
#include <QWidget>

class ProductPage : public QWidget
{
    Q_OBJECT
public:
    explicit ProductPage(QWidget *parent = nullptr);

private:
    QGridLayout* productGrid;
    QList<ProductCard*> productCards;

    void PopulateProductGrid();

    void AddNewProduct(ProductCard*);

    void OpenExistingProduct(ProductCard*);

signals:

private slots:
    void openProduct(ItemCard* product);
};

#endif // PRODUCTPAGE_H
