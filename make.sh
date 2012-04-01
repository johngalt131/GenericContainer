
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
for a in $SRC;do
    g++ -O0 -DTIXML_USE_STL -g -c -o ./objs/"$a".o ./src/"$a" $HPATH # $LIBPATH $LIBS 
done
ar -cvq ./lib/libcontainer.a ./objs/*