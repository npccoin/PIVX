// Copyright (c) 2017-2018 The NPCcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZNPCCONTROLDIALOG_H
#define ZNPCCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "znpc/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZNpcControlDialog;
}

class CZNpcControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZNpcControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZNpcControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZNpcControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZNpcControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZNpcControlDialog(QWidget *parent);
    ~ZNpcControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZNpcControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZNpcControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZNPCCONTROLDIALOG_H
