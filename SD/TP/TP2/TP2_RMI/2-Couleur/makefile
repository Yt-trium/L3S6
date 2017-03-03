all: serveur client

client: clean
	javac Client.java
serveur: clean
	javac Serveur.java

test:
	java Serveur 1234

testc:
	java Client localhost 1234

clean:
	rm *.class
