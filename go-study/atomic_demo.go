package main

import (
     "sync/atomic"
    "fmt"
    "sync"
)

func main() {
    var sum uint32 = 0
    var wg sync.WaitGroup
    for i := 0; i < 50; i++ {
        // 增加等待的线程的数量 +1
        wg.Add(1)
        go func() {
            // 结束等待线程 -1
            defer wg.Done()
            atomic.AddUint32(&sum, 1)
        }()
    }
    // 等待线程执行完毕
    wg.Wait()
    fmt.Println(sum)
}
