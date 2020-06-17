CC := gcc
CFLAGS := -Wall

SRC = afetch_*.c

a-fetch: ${OBJ}
			 @echo CC -o $@
			 @$(CC) -o ${OBJ}

clean:
			@rm -rf  afetch ${OBJ}

install: afetch
			@echo Installing executable to ${DESTDIR}${PREFIX}/bin
			@mkdir -p ${DESTDIR}${PREFIX}/bin
			@cp -f afetch ${DESTDIR}${PREFIX}/bin
			@chmod 755 ${DESTDIR}${PREFIX}/bin/afetch
			@chmod u+s ${DESTDIR}${PREFIX}/bin/afetch

uninstall:
			@echo Uninstalling executable from  ${DESTDIR}${PREFIX}/bin
			rm -rf  ${DESTDIR}${PREFIX}/bin/afetch