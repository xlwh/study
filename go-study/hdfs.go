package main

import (
    "github.com/vladimirvivien/gowfs"
    "fmt"
)

func main() {
    fs, err := gowfs.NewFileSystem(gowfs.Configuration{Addr: "localhost:5070", User: "zhanghongbin01"})
    if err != nil {
        fmt.Println("error:", err)
        return
    }
    // 读取文件的checksum
    checksum, err := fs.GetFileChecksum(gowfs.Path{Name: "/user/zhanghongbin01/input/test.txt"})
    if err != nil {
        fmt.Println("get status error")
        return
    }
    fmt.Println(checksum)
    // 创建文件夹
    createDir(fs, "/user/zhanghongbin01/test")

    // 测试服务连接
    testConn(fs)
}

func testConn(fs *gowfs.FileSystem) {
    _, err := fs.ListStatus(gowfs.Path{Name: "/"})
    if err != nil {
        fmt.Println("Unable to connection server")
        return
    }
    fmt.Println("Conn server success:", fs.Config.Addr)
}

func createDir(fs *gowfs.FileSystem, p string) {
    path := gowfs.Path{Name: p}
    ok, err := fs.MkDirs(path, 0755)
    if err != nil || !ok {
        fmt.Println("Create dir error")
        return
    }
    fmt.Println ("HDFS Path ", path.Name, " created.")
}
