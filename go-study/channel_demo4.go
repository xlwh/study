package main

import (
    "fmt"
)

func f(n int, c chan int) {
    x, y := 1, 1

    // 往channel里面写入n条数据
    for i := 0; i < n; i++ {
        c <- x
        x, y = y, x + y
    }

    close(c)
}

func main() {
    c := make(chan int, 10)
    go f(cap(c), c)

    // 取出所有的消息
    for i := range c {
        fmt.Println(i)
    }
}
