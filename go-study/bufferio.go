package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Please input your name:")
	input, err := reader.ReadString('\n')
	if err != nil {
		fmt.Println("Get input error")
		return
	}
	input = input[:len(input)-1]
	fmt.Println("*********************")
	fmt.Println(string(input))
}
