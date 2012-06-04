// Optimizations suggested by kjk, see http://blog.cdleary.com/2012/06/simple-selfish-and-unscientific-shootout/#comment-546669602

package main

import (
    "bufio"
    "fmt"
    "log"
    "math/rand"
    "os"
    "strconv"
)

func main() {
    if len(os.Args) != 2 {
        fmt.Fprintf(os.Stderr, "usage: %s <elem_count>\n", os.Args[0])
        os.Exit(-1)
    }

    count, err := strconv.Atoi(os.Args[1])
    if err != nil { panic(err) }

    file, err := os.Create("vec_gen.out")
    if err != nil { panic(err) }
    defer file.Close()

    bw := bufio.NewWriterSize(file, 1024*16)
    defer func() {
        err := bw.Flush()
        if err != nil { log.Fatal(err) }
    }()

    var scratch [128]byte
    for i := 0; i < count; i++ {
        b := strconv.AppendUint(scratch[:0], uint64(rand.Uint32()), 10)
        b2 := append(b, 10)
        if _, err := bw.Write(b2); err != nil { panic(err) }
    }
}
