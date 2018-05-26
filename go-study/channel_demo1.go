package main

import "fmt"

func main() {
	c := make(chan int, 2)
	// 只往里面塞，不取出
	c <- 1
	c <- 2

	//依次取出里面的数据
	fmt.Println(<-c)
	fmt.Println(<-c)
}
