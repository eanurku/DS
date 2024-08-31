clean:
	-del -f *.exe
	
all:  test LinkList StackAsArray StackAsLinkList

test: test.cpp
	g++ -std=c++2a -o test test.cpp

LinkList: LinkList.cpp
	g++ -std=c++2a -o LinkList LinkList.cpp

StackAsArray: StackAsArray.cpp
	g++ -std=c++2a -o StackAsArray StackAsArray.cpp

StackAsLinkList: StackAsLinkList.cpp
	g++ -std=c++2a -o StackAsLinkList StackAsLinkList.cpp
