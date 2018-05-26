package main

import (
	"fmt"
)

func sum(a []int, c chan int) {
	total := 0

	for _, v := range a {
		total += v
	}

	// 把计算结果通过管道发送出来
	c <- total
}

func main() {
	a := []int{7, 2, 8, -9, 4, 0}

	c := make(chan int, 1)
	go sum(a[:len(a)/2], c)
	go sum(a[len(a)/2:], c)

	x, y := <-c, <-c //接收数据

	fmt.Println(x, y, x+y)
}
