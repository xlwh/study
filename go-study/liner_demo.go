package main

import (
    "fmt"
    "github.com/peterh/liner"
)

func main() {
    liner = liner.NewLiner()
    defer liner.Close()

    fmt.Println("Open success")
}
