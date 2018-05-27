package main

import (
	"fmt"
	"os"
)

func main() {
	reader, writer, err := os.Pipe()
	if err != nil {
		fmt.Println("Open pipe error")
		return
	}

}
