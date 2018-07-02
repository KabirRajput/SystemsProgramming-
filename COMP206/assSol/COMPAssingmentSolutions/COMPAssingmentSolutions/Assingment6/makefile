ProducerConsumer: main producer consumer
	gcc -o ProducerConsumer Main.o Producer.o Consumer.o

main: Main.c ProducerConsumer.h
	gcc -c Main.c

producer: Producer.c ProducerConsumer.h
	gcc -c Producer.c

consumer: Consumer.c ProducerConsumer.h
	gcc -c Consumer.c

clean:
	rm -rf *.o ProducerConsumer TURN.txt DATA.txt

backup:
	test ! -d backup && mkdir backup
	cp *.c backup
	cp *.h backup

