package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	a := 10
	b := 20

	fmt.Println(max(a, b))
}
