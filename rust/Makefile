.PHONY: all
all:
	rustc -o vec_gen_rust_opt.exe --opt-level 3 vec_gen_opt.rs
	time ./vec_gen_rust_opt.exe 100000000
