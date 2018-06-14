package main

import (
    "github.com/syndtr/goleveldb/leveldb"
    "fmt"
)

func main() {
    // 先打开db
    db, err := leveldb.OpenFile("./db", nil)
    if err != nil {
        fmt.Println("Open db error:", err)
        return
    }

    // 关闭和释放资源，一定要记得写这个
    defer db.Close()
    err = db.Put([]byte("name"), []byte("zhanghongbin01"), nil)
    if err != nil {
        fmt.Println("Put data error:", err)
        return
    }

    data, err := db.Get([]byte("name"), nil)
    if err != nil {
        fmt.Println("Get key error:", err)
        return
    }
    fmt.Println("Get key success:", string(data))

    //删除key
    /* err = db.Delete([]byte("name"), nil)
    if err != nil {
        fmt.Println("Delete data error:", err)
        return
    } */
}
