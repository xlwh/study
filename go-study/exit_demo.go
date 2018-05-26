package main

import (
    "fmt"
    "os"
)

func main() {

    // 使用os.Exit() 不会调用这个defer去进行资源的释放
    // 这个在使用的时候需要关注
    defer fmt.Println("Can not run this")
    fmt.Println("Can show this")

    // 主动退出服务
    os.Exit(0)
}
