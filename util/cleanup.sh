#!/usr/bin/env bash
set -euo pipefail

cd "$(git rev-parse --show-toplevel)"

# 1. Clear everything in the trash folder
if [ -d trash ]; then
    find trash -mindepth 1 -delete
    echo "Cleared trash/"
fi

# 2. Move all .cpp files from the root into Contests/
mkdir -p Contests
shopt -s nullglob
cpp_files=(*.cpp)
if [ ${#cpp_files[@]} -gt 0 ]; then
    mv -v "${cpp_files[@]}" Contests/
else
    echo "No .cpp files in root to move"
fi
shopt -u nullglob

# 3. git add, commit, push
git add -A
if git diff --cached --quiet; then
    echo "Nothing to commit"
else
    git commit -m "Clean up trash and move .cpp files to Contests"
    git push
fi
