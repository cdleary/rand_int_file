.PHONY: all
all:
	ocamlopt -unsafe -o vec_gen_ml.exe vec_gen.ml
	time ./vec_gen_ml.exe 100000000

.PHONY: clean
clean:
	rm -f *.cm?
	rm -f *.o
	rm -f *.out
	rm -f *.exe
