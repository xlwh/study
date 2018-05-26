package main

import (
    "fmt"
    "sync"
    "time"
)

func main() {
    var mutex sync.Mutex    // 互斥锁
    fmt.Println("Get lock")
    mutex.Lock()

    fmt.Println("The lock is locked")
    for i := 1; i < 4; i++ {
        go func(i int) {
            fmt.Println("Try to get lock in thread")
            mutex.Lock()
            // 线程里面没有取到锁，不能跑
            fmt.Println("Get lock in thread success")
            mutex.Unlock()
        }(i)
    }

    // 休息一会
    time.Sleep(time.Second)
    fmt.Println("Unlock the lock")
    mutex.Unlock()
    fmt.Println("Unlock success")
}
