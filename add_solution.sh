#!/bin/bash

echo "=== HackerRank Solution Uploader with Description ==="

read -p "Problem Name (e.g., Solve Me First): " pname
read -p "Category (Algorithms/DataStructures/SQL): " category
read -p "Subcategory (e.g., Warmup, Arrays): " subcat
read -p "Language (cpp, py, java, sql): " lang
read -p "HackerRank Problem Link: " link

# Normalize names
dirname=$(echo "$pname" | tr '[:upper:]' '[:lower:]' | tr ' ' '-' | tr -cd '[:alnum:]-')
filename="$dirname.$lang"
dirpath="$category/$subcat/$dirname"

mkdir -p "$dirpath"

# README for question description
readme_file="$dirpath/README.md"
echo "# $pname" > "$readme_file"
echo "" >> "$readme_file"
echo "**Link:** [$link]($link)" >> "$readme_file"
echo "" >> "$readme_file"
echo "### Problem Description" >> "$readme_file"
echo "(Paste the problem description below manually)" >> "$readme_file"
echo "" >> "$readme_file"

# Open README for pasting problem statement
command -v code &> /dev/null && code "$readme_file" || nano "$readme_file"

# Create code file
code_file="$dirpath/$filename"
echo "// Problem: $pname" > "$code_file"
echo "// Link: $link" >> "$code_file"
echo "// Language: $lang" >> "$code_file"
echo "" >> "$code_file"

# Open solution editor
command -v code &> /dev/null && code "$code_file" || nano "$code_file"

read -p "Done writing README & code? (y/n): " confirm
if [[ "$confirm" != "y" ]]; then
  echo "❌ Aborted."
  exit 1
fi

# Add to main README
echo "- [$pname]($link) – \`$dirpath/$filename\`" >> README.md

# Git commit and push
git add .
git commit -m "Added: $pname with description and solution"
git push

echo "✅ Question and solution uploaded to GitHub!"
