package main

import (
    "fmt"
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

    for i := 0; i < count; i++ {
        r := rand.Uint32()
        fmt.Fprintf(file, "%d\n", r)
    }
}
