clean:
	-del -f *.exe
	
all:  test ArrayReverse LinkList GenericLinkList

test: test.cpp
	g++ -std=c++2a -o test test.cpp

ArrayReverse: ArrayReverse.cpp
	g++ -std=c++2a -o ArrayReverse ArrayReverse.cpp

LinkList: LinkList.cpp
	g++ -std=c++2a -o LinkList LinkList.cpp

GenericLinkList: GenericLinkList.cpp
	g++ -std=c++2a -o GenericLinkList GenericLinkList.cpp