client_p03_cya: client_p04.cc code_analyzer.cc variable.cc statement.cc comment.cc
	g++ -o client_p04 client_p04.cc code_analyzer.cc variable.cc statement.cc comment.cc

clean:
	rm -r *.txt
