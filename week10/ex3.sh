chmod -R g=u _ex3.txt

touch _ex3.txt
chmod ugo-x _ex3.txt
ls -l | grep _ex3.txt > ex3.txt
chmod uo+rwx _ex3.txt
ls -l | grep _ex3.txt >> ex3.txt
chmod -R g=u _ex3.txt
ls -l | grep _ex3.txt >> ex3.txt

echo 660 = 110110000 = rw-rw---- = owner user can read and write, same for owner group and no permissions for other users >> ex3.txt
echo 775 = 111111101 = wxrwxr-x = owner user and owner group have all permissions, other users have permission to read and execute >> ex3.txt
echo 777 = 111111111 = rwxrwxrwx = owner user, owner group amd other users have all rights >> ex3.txt