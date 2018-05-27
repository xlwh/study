package main

import (
	"errors"
	"fmt"
)

func throw_exception() {
	panic(errors.New("Unknow error"))
}

func main() {
	// 捕捉异常，并且进行处理
	defer func() {
		// 拦截异常
		if e := recover(); e != nil {
			fmt.Println("Run error")
		}
	}()

	throw_exception()
	fmt.Println("done")
}
