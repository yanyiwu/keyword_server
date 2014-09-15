keyword.server: 
	g++ -o keyword.server -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g -I./include -I./include/CppJieba keyword_server.cpp -lpthread
clean: 
	rm -f *.o *.a keyword.server
