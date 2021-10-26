mkdir -p ../week01
echo Ruslan Gilvanov> ../week01/file.txt
link ../week01/file.txt ../week10/_ex2.txt

find ../ -inum $(ls -li ../week01/file.txt | awk '{print $1}') > ex2.txt
find ../ -inum $(ls -li ../week01/file.txt | awk '{print $1}') -exec rm {} \; >> ex2.txt
