package main

import (
    "os"
    "fmt"
)

// 打开文件，返回文件句柄，以便于上层进行文件的操作
func Open(path string) (*os.File, error) {
    fmt.Println("Creating file to write")
    fs, err := os.Create(path)
    if err != nil {
        // 把错误向上层进行抛出
        return nil, err
    }

    return fs, nil
}

// 写入数据
func Write(data string, fd *os.File) {
    fmt.Println("Write data to file")
    fmt.Fprintln(fd, data)
}

// 关闭文件
func Close(fd *os.File) {
    fmt.Println("Close file")
    fd.Close()
}


func main() {
    // 打开文件
    fd, err := Open("./test.data")
    if err != nil {
        fmt.Println("Open file to write error")
        return
    }
    // 文件打开成功，注册一下关闭操作
    defer Close(fd)

    // 写入数据到文件中去
    Write("hello, my name is zhanghongbin01", fd)
}
