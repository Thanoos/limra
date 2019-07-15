// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Limracoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef LIMRACOIN_SCRIPT_LIMRACOINCONSENSUS_H
#define LIMRACOIN_SCRIPT_LIMRACOINCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_LIMRACOIN_INTERNAL) && defined(HAVE_CONFIG_H)
#include <config/limracoin-config.h>
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBLIMRACOINCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define LIMRACOINCONSENSUS_API_VER 1

typedef enum limracoinconsensus_error_t
{
    limracoinconsensus_ERR_OK = 0,
    limracoinconsensus_ERR_TX_INDEX,
    limracoinconsensus_ERR_TX_SIZE_MISMATCH,
    limracoinconsensus_ERR_TX_DESERIALIZE,
    limracoinconsensus_ERR_AMOUNT_REQUIRED,
    limracoinconsensus_ERR_INVALID_FLAGS,
} limracoinconsensus_error;

/** Script verification flags */
enum
{
    limracoinconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    limracoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    limracoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    limracoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    limracoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    limracoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    limracoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    limracoinconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = limracoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH | limracoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               limracoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | limracoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               limracoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | limracoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int limracoinconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, limracoinconsensus_error* err);

EXPORT_SYMBOL int limracoinconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, limracoinconsensus_error* err);

EXPORT_SYMBOL unsigned int limracoinconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // LIMRACOIN_SCRIPT_LIMRACOINCONSENSUS_H
