
LIBPATH="\

"
HPATH="\
-I./include/ \
-I./i_include/ \
"
LIBS="\

"
SRC="\
container.cpp
"
#Filters.cpp
MAIN="main"
rm -v ./lib/*
for a in $SRC;do
    g++ -O0  -DTIXML_USE_STL -g -c -o ./objs/"$a".o ./src/"$a" $HPATH # $LIBPATH $LIBS 
done
ar -cvq ./lib/libcontainer.a ./objs/*
g++ -O0 -g -o test ./src/test.cpp -I./i_include/ -L./lib/ -lcontainer