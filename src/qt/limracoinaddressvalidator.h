// Copyright (c) 2011-2014 The Limracoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef LIMRACOIN_QT_LIMRACOINADDRESSVALIDATOR_H
#define LIMRACOIN_QT_LIMRACOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class LimracoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit LimracoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Limracoin address widget validator, checks for a valid limracoin address.
 */
class LimracoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit LimracoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // LIMRACOIN_QT_LIMRACOINADDRESSVALIDATOR_H
