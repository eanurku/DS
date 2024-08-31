clean:
	-del -f *.exe
	
all:  test Array LinkList GenericLinkList

test: test.cpp
	g++ -std=c++2a -o test test.cpp

Array: Array.cpp
	g++ -std=c++2a -o Array Array.cpp

LinkList: LinkList.cpp
	g++ -std=c++2a -o LinkList LinkList.cpp

GenericLinkList: GenericLinkList.cpp
	g++ -std=c++2a -o GenericLinkList GenericLinkList.cpp