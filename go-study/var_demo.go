package main

import "fmt"

var a string = "A"
var b = "B"

// 定义一个bool，默认会是bool
var c bool

func main() {
	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(c)

	d := &a
	fmt.Println(*d)
}
