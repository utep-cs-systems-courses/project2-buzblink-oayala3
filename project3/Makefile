all:

	(cd timerLib; make install)

	(cd lcdLib; make install)


doc:

	rm -rf doxygen_docs

	doxygen Doxyfile

clean:

	(cd timerLib; make clean)

	(cd lcdLib; make clean)

	rm -rf lib h

	rm -rf doxygen_docs/*
