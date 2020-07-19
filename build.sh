#sudo cp -rf *so* /usr/lib
#g++ -c lyp.cc -I/usr/local/include/Poco/ -lPocoJSON -lPocoUtil  -lPocoXML -lPocoNet  -lPocoFoundation  -lcrypto -lssl -lpthread -lrt -ldl
#g++ -c parser.cc -I/usr/local/include/Poco/ -lPocoJSON -lPocoUtil  -lPocoXML -lPocoNet  -lPocoFoundation -lcrypto -lssl -lpthread -lrt -ldl


g++ -o main rest.cc parser.cc -I/usr/local/include/Poco/ -lPocoJSON -lPocoUtil  -lPocoXML -lPocoNet  -lPocoFoundation -lcrypto -lssl -lpthread -lrt -ldl

#g++ -o test parser.o
