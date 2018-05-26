package main

import "fmt"

type UpdateOp struct {
    Key int
    Value string
}

func applyUpdate(data map[int]string, op UpdateOp) {
    data[op.Key] = op.Value
}

func main() {
    m := make(map[int]string)  // 创建map
    m[2] = "abcdefg"

    ch := make(chan UpdateOp)

    go func(ch chan UpdateOp) {
        // 在协程里面把数据放到队列里面，让另一端消费
        ch <- UpdateOp{2, "New data"}
    }(ch)

    // 消费channel里面的数据
    applyUpdate(m, <-ch)
    fmt.Println(m[2])
}
