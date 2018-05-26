package main

import "fmt"
import "runtime"

func say() {
    fmt.Println("hello")
    runtime.Gosched()
}

func main() {
    go say()
    say()
}
