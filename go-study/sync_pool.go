package main

import (
    "fmt"
    "sync"
)

func main() {
    p := &sync.Pool {
        New: func() interface{} {
            return 0;
        },
    }

    // 尝试去pool里面取出一个对象，这个时候是没有的
    a := p.Get().(int)
    // 往pool里面放入一个对象
    p.Put(1)
    b := p.Get().(int)
    fmt.Println(a, b)
}
