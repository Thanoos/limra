This folder contains lint scripts.

check-doc.py
============
Check for missing documentation of command line options.

commit-script-check.sh
======================
Verification of [scripted diffs](/doc/developer-notes.md#scripted-diffs).

git-subtree-check.sh
====================
Run this script from the root of the repository to verify that a subtree matches the contents of
the commit it claims to have been updated to.

To use, make sure that you have fetched the upstream repository branch in which the subtree is
maintained:
* for `src/secp256k1`: https://github.com/limracoin-core/secp256k1.git (branch master)
* for `src/leveldb`: https://github.com/limracoin-core/leveldb.git (branch limracoin-fork)
* for `src/univalue`: https://github.com/limracoin-core/univalue.git (branch master)
* for `src/crypto/ctaes`: https://github.com/limracoin-core/ctaes.git (branch master)

Usage: `git-subtree-check.sh DIR (COMMIT)`

`COMMIT` may be omitted, in which case `HEAD` is used.

lint-all.sh
===========
Calls other scripts with the `lint-` prefix.