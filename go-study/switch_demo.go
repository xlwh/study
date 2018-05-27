package main

import (
	"fmt"
)

func main() {
	var str string = "A"

	switch str {
	case "A":
		fmt.Println("A")
	case "B":
		fmt.Println("B")
	default:
		fmt.Println("No match")
	}
}
