//#ifndef TILETABLEMODEL_H
//#define TILETABLEMODEL_H

//#include <QAbstractTableModel>
//#include <QVector>

//struct TileData {
//    int color;
//    int type;
//};

//class TileTableModel : public QAbstractTableModel
//{
//    Q_OBJECT

//public:
//    explicit TileTableModel(QObject *parent = nullptr);

//    enum {
//        ColorRole = Qt::UserRole,
//        TypeRole,
//    };

//    void setSize(int, int);
//    std::string toString();
//    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
//    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
//    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
//    QHash<int, QByteArray> roleNames() const override;
//    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
//    Qt::ItemFlags flags(const QModelIndex &index) const override;

//    void append(TileData tile, int col, int row);
//    void remove(int col, int row);

//signals:
//    void tileAdded();
//    void tileRemoved();

//private:
//    QVector<TileData> m_tiles;
//    int m_cols;
//    int m_rows;
//};

//#endif // TILETABLEMODEL_H
