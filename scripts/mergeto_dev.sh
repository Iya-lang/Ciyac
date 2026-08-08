#!/bin/bash

echo "This script may only work on linux"
echo "Merging to main...."
git switch development

for file in $(git ls-tree -r minimalist --name-only | grep -E '\.(c|h)$'); do
    base_name=$(basename "$file")
    target_path=$(find src include -name "$base_name" 2>/dev/null)
    if [ ! -z "$target_path" ]; then
        git show "minimalist:$file" > "$target_path"
    fi
done

git switch minimalist