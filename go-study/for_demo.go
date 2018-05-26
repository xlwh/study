package main

import "fmt"

func main() {
	var i int = 20
	for c := 0; c < i; c++ {
		fmt.Println(c)
	}

	// 这种形式的写法，可以代替while使用
	var j = 0
	for j < 100 {
		fmt.Println(j)
		j++
	}
}
