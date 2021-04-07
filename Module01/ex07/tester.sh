#!/bin/bash

make

### Testing error cases ###
echo "=== Error cases ==="
./replace ./files/test.txt
./replace ./files/test.txt "" Bla
./replace ./files/test.txt fichier ""
./replace i_dont_exist Quentin Julien
./replace ./files/unauth.txt lecture Bla


### Tests that should work ###
echo "=== Legit tests ==="
echo "--> Check \".replace\" files in files directory"
./replace ./files/test.txt Quentin Julien
./replace ./files/empty.txt hello hey
./replace ./files/ipsum.txt e z
./replace ./files/ipsum.txt.replace z e
./replace ./files/alphabet.txt abcdefghijklmnopqrstuvwxyz ":)"
