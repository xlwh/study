package main

import "fmt"

func main() {
	var a int = 100
	var b, ok = interface{}(a).(int)
	if !ok {
		fmt.Println("assert error")
		return
	}
	fmt.Println(b)
}
