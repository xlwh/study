package main

import (
	"fmt"
)

func swap(a, b string) (string, string) {
	return b, a
}

func main() {
	var a string = "A"
	var b string = "B"

	fmt.Println(swap(a, b))
}
