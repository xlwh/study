package main

import (
    "fmt"
    "github.com/syndtr/goleveldb/leveldb/util"
)

func main() {
    str := "hello"
    buf := util.NewBuffer([]byte(str))

    fmt.Println("Allocate buffer success, size is:", buf.String())

    // 进行数据的Truncate
    buf.Truncate(1)
    fmt.Println("Truncate result:", buf.String())
    fmt.Println("Len:", buf.Len())
}
