if (Array.length Sys.argv) <> 2 then (
  let msg = "Usage: " ^ (Array.get Sys.argv 0) ^ " <elem_count>\n" in
  prerr_string msg;
  exit (-1)
) else (
  let count = int_of_string (Array.get Sys.argv 1) in
  let file = open_out "vec_gen.out" in
  let rec write_rand_line n =
    if n = 0 then ()
    else
      let r = Random.bits () in
      output_string file ((string_of_int r) ^ "\n");
      write_rand_line (n - 1)
  in
  write_rand_line count;
  exit 0
)
