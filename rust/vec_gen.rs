import io::writer_util;

fn main(args: [str]) {
    if vec::len(args) != 2u {
        let usage = #fmt("Usage: %s <elem_count>\n", args[0]);
        io::stderr().write_str(usage);
        os::set_exit_status(-1);
        ret;
    }

    let count = option::get(int::from_str(args[1]));
    let rng = rand::seeded_rng(rand::seed());

    let fw = result::get(io::buffered_file_writer("vec_gen.out"));
    let mut i = 0;
    while i < count {
        let r = rng.next() & (0x7fffffffu as u32);
        fw.write_line(int::to_str(r as int, 10u));
        i += 1;
    }
}
