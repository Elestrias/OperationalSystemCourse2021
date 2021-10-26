mkdir ../week01
echo Ruslan Gilvanov> ../week01/file.txt
link ../week01/file.txt ../week10/_ex2.txt
find ../ -inum $ls -i ../week01/file.txt
