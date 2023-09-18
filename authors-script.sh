#!/usr/bin/env bash

# This file extracts author information from the Git history and formats it.

set -e

# First, get the directory where this script is located
SCRIPTDIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Then, determine the root directory of the project using Git
ROOTDIR="$(git -C "$SCRIPTDIR" rev-parse --show-toplevel)"

set -x

# Can use Git log to extract author information
cat > "${ROOTDIR}/AUTHORS" <<- EOF
# @Generated by generate-authors.sh. DO NOT EDIT.
# Lists all the contributors of this project.

$(git -C "$ROOTDIR" log --format='%aN <%aE>' | LC_ALL=C.UTF-8 sort -uf)
EOF
